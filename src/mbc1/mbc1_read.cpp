#include <mbc1.h>

namespace Cart {

uint8_t MBC1::read_memory(uint16_t addr) {

    uint8_t bank_number = 0;

    /* If we're in the lower 8KB, check against mode    */
    if(addr < 0x4000){

        bank_number = 0;

        return rom_banks[bank_number][addr % ROM_BANK_SIZE];
    }

    /* If were in the switchable bank area, different rules apply   */
    if((addr < 0x8000) && (addr >= 0x4000)){
        bank_number = get_rom_bank();

        return rom_banks[bank_number][addr % ROM_BANK_SIZE];
    }

    /* If the address is in the RAM range and RAM is enabled    */
    if ((addr < 0xC000) && (addr >= 0xA000)) {

        if (enable_ram) {
            
            bank_number = get_ram_bank();

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