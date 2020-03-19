#include <mbc1.h>
#include <stdlib.h>

namespace Cart{

void MBC1::init_cart(FILE *fp){

    /* Make sure to scroll back to the start    */
    num_ram_banks = get_num_ram_banks(fp);
    num_rom_banks = get_num_rom_banks(fp);

    printf("Device has %d ROM Banks and %d RAM Banks\n", num_rom_banks, num_ram_banks);
    fflush(stdout);

    if((num_ram_banks == 0) && (num_rom_banks == 0)){
        printf("Invalid Cart File\n");
        exit(-1);
    }

    /* Allocate out space for the RAM Banks     */
    ram_banks = (uint8_t **)malloc(sizeof(uint8_t**) * num_ram_banks);
    uint8_t bank;
    uint16_t addr;
    for (bank = 0; bank < num_ram_banks; bank++){
        ram_banks[bank] = (uint8_t*)malloc(sizeof(uint8_t) * RAM_BANK_SIZE);
        for(addr = 0; addr < RAM_BANK_SIZE; addr++){
            ram_banks[bank][addr] = 0;
        }
    }

    /* Allocate out space for the ROM Banks     */
    rom_banks = (uint8_t **)malloc(sizeof(uint8_t**) * num_rom_banks);
    for (bank = 0; bank < num_rom_banks; bank++){
        rom_banks[bank] = (uint8_t*)malloc(sizeof(uint8_t) * ROM_BANK_SIZE);
        for(addr = 0; addr < ROM_BANK_SIZE; addr++){
            rom_banks[bank][addr] = 0;
        }
    }

    extended_memory_mode = false;
    enable_ram = false;
    bank1 = 1;
    bank2 = 0;

    /* Import the file into the ROM banks       */
    for(bank = 0; bank < num_rom_banks; bank++){
        for(addr = 0; addr < ROM_BANK_SIZE; addr++){
            rom_banks[bank][addr] = fgetc(fp);
        }
    }


}

}