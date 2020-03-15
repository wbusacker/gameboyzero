#include <cpu_core.h>
#include <stdio.h>

namespace CPU{

void LR35902::crash_cpu(enum CPU_Failure_Modes mode){

    printf("CPU Is Crashing!\n");

    switch (mode){
        case CPU::INVALID_INSTRUCTION:
            printf("Invalid Instruction\n");
            break;
        
        default:
            printf("Unkown Exception");
            break;
    }

    printf("flag - sub          %01d\n", flags.sub);
    printf("flag - zero         %01d\n", flags.zero);
    printf("flag - carry        %01d\n", flags.carry);
    printf("flag - half_carry   %01d\n", flags.half_carry);

    printf("Register A          %03d   %02X\n", A, A);
    printf("Register B          %03d   %02X\n", B, B);
    printf("Register C          %03d   %02X\n", C, C);
    printf("Register D          %03d   %02X\n", D, D);
    printf("Register E          %03d   %02X\n", E, E);
    printf("Register H          %03d   %02X\n", H, H);
    printf("Register L          %03d   %02X\n", L, L);

    uint16_t BC = (static_cast<uint16_t>(A) << 8) | B;
    uint16_t DE = (static_cast<uint16_t>(D) << 8) | E;
    uint16_t HL = (static_cast<uint16_t>(H) << 8) | L;

    printf("Register BC         %05d %04X\n",BC,BC);
    printf("Register DE         %05d %04X\n",DE,DE);
    printf("Register HL         %05d %04X\n",HL,HL);

    printf("Stack Pointer       %04X\n", stack_pointer);
    printf("Program Counter     %04X\n", program_counter);

    fflush(stdout);

}

}