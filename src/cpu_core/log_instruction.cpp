#include <cpu_core.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <function_decomposer.h>

namespace CPU {

void LR35902::log_instruction(uint8_t instr) {

    /* Open the file for writing    */
    // FILE *fp;

    // fp = fopen(CPU::TRACE_LOG_NAME, "a");

    // A:FE F:---- BC:006B DE:9795 HL:5796 SP:dffb PC:28c7 (cy: 978340) ppu:+0 |[00]0x28c7: 13        inc de

    fprintf(trace_log_handle, "A:%02x F:", A);

    if (flags.zero) {
        fprintf(trace_log_handle, "Z");
    } else {
        fprintf(trace_log_handle, "-");
    }

    if (flags.sub) {
        fprintf(trace_log_handle, "N");
    } else {
        fprintf(trace_log_handle, "-");
    }

    if (flags.half_carry) {
        fprintf(trace_log_handle, "H");
    } else {
        fprintf(trace_log_handle, "-");
    }

    if (flags.carry) {
        fprintf(trace_log_handle, "C");
    } else {
        fprintf(trace_log_handle, "-");
    }

    fprintf(trace_log_handle, " BC:%04x", get_BC_indirect());
    fprintf(trace_log_handle, " DE:%04x", get_DE_indirect());
    fprintf(trace_log_handle, " HL:%04x", get_HL_indirect());
    fprintf(trace_log_handle, " SP:%04x", stack_pointer);
    fprintf(trace_log_handle, " PC:%04x", program_counter);

    fprintf(trace_log_handle, " (cy: %ld) ppu:--", num_clock_cycles * 4);

    fprintf(trace_log_handle, " |[%02x]", memory_bus.get_rom_bank());


    fprintf(trace_log_handle, "0x%04x: ", program_counter);

    uint8_t i;
    uint8_t stop = Disassembler::get_instr_bytes(instr);
    for(i = 0; i < stop; i++){
        fprintf(trace_log_handle, "%02x ", memory_bus.fetch_addr(program_counter + i));
    }

    for(; i < 3; i++){
        fprintf(trace_log_handle, "   ");
    }

    fprintf(trace_log_handle, "%s\n", Disassembler::get_instr_mnemonic(instr));

    // fclose(fp);
}

}    // namespace CPU