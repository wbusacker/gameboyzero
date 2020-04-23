#include <cpu_core.h>
#include <stdio.h>

namespace CPU {

void
LR35902::process_misc(uint8_t instr) {

    switch (instr) {
        case 0x00: /* NOP          */
            return;
        case 0x10: /* STOP         */
        case 0x76: /* HALT         */
            stall_processor = true;
            break;
        case 0xF3: /* DI           */
            enable_interrupt = false;
            break;
        case 0xFB: /* EI           */
            enable_interrupt = true;
            break;

        default:
            crash_cpu(CPU::UNKNOWN_INSTRUCTION);
    }
}

}    // namespace CPU