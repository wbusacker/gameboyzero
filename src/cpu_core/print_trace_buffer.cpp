#include <cpu_core.h>
#include <stdio.h>

namespace CPU {

void
  LR35902::print_trace_buffer(void) {

    printf("CPU Trace Buffer\n");

    uint16_t i;
    uint16_t index;
    uint16_t lines_to_print;

    /* Determine starting point for printing    */
    if (trace_buffer_overflow) {
        index          = (trace_buffer_bottom + 1) % CPU::TRACE_BUFFER_LEN;
        lines_to_print = TRACE_BUFFER_LEN;
    } else {
        index          = 0;
        lines_to_print = trace_buffer_bottom + 1;
    }

    printf(" Wall Time (s)  |  CPU Time (s)   |  CPU Cycles  | ST P | ADDR | Mnemonic\n");
    //          123456789ABC | 123456789ABC | 1234 |
    for (i = 0; i < lines_to_print; i++) {
        printf("%15.9f | %15.9f | %12ld | %04X | %04X | %s\n", trace_buffer[index].wall_time,
               trace_buffer[index].count * CPU::CORE_PERIOD, trace_buffer[index].count,
               trace_buffer[index].stack_pointer, trace_buffer[index].addr, trace_buffer[index].mnemonic);
        index = (index + 1) % CPU::TRACE_BUFFER_LEN;
    }
}

}    // namespace CPU