#!/bin/bash
set -e

# Configuration
###############
ZEPHYR_REPO="https://github.com/zephyrproject-rtos/zephyr.git"
ZEPHYR_SDK="https://github.com/zephyrproject-rtos/meta-zephyr-sdk/releases/download/0.9.2/zephyr-sdk-0.9.2-setup.run"
MCUBOOT_REPO="https://github.com/runtimeco/mcuboot"
BUILD_DIR="build"

# Change to script directory
############################
cd $(dirname "$0")
SRC_DIR="$(pwd)"

# Prepare build directory
#########################
test -e "$BUILD_DIR" || mkdir "$BUILD_DIR"
cd "$BUILD_DIR"
DST_DIR="$(pwd)"

# Calculate variables
#####################
MCUBOOT_DIR="$DST_DIR/mcuboot"
ZEPHYR_SDK_INSTALLER="$(basename "$ZEPHYR_SDK")"
BOARD_LIST="$(ls "$SRC_DIR/zephyr_src/boards/arm")"

# Prepare Zephyr SDK
####################
if [ -z "$ZEPHYR_SDK_INSTALL_DIR" ]; then
	# Calculate zephyr SDK install dir
	ZEPHYR_SDK_INSTALL_DIR="$DST_DIR/zephyr-sdk"
	# Download SDK
	test -e "$ZEPHYR_SDK_INSTALLER" || curl -L "$ZEPHYR_SDK" -o "$ZEPHYR_SDK_INSTALLER" -C -
	# Install SDK
	if [ ! -e "$ZEPHYR_SDK_INSTALL_DIR" ]; then
		yes | sh "$ZEPHYR_SDK_INSTALLER" --confirm --nox11 -- -y -d "$ZEPHYR_SDK_INSTALL_DIR"
	fi
fi

# Prepare Zephyr
################
if [ -z "$ZEPHYR_BASE" ]; then
	# Calculate zephyt dir
	ZEPHYR_BASE="$DST_DIR/zephyr"
	test -e "$ZEPHYR_BASE" || git clone "$ZEPHYR_REPO" "$ZEPHYR_BASE"
	cd "$ZEPHYR_BASE" && git pull
fi

# Prepare mcuboot
#################
if [ ! -e "$MCUBOOT_DIR" ]; then
	git clone "$MCUBOOT_REPO" "$MCUBOOT_DIR"
else
	cd "$MCUBOOT_DIR"
	# Reset keys.c to default
	git checkout boot/zephyr/keys.c
	# Pull updates
	git pull
fi

# Prepare env
#############
export ZEPHYR_GCC_VARIANT=zephyr
export ZEPHYR_SDK_INSTALL_DIR
. "$ZEPHYR_BASE/zephyr-env.sh"

# Prepare boards
################
cd "$ZEPHYR_BASE"
cp -rv "$SRC_DIR/zephyr_src/." .

# Prepare an uniqe key
######################
keyfile="$SRC_DIR/root-ec-p256.pem"

# create new key, if file was removed
if [ ! -e "$keyfile" ]; then
	# Generate key
	"$MCUBOOT_DIR/scripts/imgtool.py" keygen -t ecdsa-p256 -k "$keyfile"
fi

# Generate keys.c
cat >"$MCUBOOT_DIR/boot/zephyr/keys.c" <<EOF
// Generated for MySensors ArduinoHwNRF5
#include <bootutil/sign_key.h>

$("$MCUBOOT_DIR/scripts/imgtool.py" getpub -l c -k "$keyfile")

const struct bootutil_key bootutil_keys[] = {
  {
	.key = ecdsa_pub_key,
	.len = &ecdsa_pub_key_len,
  },
  // Add some space for up to three additional keys
  {
	.key = (uint8_t *)0,
	.len = (unsigned int *)0,
  },
  {
	.key = (uint8_t *)0,
	.len = (unsigned int *)0,
  },
  {
	.key = (uint8_t *)0,
	.len = (unsigned int *)0,
  }
};
const int bootutil_key_cnt = 1;
EOF

# Compile bootloaders
#####################
cd "$MCUBOOT_DIR/boot/zephyr/"
for board in $BOARD_LIST; do
	echo "Compile: $board"
	# Compile bootloader
	dir="$MCUBOOT_DIR/boot/zephyr/build_$board"
	test -e "$dir" || mkdir "$dir"
	cd "$dir"
	/opt/cmake/bin/cmake -DBOARD="$board" -DCONF_SIGNATURE_TYPE=ECDSA_P256 -DCONF_VALIDATE_SLOT0=YES ..
	make

	# Copy bootloader
	dst="$SRC_DIR/$( echo "$board" | sed 's/^mys_//')"
	test -e "$dst" || mkdir "$dst"
	cp "zephyr/zephyr.bin" "$dst/bootloader.bin"
	chmod 644 "$dst/bootloader.bin"

	# Prepare none bootloader dir
	none_dst="$SRC_DIR/../none/$( echo "$board" | sed 's/^mys_//')"
	test -e "$none_dst" || mkdir "$none_dst"

	# Copy memory layout
	cp "zephyr/include/generated/generated_dts_board.h" "$dst/generated_dts_board.h"

	# Load DTS in shell
	. "zephyr/include/generated/generated_dts_board.conf"

	# extract addresses of "root_pub_der" and "root_pub_der_len"
	sed -i 's/^#endif//' "$dst/generated_dts_board.h"
	cat >>"$dst/generated_dts_board.h" <<EOF
/*
 * The following fields are added for the MySensors ArduinoHwNRF5 variant.
 */
#define MCUBOOT_BOOTUTIL_KEY_CNT	(FLASH_AREA_MCUBOOT_SIZE_0-sizeof(uint32_t))
#define MCUBOOT_BOOTUTIL_KEYS	(FLASH_AREA_MCUBOOT_SIZE_0-(sizeof(uint32_t)<<1))

#endif
EOF
	
	# Store to generate pointers at the end of the bootloader area
	readelf -s "zephyr/zephyr.elf" |  awk '/bootutil_keys/{print "#define TMP_MCUBOOT_"toupper($8)"\t0x"$2}' >>"$dst/write_data.h"
	readelf -s "zephyr/zephyr.elf" |  awk '/bootutil_key_cnt/{print "#define TMP_MCUBOOT_"toupper($8)"\t0x"$2}' >>"$dst/write_data.h"

	# Add key information to the end of the bootloader
	# Give WRONG results on big endian systems!
	cat >"$dst/write_data.c" <<EOF
#include "generated_dts_board.h"
#include "write_data.h"
#include <stdio.h>
#include <stdint.h>

#define BOOT_HEADER_LEN 0x200

void main() {
	FILE *fp;
	char buffer[32768];
	char ldtemplate[] = "/* Linker script to configure memory regions. */\nSEARCH_DIR(.)\nGROUP(-lgcc -lc -lnosys)\n\nMEMORY\n{\n        FLASH (rx) : ORIGIN = 0x%08x, LENGTH = 0x%x\n        RAM (rwx) :  ORIGIN = 0x%08x, LENGTH = 0x%x\n}\nINCLUDE \"nrf5x_common.ld\"\n";
	uint8_t data[FLASH_AREA_MCUBOOT_SIZE_0] = {0xff};

	// Read file
	fp = fopen("$dst/bootloader.bin", "r");
	fread(&data, 1, FLASH_AREA_MCUBOOT_SIZE_0, fp);
	fclose(fp);

	// Put MCUBOOT_BOOTUTIL_KEY_CNT and MCUBOOT_BOOTUTIL_KEYS at the end
	*((uint32_t*)&data[MCUBOOT_BOOTUTIL_KEY_CNT]) = TMP_MCUBOOT_BOOTUTIL_KEY_CNT;
	*((uint32_t*)&data[MCUBOOT_BOOTUTIL_KEYS]) = TMP_MCUBOOT_BOOTUTIL_KEYS;

	// Write file
	fp = fopen("$dst/bootloader.bin", "w");
	fwrite(&data, 1, FLASH_AREA_MCUBOOT_SIZE_0, fp);
	fclose(fp);

	// Write linker scripts
	fp = fopen("$dst/MyBoardNRF5.ld", "w");
	sprintf(buffer, ldtemplate , FLASH_AREA_IMAGE_0_OFFSET_0+BOOT_HEADER_LEN, FLASH_AREA_IMAGE_0_SIZE_0-BOOT_HEADER_LEN, CONFIG_SRAM_BASE_ADDRESS_0, CONFIG_SRAM_SIZE_0*1024);
	fputs(buffer, fp);
	fclose(fp);

	fp = fopen("$dst/../../none/$(basename "$dst")/MyBoardNRF5.ld", "w");
	sprintf(buffer, ldtemplate , CONFIG_FLASH_BASE_ADDRESS_0, CONFIG_FLASH_SIZE_0*1024, CONFIG_SRAM_BASE_ADDRESS_0+4096, (CONFIG_SRAM_SIZE_0*1024)-8192);
	fputs(buffer, fp);
	fclose(fp);
}
EOF
	gcc "$dst/write_data.c" -o "$dst/write_data"
	"$dst/write_data"
	rm "$dst/write_data.c" "$dst/write_data.h" "$dst/write_data"
done
