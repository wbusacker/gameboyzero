#ifndef CPU_CORE_H
#define CPU_CORE_H

#include <stdint.h>
#include <memory_map.h>

namespace CPU{

const uint8_t   MNEMONIC_LENGTH     = 32;
const uint16_t  TRACE_BUFFER_LEN    = 2048;

struct CPU_flags{
    bool sub        : 1;
    bool zero       : 1;
    bool carry      : 1;
    bool half_carry : 1;
};

enum CPU_Failure_Modes{
    INVALID_INSTRUCTION,
    UNKNOWN_INSTRUCTION
};

void print_instr_mnemonic(uint8_t instr);

class LR35902{

public:
    LR35902(Memory::Memory_Map &bus);

    void cycle_cpu(void);

    /* Psuedo Private */
    void process_ld(uint8_t instr);
    void process_arith(uint8_t instr);
    void process_logical(uint8_t instr);
    void process_flow(uint8_t instr);
    void process_misc(uint8_t instr);
    void process_cb(void);

    void crash_cpu(enum CPU_Failure_Modes);

    inline uint16_t get_BC_indirect(){return (static_cast<uint16_t>(B) << 8) | C;}
    inline uint16_t get_DE_indirect(){return (static_cast<uint16_t>(D) << 8) | E;}
    inline uint16_t get_HL_indirect(){return (static_cast<uint16_t>(H) << 8) | L;}
    
    inline void HL_inc(void){ L++; if(L == 0) { H++;}}
    inline void HL_dec(void){ L--; if(L == 0xFF) { H--;}}

    inline bool check_bits(uint8_t instr, uint8_t term_mask, uint8_t term){
        instr &= term_mask;
        if((instr ^ term) == 0){
            return true;
        } else {
            return false;
        }
    }

    uint8_t* get_reg_ptr_from_number(uint8_t num);

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

    Memory::Memory_Map  &memory_bus;

    bool                stall_processor;
    bool                interrupts_enabled;
    bool                enable_interrupt;
    bool                disable_interrupt;

    uint8_t             instr_cycles;

    char                instruction_trace_buffer[TRACE_BUFFER_LEN][MNEMONIC_LENGTH];

};

}

#endif