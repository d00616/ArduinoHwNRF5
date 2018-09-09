/* Linker script to configure memory regions. */
SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
        FLASH (rx) : ORIGIN = 0x0000c200, LENGTH = 0x68e00
        RAM (rwx) :  ORIGIN = 0x20000000, LENGTH = 0x10000
}
INCLUDE "nrf5x_common.ld"
