#include <cpu_core.h>

namespace CPU{

bool    print_diagnostics = true;

LR35902::LR35902(Memory::Memory_Map &bus) : memory_bus(bus){
    flags.sub           = false;
    flags.zero          = false;
    flags.carry         = false;
    flags.half_carry    = false;
    flags.padding       = 0x0;

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

    trace_buffer_overflow = false;
    trace_buffer_bottom = 0;

    static char* default_instr = "Default INSTR";

    uint16_t i;
    for(i = 0; i < CPU::TRACE_BUFFER_LEN; i++){
        instruction_trace_buffer[i] = default_instr;
        instruction_trace_buffer_addr[i] = 0xFFFF;
    }

}

}