#include <cpu_core.h>

namespace CPU{

void LR35902::process_misc(uint8_t instr){
    
    switch(instr){
        case 0x00:  /* NOP          */
            return;
        case 0x01:  /* STOP         */
        case 0x76:  /* HALT         */
            stall_processor = true;
        case 0xF3:  /* DI           */
            disable_interrupt = true;
        case 0xF8:  /* EI           */
            enable_interrupt = true;

        default:
            crash_cpu(CPU::UNKNOWN_INSTRUCTION);
    }

}

}