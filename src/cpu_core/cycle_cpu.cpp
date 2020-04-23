#include <cpu_core.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace CPU {

void
LR35902::cycle_cpu(void) {

    pthread_mutex_lock(&cpu_control_lock);

    /* Up the cycle count                           */
    num_clock_cycles++;

    /* If the processor is halted, don't cycle      */
    if (stall_processor) {
        pthread_mutex_unlock(&cpu_control_lock);
        return;
    }

    /* Take into account multi-cycle instructions   */
    if (instr_cycles > 1) {
        instr_cycles--;
        pthread_mutex_unlock(&cpu_control_lock);
        return;
    }

    /* Check for interrupts */
    if (enable_interrupt) {
        uint16_t int_addr = irq_controller.get_interrupt();
        if (int_addr != 0) {
            /* Push the PC Counter onto the stack   */
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = int_addr;
            printf("\nServicing Interrupt %x\n", program_counter);
        }
    }

    /* Fetch the next instruction */
    uint8_t instr = memory_bus.fetch_addr(program_counter);
    // printf("%04X ",program_counter);
    // print_instr_mnemonic(instr);

    /* Fill in the trace buffer     */
    trace_buffer_bottom = (trace_buffer_bottom + 1) % CPU::TRACE_BUFFER_LEN;
    // printf("TB Index = %d\n", trace_buffer_bottom);
    if (trace_buffer_bottom == 0) {
        trace_buffer_overflow = true;
        // print_trace_buffer();
    }

    timespec timer_get;
    double   last_cycle_time;
    double   cur_cycle_time;

    clock_gettime(CLOCK_MONOTONIC, &timer_get);

    trace_buffer[trace_buffer_bottom].count    = num_clock_cycles;
    trace_buffer[trace_buffer_bottom].addr     = program_counter;
    trace_buffer[trace_buffer_bottom].mnemonic = Disassembler::get_instr_mnemonic(instr);
    uint64_t cur_time_ns                       = timer_get.tv_nsec;
    cur_time_ns += static_cast<uint64_t>(timer_get.tv_sec) * 1E9;
    trace_buffer[trace_buffer_bottom].wall_time     = static_cast<double>((cur_time_ns - cpu_start_time_ns) / 1E9);
    trace_buffer[trace_buffer_bottom].stack_pointer = stack_pointer;

    // /* Check for softlock           */
    // if((instr == 0xff) && (memory_bus.fetch_addr(0x38 + 1) == 0xff)){
    //     /* We're in a continuous loop, crach the CPU    */
    //     crash_cpu(CPU::RESET_LOOP);
    //     exit(-1);
    // }

    /* Increment Program Counter */
    program_counter++;

    /* Load */
    if (check_bits(instr, 0b11100000, 0b01000000) || check_bits(instr, 0b01101110, 0b01100000) ||
        check_bits(instr, 0b11010000, 0b01000000) || check_bits(instr, 0b10111101, 0b00001000) ||
        check_bits(instr, 0b01001011, 0b01000001) || check_bits(instr, 0b11001000, 0b01001000) ||
        check_bits(instr, 0b01100111, 0b01100010) || check_bits(instr, 0b01110110, 0b01110000) ||
        check_bits(instr, 0b11000010, 0b01000000) || check_bits(instr, 0b10001111, 0b00000001) ||
        check_bits(instr, 0b11000011, 0b00000010) || check_bits(instr, 0b11000001, 0b01000001)) {
        process_ld(instr);

        /* Determine if we match an arithmetic instruction */
    } else if (check_bits(instr, 0b01001101, 0b00001001) || check_bits(instr, 0b01100011, 0b00100011) ||
               check_bits(instr, 0b10000111, 0b10000110) || check_bits(instr, 0b01000110, 0b00000100) ||
               check_bits(instr, 0b11000000, 0b10000000) || check_bits(instr, 0b10111111, 0b10101000) ||
               check_bits(instr, 0b01000111, 0b00000011)) {
        process_arith(instr);

        /* Flow Control */
    } else if (check_bits(instr, 0b11111011, 0b11000011) || check_bits(instr, 0b11111010, 0b11001000) ||
               check_bits(instr, 0b11100101, 0b11000000) || check_bits(instr, 0b11101110, 0b11001000) ||
               check_bits(instr, 0b11000111, 0b11000111) || check_bits(instr, 0b11100111, 0b00100000) ||
               check_bits(instr, 0b11011111, 0b00011000) || check_bits(instr, 0b11011111, 0b11001001) ||
               check_bits(instr, 0b11100011, 0b11000000)) {
        process_flow(instr);

        /* Load */
    } else if (check_bits(instr, 0b11100000, 0b01000000) || check_bits(instr, 0b01101110, 0b01100000) ||
               check_bits(instr, 0b11010000, 0b01000000) || check_bits(instr, 0b10111101, 0b00001000) ||
               check_bits(instr, 0b01001011, 0b01000001) || check_bits(instr, 0b11001000, 0b01001000) ||
               check_bits(instr, 0b01100111, 0b01100010) || check_bits(instr, 0b01110110, 0b01110000) ||
               check_bits(instr, 0b11000010, 0b01000000) || check_bits(instr, 0b10001111, 0b00000001) ||
               check_bits(instr, 0b11000011, 0b00000010) || check_bits(instr, 0b11000001, 0b01000001)) {
        process_ld(instr);

        /* Logical */
    } else if (check_bits(instr, 0b11111111, 0b11001011) || check_bits(instr, 0b11100111, 0b00000111)) {
        process_logical(instr);

        /* Misc */
    } else if (check_bits(instr, 0b11110111, 0b11110011) || check_bits(instr, 0b11101111, 0b00000000) ||
               check_bits(instr, 0b11111111, 0b01110110)) {
        process_misc(instr);

        /* Invalid Instruction */
    } else {
        crash_cpu(CPU::INVALID_INSTRUCTION);
    }

    pthread_mutex_unlock(&cpu_control_lock);
}

}    // namespace CPU