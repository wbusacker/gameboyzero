#include <cpu_core.h>

namespace CPU {

bool print_diagnostics = true;

LR35902::LR35902(Memory::Memory_Map &bus, IRQ::Controller &irq) : memory_bus(bus), irq_controller(irq) {
    flags.sub        = false;
    flags.zero       = false;
    flags.carry      = false;
    flags.half_carry = false;
    flags.padding    = 0x0;

    A = 0;
    B = 0;
    C = 0;
    D = 0;
    E = 0;
    H = 0;
    L = 0;

    stack_pointer   = 0;
    program_counter = 0x0100;

    stall_processor    = false;
    instr_cycles       = 0;
    interrupts_enabled = true;
    enable_interrupt   = true;

    trace_buffer_overflow = false;
    trace_buffer_bottom   = 0;

    static char default_instr[CPU::MNEMONIC_LENGTH] = "Default INSTR";

    uint16_t i;
    for (i = 0; i < CPU::TRACE_BUFFER_LEN; i++) {

        trace_buffer[i].addr     = 0xFFFF;
        trace_buffer[i].count    = 0x0;
        trace_buffer[i].mnemonic = default_instr;
    }

    num_clock_cycles = 0;

    timespec timer_get;
    clock_gettime(CLOCK_MONOTONIC, &timer_get);

    cpu_start_time_ns = timer_get.tv_nsec;
    cpu_start_time_ns += static_cast<uint64_t>(timer_get.tv_sec) * 1E9;

    pthread_mutex_init(&cpu_control_lock, NULL);
}

}    // namespace CPU