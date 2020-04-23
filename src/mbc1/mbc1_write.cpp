#include <mbc1.h>

namespace Cart {

void
MBC1::write_memory(uint16_t addr, uint8_t val) {

    /* RAM Gate Control         */
    if ((addr < 0x1FFF) && (addr >= 0x0000)) {
        // printf("[CART] RAM State ");
        val &= 0b1111;
        if (val == 0b1010) {
            // printf("Enabled\n");
            enable_ram = true;
        } else {
            // printf("Disabled\n");
            enable_ram = false;
        }

        /* Bank 1 Control           */
    } else if ((addr < 0x3FFF) && (addr >= 0x2000)) {
        bank1 = val & 0b11111;
        printf("[CART] Changed Bank1 Target to %d\n", bank1);
        fflush(stdout);

        /* Bank 2 Control           */
    } else if ((addr < 0x5FFF) && (addr >= 0x4000)) {
        bank2 = val & 0b11;
        printf("[CART] Changed Bank2 Target to %d\n", bank2);
        fflush(stdout);

        /* Bank 2 Control           */
    } else if ((addr < 0x7FFF) && (addr >= 0x6000)) {
        if ((val & 0b1) == 1) {
            // printf("[CART] Enabled Extended Memory Mode\n");
            extended_memory_mode = true;
        } else {
            // printf("[CART] Disabled Extended Memory Mode\n");
            extended_memory_mode = false;
        }

    } else if ((addr < 0xC000) && (addr >= 0xA000)) {

        // if(enable_ram == true){
        uint8_t bank_number = 0;
        if (extended_memory_mode) {
            bank_number = bank2;
        }

        ram_banks[bank_number][addr % Cart::RAM_BANK_SIZE] = val;
        // }
    }
}

}    // namespace Cart