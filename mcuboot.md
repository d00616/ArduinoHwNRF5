# mcuboot for MySensors

## building bootloader (mynewt)

https://mynewt.apache.org/latest/os/get_started/native_install_intro/


cd mcuboot
newt install

newt target create rbnano2_boot
newt target set rbnano2_boot bsp=@apache-mynewt-core/hw/bsp/rb-nano2
newt target set rbnano2_boot build_profile=optimized
newt target set rbnano2_boot app=@mcuboot/apps/blinky

newt create-image rbnano2_boot 1.0.0 

## build zephyr

http://docs.zephyrproject.org/getting_started/getting_started.html#building-and-running-an-application
+ python3-elftools pyocd-flashtool python3-ecdsa


https://github.com/zephyrproject-rtos/meta-zephyr-sdk/releases/
git clone https://github.com/zephyrproject-rtos/zephyr.git

export ZEPHYR_GCC_VARIANT=zephyr
export ZEPHYR_SDK_INSTALL_DIR=<sdk installation directory>
source <zepyhr>/zephyr.sh

cd  mcuboot/boot/zephyr/
mkdir build_nrf52
cd build_nrf52
/opt/cmake/bin/cmake -DBOARD=nrf52_blenano2 -DCONF_SIGNATURE_TYPE=ECDSA_P256 -DCONF_VALIDATE_SLOT0=YES ..
make

/home/frank/.arduino15/packages/sandeepmistry/tools/openocd/0.10.0-dev.nrf5/bin/openocd -d2 -f "interface/cmsis-dap.cfg" -c "transport select swd;" -f "target/nrf52.cfg" -c "program {{${file}}} verify reset; shutdown;"

Adresses:
samples/zephyr/build/nrf52_blenano2/hello1/zephyr/nrf52_blenano2.dts_compiled


## Python-Env

pyyaml
pyelftools

## own board

keep 32k/16k free at the top of flash
Enable serial only, for custom layout



./imgtool.py sign -k ../../../root-ec-p256.pem -H 0x200 --align 8 --version 1.2 --pad 0x30000 /tmp/arduino_build_395762/DimmableLEDActuator_test.ino.bin /tmp/DimmableLEDActuator_test.ino-1.2.bin
"/home/frank/.arduino15/packages/sandeepmistry/tools/gcc-arm-none-eabi/5_2-2015q4/bin/arm-none-eabi-objcopy" -I binary -O ihex /tmp/DimmableLEDActuator_test.ino-1.2.bin /tmp/DimmableLEDActuator_test.ino-1.2.hex
