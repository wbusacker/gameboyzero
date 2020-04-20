#include <cartridge.h>
#include <cpu_core.h>
#include <debugger.h>
#include <display.h>
#include <mbc1.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

CPU::LR35902 *global_cpu;

void
error_catch(int sig_num) {

    if (sig_num == SIGSEGV) {
        printf("Segmentation Fault\n");
    }

    global_cpu->crash_cpu(CPU::SYSTEM_FAILURE);

    exit(-1);
}

int
main(void) {

    signal(SIGSEGV, error_catch);
    signal(SIGINT, error_catch);

    printf("Starting Gameboy Zero\n");

    /* Load up the cartridge    */
    FILE *fp;
    fp = fopen("loz_la.gb", "r");

    if (fp == NULL) {
        perror("Cannot open file\n");
        exit(-1);
    }

    printf("Determining Cartridge Type\n");
    Cart::Cartridge *cart;
    switch (Cart::determine_cart_type(fp)) {
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

    cart->init_cart(fp);

    fclose(fp);

    /* Setup the IRQ Controller */
    IRQ::Controller irqc;

    /* Create Main Memory Bus   */
    Memory::Memory_Map main_memory(cart, &irqc);

    /* Setup Display controller */
    Graphics::Display disp(irqc, main_memory);

    /* Create the CPU           */
    CPU::LR35902 cpu(main_memory, irqc);
    global_cpu = &cpu;

    /* Hookup the Debugger      */
    Debug::GB_Debugger gbdb(&cpu);

    /* Begin cycling the CPU at the appropriate rate    */

    timespec timer_get;
    double   last_cycle_time;
    double   cur_cycle_time;

    clock_gettime(CLOCK_MONOTONIC, &timer_get);
    last_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    while (1) {
        // printf("Running CPU\n");
        // fflush(stdout);
        cpu.cycle_cpu();

        // printf("Drawing Dispaly\n");
        // fflush(stdout);
        disp.cycle_display();

        // printf("Drawing Debugger\n");
        // fflush(stdout);

        // getc(stdin);
        // usleep(10);
        // clock_gettime(CLOCK_MONOTONIC, &timer_get);
        // cur_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);
        // if(cur_cycle_time > (last_cycle_time + CPU::CORE_PERIOD)){
        //     printf("Cycle Time Blew by %10.9f ns\n", cur_cycle_time - last_cycle_time -
        //     CPU::CORE_PERIOD); return 0;
        // }
        // last_cycle_time = cur_cycle_time;
    }

    return 0;
}
