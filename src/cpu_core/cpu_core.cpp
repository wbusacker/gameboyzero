#include <cpu_core.h>

namespace CPU {

bool print_diagnostics = true;

LR35902::LR35902(Memory::Memory_Map &bus, IRQ::Controller &irq) :
    memory_bus(bus), irq_controller(irq), func_decomp(bus) {
    flags.sub        = false;
    flags.zero       = true;
    flags.carry      = true;
    flags.half_carry = true;
    flags.padding    = 0x0;

    A = 0x01;
    B = 0x00;
    C = 0x13;
    D = 0x00;
    E = 0xD8;
    H = 0x01;
    L = 0x4D;

    stack_pointer   = 0xFFFE;
    program_counter = 0x0100;

    stall_processor  = false;
    instr_cycles     = 0;
    enable_interrupt = false;

    trace_buffer_overflow = false;
    trace_buffer_bottom   = 0;

    static char default_instr[CPU::MNEMONIC_LENGTH] = "Default INSTR";

    uint16_t i;
    for (i = 0; i < CPU::TRACE_BUFFER_LEN; i++) {

        trace_buffer[i].addr     = 0xFFFF;
        trace_buffer[i].count    = 0x0;
        trace_buffer[i].mnemonic = default_instr;
    }

    num_clock_cycles = 0xFFFFFFFFFFFFFFFF;

    timespec timer_get;
    clock_gettime(CLOCK_MONOTONIC, &timer_get);

    cpu_start_time_ns = timer_get.tv_nsec;
    cpu_start_time_ns += static_cast<uint64_t>(timer_get.tv_sec) * 1E9;

    pthread_mutex_init(&cpu_control_lock, NULL);

    enable_instruction_trace = false;
    enable_function_trace    = false;

    trace_log_handle = fopen(CPU::TRACE_LOG_NAME, "w");
    // fclose(fp);

    // func_decomp.register_call(0x0150, 0x0700);

    last_cycle_time = 0;
    cpu_frequency   = 0;
}

LR35902::~LR35902(void){
    fclose(trace_log_handle);
}

}    // namespace CPU