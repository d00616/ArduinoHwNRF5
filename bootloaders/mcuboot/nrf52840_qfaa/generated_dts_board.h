/**************************************************
 * Generated include file for nordic,pca10056-dk
 *               DO NOT MODIFY
 */

#ifndef _DEVICE_TREE_BOARD_H
#define _DEVICE_TREE_BOARD_H

/* flash@0 */
#define CONFIG_FLASH_BASE_ADDRESS_0	0x0
#define CONFIG_FLASH_LOAD_OFFSET	0
#define CONFIG_FLASH_LOAD_SIZE		0
#define CONFIG_FLASH_SIZE_0		512
#define FLASH_WRITE_BLOCK_SIZE		4
#define CONFIG_FLASH_BASE_ADDRESS	CONFIG_FLASH_BASE_ADDRESS_0
#define CONFIG_FLASH_SIZE		CONFIG_FLASH_SIZE_0

/* partition@0 */
#define FLASH_AREA_MCUBOOT_LABEL	"mcuboot"
#define FLASH_AREA_MCUBOOT_OFFSET_0	0x0
#define FLASH_AREA_MCUBOOT_SIZE_0	49152
#define FLASH_AREA_MCUBOOT_OFFSET	FLASH_AREA_MCUBOOT_OFFSET_0
#define FLASH_AREA_MCUBOOT_SIZE		FLASH_AREA_MCUBOOT_SIZE_0

/* partition@75000 */
#define FLASH_AREA_IMAGE_1_LABEL	"image-1"
#define FLASH_AREA_IMAGE_1_OFFSET_0	0x75000
#define FLASH_AREA_IMAGE_1_SIZE_0	430080
#define FLASH_AREA_IMAGE_1_OFFSET	FLASH_AREA_IMAGE_1_OFFSET_0
#define FLASH_AREA_IMAGE_1_SIZE		FLASH_AREA_IMAGE_1_SIZE_0

/* partition@c000 */
#define FLASH_AREA_IMAGE_0_LABEL	"image-0"
#define FLASH_AREA_IMAGE_0_OFFSET_0	0xc000
#define FLASH_AREA_IMAGE_0_SIZE_0	430080
#define FLASH_AREA_IMAGE_0_OFFSET	FLASH_AREA_IMAGE_0_OFFSET_0
#define FLASH_AREA_IMAGE_0_SIZE		FLASH_AREA_IMAGE_0_SIZE_0

/* partition@de000 */
#define FLASH_AREA_IMAGE_SCRATCH_LABEL		"image-scratch"
#define FLASH_AREA_IMAGE_SCRATCH_OFFSET_0	0xde000
#define FLASH_AREA_IMAGE_SCRATCH_SIZE_0		122880
#define FLASH_AREA_IMAGE_SCRATCH_OFFSET		FLASH_AREA_IMAGE_SCRATCH_OFFSET_0
#define FLASH_AREA_IMAGE_SCRATCH_SIZE		FLASH_AREA_IMAGE_SCRATCH_SIZE_0

/* memory@20000000 */
#define CONFIG_SRAM_BASE_ADDRESS_0	0x20000000
#define CONFIG_SRAM_SIZE_0		64
#define CONFIG_SRAM_BASE_ADDRESS	CONFIG_SRAM_BASE_ADDRESS_0
#define CONFIG_SRAM_SIZE		CONFIG_SRAM_SIZE_0

/* interrupt-controller@e000e100 */
#define ARM_V7M_NVIC_E000E100_ARM_NUM_IRQ_PRIORITY_BITS		3
#define ARM_V7M_NVIC_E000E100_BASE_ADDRESS_0			0xe000e100
#define ARM_V7M_NVIC_E000E100_SIZE_0				3072
#define ARM_V7M_NVIC_E000E100_BASE_ADDRESS			ARM_V7M_NVIC_E000E100_BASE_ADDRESS_0
#define ARM_V7M_NVIC_E000E100_SIZE				ARM_V7M_NVIC_E000E100_SIZE_0

/* uart@40002000 */
#define CONFIG_UART_CONSOLE_ON_DEV_NAME			"UART_0"
#define NORDIC_NRF_UART_40002000_BASE_ADDRESS_0		0x40002000
#define NORDIC_NRF_UART_40002000_CURRENT_SPEED		115200
#define NORDIC_NRF_UART_40002000_IRQ_0			2
#define NORDIC_NRF_UART_40002000_IRQ_0_PRIORITY		1
#define NORDIC_NRF_UART_40002000_LABEL			"UART_0"
#define NORDIC_NRF_UART_40002000_SIZE_0			4096
#define NORDIC_NRF_UART_40002000_BASE_ADDRESS		NORDIC_NRF_UART_40002000_BASE_ADDRESS_0
#define NORDIC_NRF_UART_40002000_SIZE			NORDIC_NRF_UART_40002000_SIZE_0


/* Following definitions fixup the generated include */
#define CONFIG_NUM_IRQ_PRIO_BITS	ARM_V7M_NVIC_E000E100_ARM_NUM_IRQ_PRIORITY_BITS
#define CONFIG_UART_NRF5_IRQ_PRI	NORDIC_NRF_UART_40002000_IRQ_0_PRIORITY
#define CONFIG_UART_NRF5_BAUD_RATE	NORDIC_NRF_UART_40002000_CURRENT_SPEED
#define CONFIG_UART_NRF5_NAME		NORDIC_NRF_UART_40002000_LABEL


/*
 * The following fields are added for the MySensors ArduinoHwNRF5 variant.
 */
#define MCUBOOT_BOOTUTIL_KEY_CNT	(FLASH_AREA_MCUBOOT_SIZE_0-sizeof(uint32_t))
#define MCUBOOT_BOOTUTIL_KEYS	(FLASH_AREA_MCUBOOT_SIZE_0-(sizeof(uint32_t)<<1))

#endif
