/* Linker script to configure memory regions. */
SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
        FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x2fe00
        RAM (rwx) :  ORIGIN = 0x20000000, LENGTH = 0x10000
}
INCLUDE "nrf5x_common.ld"
