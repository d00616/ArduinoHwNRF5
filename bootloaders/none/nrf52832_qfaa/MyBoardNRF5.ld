/* Linker script to configure memory regions. */
SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
        FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x80000
        RAM (rwx) :  ORIGIN = 0x20001000, LENGTH = 0xe000
}
INCLUDE "nrf5x_common.ld"
