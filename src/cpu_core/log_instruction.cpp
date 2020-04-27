#include <cpu_core.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace CPU {

void LR35902::log_instruction(uint8_t instr) {

    /* Open the file for writing    */
    FILE *fp;

    fp = fopen(CPU::TRACE_LOG_NAME, "a");

    // A:FE F:---- BC:006B DE:9795 HL:5796 SP:dffb PC:28c7 (cy: 978340) ppu:+0 |[00]0x28c7: 13        inc de

    fprintf(fp, "A:%02X F:", A);

    if (flags.zero) {
        fprintf(fp, "Z");
    } else {
        fprintf(fp, "-");
    }

    if (flags.sub) {
        fprintf(fp, "N");
    } else {
        fprintf(fp, "-");
    }

    if (flags.half_carry) {
        fprintf(fp, "H");
    } else {
        fprintf(fp, "-");
    }

    if (flags.carry) {
        fprintf(fp, "C");
    } else {
        fprintf(fp, "-");
    }

    fprintf(fp, " BC:%04X", get_BC_indirect());
    fprintf(fp, " DE:%04X", get_DE_indirect());
    fprintf(fp, " HL:%04X", get_HL_indirect());
    fprintf(fp, " SP:%04X", stack_pointer);
    fprintf(fp, " PC:%04X", program_counter);

    fprintf(fp, " (cy: %ld) ppu:--", num_clock_cycles * 4);

    fprintf(fp, " |[--]0x%04X: ", program_counter);

    fprintf(fp, "%s\n", Disassembler::get_instr_mnemonic(instr));

    fclose(fp);
}

}    // namespace CPU