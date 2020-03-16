#include <stdio.h>
#include <main_bus.h>
#include <cpu_core.h>
#include <rom_bank.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void){
    printf("Starting Gameboy Zero\n");

    /* Create Main Memory Bus   */
    Bus::Main_Bus main_memory_bus;

    /* Create the CPU           */
    CPU::LR35902  cpu(main_memory_bus);

    /* Initialize the ROM Bank  */
    ROM::ROM_Bank   rom(0x0, 0x3FFF);

    /* Attach the ROM to the bus    */
    main_memory_bus.attach_device(&rom);

    printf("Importing ROM File\n");

    /* Open the ROM file and import it into the ROM bank */
    FILE *fp;
    fp = fopen("loz_la.gb","rb");

    if(fp == NULL){
        perror("Cannot open file\n");
        exit(-1);
    }

    uint8_t* buf;
    buf = (uint8_t*)malloc(0x4000);
    fread(buf, 1, 0x4000, fp);

    fclose(fp);

    rom.load_memory(buf, 0x4000);

    printf("Import complete!\n");

    while(1){
        cpu.cycle_cpu();
        usleep(100000);
    }



    return 0;
}
