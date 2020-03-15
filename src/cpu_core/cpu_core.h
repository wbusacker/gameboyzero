#ifndef CPU_CORE_H
#define CPU_CORE_H

#include <stdint.h>
#include <main_bus.h>

namespace CPU{

struct CPU_flags{
    bool sub;
    bool zero;
    bool parity;
    bool carry;
    bool half_carry;
};

enum CPU_Failure_Modes{
    INVALID_INSTRUCTION
};

class LR35902{

public:
    LR35902(Bus::Main_Bus &bus);

    void cycle_cpu(void);

    /* Psuedo Private */
    void process_ld(uint8_t instr);
    void process_arith(uint8_t instr);
    void process_logical(uint8_t instr);
    void process_flow(uint8_t instr);
    void process_misc(uint8_t instr);
    void process_cb(void);

    void crash_cpu(enum CPU_Failure_Modes);

    inline uint16_t get_HL_indirect(){
        return ((uint16_t)H << 8) | L;
    }

    struct CPU_flags    flags;
    uint8_t             A;
    uint8_t             B;
    uint8_t             C;
    uint8_t             D;
    uint8_t             E;
    uint8_t             H;
    uint8_t             L;

    uint16_t            stack_pointer;
    uint16_t            program_counter;

    Bus::Main_Bus       &memory_bus;

    bool                stall_processor;
    bool                interrupts_enabled;
    bool                enable_interrupt;
    bool                disable_interrupt;

    uint8_t             instr_cycles;

};

}

#endif