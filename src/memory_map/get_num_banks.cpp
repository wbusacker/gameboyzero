#include <cartridge.h>

namespace Cart{

uint8_t get_num_rom_banks(FILE *fp){

    /* Scan ahead to address 147 */
    if(fseek(fp, 0x148, SEEK_SET) != 0){
        perror("Failed to seek forward\n");
    }

    uint8_t val = fgetc(fp);
    printf("Read %d from addr 148\n", val);

    if(fseek(fp, 0, SEEK_SET) != 0){
        perror("Failed to seek 0\n");
    }

    switch(val){
        case 0:
            return 2;

        case 1:
            return 4;

        case 2:
            return 8;

        case 3:
            return 16;

        case 4:
            return 32;

        case 5:
            return 64;

        case 6:
            return 128;

        case 0x52:
            return 72;

        case 0x53:
            return 80;

        case 0x54:
            return 96;

        default:
            return 0;
    }

}

uint8_t get_num_ram_banks(FILE *fp){
    
    /* Scan ahead to address 149 */
    if(fseek(fp, 0x149, SEEK_SET) != 0){
        perror("Failed to seek forward\n");
    }

    uint8_t val = fgetc(fp);
    printf("Read %d from addr 149\n", val);

    if(fseek(fp, 0, SEEK_SET) != 0){
        perror("Failed to seek 0\n");
    }

    switch(val){
        case 0:
            return 0;

        case 1:
            return 1;

        case 2:
            return 1;

        case 3:
            return 4;

        case 4:
            return 16;

        default:
            return 0;
    }
}

}