#include <mbc1.h>

namespace Cart {

uint8_t
  MBC1::read_memory(uint16_t addr) {

    /* If addr is in the first 16KB its in the rom bank */
    uint8_t bank_number = 0;
    if (addr < 0x8000) {

        /* Calculate the bank number    */
        /* If we're in extended mode, Bank2 plays into things   */
        if ((addr < 0x4000) && (extended_memory_mode)) {
            bank_number |= (bank2 << 5);
        } else if ((addr >= 0x4000) && (addr < 0x8000)) {
            bank_number = (bank2 << 5) | bank1;
        }

        /* Keep the addr in the range of the bank size */
        addr %= ROM_BANK_SIZE;
        return rom_banks[bank_number][addr % Cart::ROM_BANK_SIZE];
    }

    /* If the address is in the RAM range and RAM is enabled    */
    if ((addr < 0xC000) && (addr >= 0xA000)) {

        if (enable_ram) {
            /* Select bank  */
            if (extended_memory_mode) {
                bank_number = bank2;
            }

            addr %= RAM_BANK_SIZE;
            return ram_banks[bank_number][addr % Cart::RAM_BANK_SIZE];
        } else {
            printf("[CART ] FATAL!!! RAM IS DISABLED\n");
        }
    }

    /* There is no other memory on the chip so just return 0 */
    return 0;
}

}    // namespace Cart