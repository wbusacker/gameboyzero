#include <cpu_core.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace CPU {

void LR35902::cycle_cpu(void) {

    // pthread_mutex_lock(&cpu_control_lock);

    /* Up the cycle count                           */
    num_clock_cycles++;

    /* Get this Cycle Time & calculate the frequency    */
    // timespec timer_get;
    // double   cur_cycle_time;

    // clock_gettime(CLOCK_MONOTONIC, &timer_get);
    // cur_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    // double total_time_passed = cur_cycle_time - (cpu_start_time_ns / 1000000000.0);

    // cpu_frequency   = num_clock_cycles / total_time_passed;
    // last_cycle_time = cur_cycle_time;

    /* Check for interrupts */
    if (enable_interrupt) {
        uint16_t int_addr = irq_controller.get_interrupt();
        if (int_addr != 0) {
            /* Push the PC Counter onto the stack   */
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = int_addr;
            // printf("\nServicing Interrupt %x\n", program_counter);

            /* Re-enable the CPU                    */
            stall_processor = false;
        }
    }

    /* If the processor is halted, don't cycle      */
    if (stall_processor) {
        // pthread_mutex_unlock(&cpu_control_lock);
        return;
    }

    /* Take into account multi-cycle instructions   */
    if (instr_cycles > 1) {
        instr_cycles--;
        // pthread_mutex_unlock(&cpu_control_lock);
        return;
    }

    num_acted_cycles++;

    /* Fetch the next instruction */
    uint8_t instr = memory_bus.fetch_addr(program_counter);
    // printf("%04X ",program_counter);
    // print_instr_mnemonic(instr);

    if (enable_instruction_trace == true) {
        log_instruction(instr);
    }

    // /* Fill in the trace buffer     */
    // trace_buffer_bottom = (trace_buffer_bottom + 1) % CPU::TRACE_BUFFER_LEN;
    // // printf("TB Index = %d\n", trace_buffer_bottom);
    // if (trace_buffer_bottom == 0) {
    //     trace_buffer_overflow = true;
    //     // print_trace_buffer();
    // }

    // clock_gettime(CLOCK_MONOTONIC, &timer_get);

    // trace_buffer[trace_buffer_bottom].count    = num_clock_cycles;
    // trace_buffer[trace_buffer_bottom].addr     = program_counter;
    // trace_buffer[trace_buffer_bottom].mnemonic = Disassembler::get_instr_mnemonic(instr);
    // uint64_t cur_time_ns                       = timer_get.tv_nsec;
    // cur_time_ns += static_cast<uint64_t>(timer_get.tv_sec) * 1E9;
    // trace_buffer[trace_buffer_bottom].wall_time     = static_cast<double>((cur_time_ns - cpu_start_time_ns) / 1E9);
    // trace_buffer[trace_buffer_bottom].stack_pointer = stack_pointer;

    // /* Check for softlock           */
    // if((instr == 0xff) && (memory_bus.fetch_addr(0x38 + 1) == 0xff)){
    //     /* We're in a continuous loop, crach the CPU    */
    //     crash_cpu(CPU::RESET_LOOP);
    //     exit(-1);
    // }

    /* Increment Program Counter */
    program_counter++;

    if (fp[instr] == NULL) {
        /* Invalid Instruction  */
        crash_cpu(CPU::INVALID_INSTRUCTION);
    }

    (this->*fp[instr])(instr);

    // pthread_mutex_unlock(&cpu_control_lock);
}

}    // namespace CPU