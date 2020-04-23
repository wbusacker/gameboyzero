#ifndef CPU_CORE_H
#define CPU_CORE_H

#include <SFML/Graphics.hpp>
#include <function_decomposer.h>
#include <memory_map.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>

namespace CPU {

const uint8_t  MNEMONIC_LENGTH  = 32;
const uint16_t TRACE_BUFFER_LEN = 2048;

const double CORE_FREQUENCY = 1.0485E6;
const double CORE_PERIOD    = 1.0 / CORE_FREQUENCY;

struct CPU_flags {
    bool    sub : 1;
    bool    zero : 1;
    bool    carry : 1;
    bool    half_carry : 1;
    uint8_t padding : 4;
};

enum CPU_Failure_Modes { INVALID_INSTRUCTION, RESET_LOOP, UNKNOWN_INSTRUCTION, SYSTEM_FAILURE };

struct TB_entry {
    char *   mnemonic;
    uint16_t addr;
    uint64_t count;
    double   wall_time;
    uint16_t stack_pointer;
};

// void  print_instr_mnemonic(uint8_t instr);
// char *get_instr_mnemonic(uint8_t instr);

extern bool print_diagnostics;

class LR35902 {

    public:
    LR35902(Memory::Memory_Map &bus, IRQ::Controller &irq);

    void cycle_cpu(void);

    inline void
    lock_cpu(void) {
        pthread_mutex_lock(&cpu_control_lock);
        return;
    }

    inline void
    unlock_cpu(void) {
        pthread_mutex_unlock(&cpu_control_lock);
        return;
    }

    /* Psuedo Private */
    void process_ld(uint8_t instr);
    void process_arith(uint8_t instr);
    void process_logical(uint8_t instr);
    void process_flow(uint8_t instr);
    void process_misc(uint8_t instr);
    void process_cb(void);

    void print_trace_buffer(void);

    void crash_cpu(enum CPU_Failure_Modes);

    inline uint16_t
    get_BC_indirect() {
        return (static_cast<uint16_t>(B) << 8) | C;
    }
    inline uint16_t
    get_DE_indirect() {
        return (static_cast<uint16_t>(D) << 8) | E;
    }
    inline uint16_t
    get_HL_indirect() {
        return (static_cast<uint16_t>(H) << 8) | L;
    }

    inline void
    HL_inc(void) {
        L++;
        if (L == 0) {
            H++;
        }
    }
    inline void
    HL_dec(void) {
        L--;
        if (L == 0xFF) {
            H--;
        }
    }

    inline bool
    check_bits(uint8_t instr, uint8_t term_mask, uint8_t term) {
        instr &= term_mask;
        if ((instr ^ term) == 0) {
            return true;
        } else {
            return false;
        }
    }

    uint8_t *get_reg_ptr_from_number(uint8_t num);

    struct CPU_flags flags;
    uint8_t          A;
    uint8_t          B;
    uint8_t          C;
    uint8_t          D;
    uint8_t          E;
    uint8_t          H;
    uint8_t          L;

    uint16_t stack_pointer;
    uint16_t program_counter;

    Memory::Memory_Map &memory_bus;
    IRQ::Controller &   irq_controller;

    bool stall_processor;
    bool enable_interrupt;

    uint8_t instr_cycles;

    struct TB_entry trace_buffer[TRACE_BUFFER_LEN];

    bool     trace_buffer_overflow;
    uint16_t trace_buffer_bottom;
    uint64_t num_clock_cycles;

    uint64_t cpu_start_time_ns;

    pthread_mutex_t cpu_control_lock;

    Disassembler::Function_Decomposer func_decomp;

    bool enable_function_trace;
};

}    // namespace CPU

#endif