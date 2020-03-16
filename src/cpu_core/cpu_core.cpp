#include <cpu_core.h>

namespace CPU{

LR35902::LR35902(Bus::Main_Bus &bus) : memory_bus(bus){
    flags.sub           = false;
    flags.zero          = false;
    flags.carry         = false;
    flags.half_carry    = false;

    A   = 0;
    B   = 0;
    C   = 0;
    D   = 0;
    E   = 0;
    H   = 0;
    L   = 0;

    stack_pointer   = 0;
    program_counter = 0x0100;

    stall_processor = false;
    instr_cycles = 0;
    interrupts_enabled = true;
    enable_interrupt = true;
    disable_interrupt = false;

}

}