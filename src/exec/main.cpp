#include <stdio.h>
#include <cpu_core.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <mbc1.h>
#include <cartridge.h>

int main(void){
    printf("Starting Gameboy Zero\n");

    /* Load up the cartridge    */
    FILE *fp;
    fp = fopen("loz_la.gb","r");

    if(fp == NULL){
        perror("Cannot open file\n");
        exit(-1);
    }

    printf("Determining Cartridge Type\n");
    Cart::Cartridge *cart;
    switch(Cart::determine_cart_type(fp)){
        case Cart::CART_MBC1:
            printf("Type MBC1\n");
            cart = new Cart::MBC1();
            break;
        case Cart::CART_NO_CONTROLLER:
            printf("NO CONTROLLER Not Implemented!");
            break;
        case Cart::CART_MBC2:
            printf("MBC2 Not Implemented!");
            break;
        case Cart::CART_MBC3:
            printf("MBC3 Not Implemented!");
            break;
        case Cart::CART_MBC5:
            printf("MBC5 Not Implemented!");
            break;
        case Cart::CART_MMMO1:
            printf("MMMO1 Not Implemented!");
            break;
        case Cart::CART_CAMERA:
            printf("CAMERA Not Implemented!");
            break;
        case Cart::CART_TAMA5:
            printf("TAMA5 Not Implemented!");
            break;
        case Cart::CART_HUC3:
            printf("HUC3 Not Implemented!");
            break;
        case Cart::CART_UNKNOWN:
        default:
            printf("Unimplemented cartridge type\n");
    }

    printf("Importing ROM File\n");

    // class Cart::MBC1    cart;
    cart->init_cart(fp);

    fclose(fp);

    /* Create Main Memory Bus   */
    Memory::Memory_Map main_memory(cart);

    /* Create the CPU           */
    CPU::LR35902  cpu(main_memory);

    /* Open the ROM file and import it into the ROM bank */

    while(1){
        cpu.cycle_cpu();
        /* Approx Gameboy Clock Speed   */
        usleep(1);
        /* Debug Speed                  */
        // usleep(100000);
    }




    return 0;
}
