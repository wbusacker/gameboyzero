#include <cpu_core.h>

namespace CPU {

void
  LR35902::process_flow(uint8_t instr) {

    uint16_t nn_lsb;
    uint16_t nn_msb;
    uint16_t offset;

    switch (instr) {
        case 0x18: /* Unconditional Relative Jump                           */
            offset = memory_bus.fetch_addr(program_counter++);
            program_counter += offset;
            instr_cycles = 3;
            break;

        case 0x20: /* Branch Relative on Conditional Code NZ                */
            offset = memory_bus.fetch_addr(program_counter++);
            if (flags.zero == false) {
                program_counter += offset;
                instr_cycles = 4;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0x28: /* Branch Relative on Conditional Code Z                 */
            offset = memory_bus.fetch_addr(program_counter++);
            if (flags.zero == true) {
                program_counter += offset;
                instr_cycles = 4;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0x30: /* Branch Relative on Conditional Code NC                */
            offset = memory_bus.fetch_addr(program_counter++);
            if (flags.carry == false) {
                program_counter += offset;
                instr_cycles = 4;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0x38: /* Branch Relative on Conditional Code C                 */
            offset = memory_bus.fetch_addr(program_counter++);
            if (flags.carry == true) {
                program_counter += offset;
                instr_cycles = 4;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0xC0: /* Return from call on Conditional Code NZ               */
            if (flags.zero == false) {
                nn_lsb          = memory_bus.fetch_addr(stack_pointer++);
                nn_msb          = memory_bus.fetch_addr(stack_pointer++);
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 5;
            } else {
                instr_cycles = 2;
            }

            break;

        case 0xC2: /* Branch absolute on Conditional Code NZ                */
            nn_lsb = memory_bus.fetch_addr(program_counter++);
            nn_msb = memory_bus.fetch_addr(program_counter++);
            if (flags.zero == false) {
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 4;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0xC3: /* Unconditional Jump absolute nn                        */
            nn_lsb          = memory_bus.fetch_addr(program_counter++);
            nn_msb          = memory_bus.fetch_addr(program_counter++);
            program_counter = (nn_msb << 8) | nn_lsb;
            instr_cycles    = 3;
            break;

        case 0xC4: /* Call on Condtional Code NZ                            */
            nn_lsb = memory_bus.fetch_addr(program_counter++);
            nn_msb = memory_bus.fetch_addr(program_counter++);
            if (flags.zero == false) {
                memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
                memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 6;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0xC7: /* Unconditionall call to fixed address 0x00             */
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = 0x00;
            break;

        case 0xC8: /* Return from call on Conditional Code Z                */
            if (flags.zero == true) {
                nn_lsb          = memory_bus.fetch_addr(stack_pointer++);
                nn_msb          = memory_bus.fetch_addr(stack_pointer++);
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 5;
            } else {
                instr_cycles = 2;
            }
            break;

        case 0xC9: /* Unconditional Return from Call                        */
            nn_lsb          = memory_bus.fetch_addr(stack_pointer++);
            nn_msb          = memory_bus.fetch_addr(stack_pointer++);
            program_counter = (nn_msb << 8) | nn_lsb;
            instr_cycles    = 4;
            break;

        case 0xCA: /* Branch absolute on Conditional Code Z                 */
            nn_lsb = memory_bus.fetch_addr(program_counter++);
            nn_msb = memory_bus.fetch_addr(program_counter++);
            if (flags.zero == true) {
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 4;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0xCC: /* Call on Condtional Code Z                             */
            nn_lsb = memory_bus.fetch_addr(program_counter++);
            nn_msb = memory_bus.fetch_addr(program_counter++);
            if (flags.zero == true) {
                memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
                memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 6;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0xCD: /* Unconditional Call nn                                 */
            nn_lsb = memory_bus.fetch_addr(program_counter++);
            nn_msb = memory_bus.fetch_addr(program_counter++);
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = (nn_msb << 8) | nn_lsb;
            instr_cycles    = 6;
            break;

        case 0xCF: /* Unconditionall call to fixed address 0x08             */
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = 0x08;
            break;

        case 0xD0: /* Return from call on Conditional Code NC               */
            if (flags.carry == false) {
                nn_lsb          = memory_bus.fetch_addr(stack_pointer++);
                nn_msb          = memory_bus.fetch_addr(stack_pointer++);
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 5;
            } else {
                instr_cycles = 2;
            }
            break;

        case 0xD2: /* Branch absolute on Conditional Code NC                */
            nn_lsb = memory_bus.fetch_addr(program_counter++);
            nn_msb = memory_bus.fetch_addr(program_counter++);
            if (flags.carry == false) {
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 4;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0xD4: /* Call on Condtional Code NC                            */
            nn_lsb = memory_bus.fetch_addr(program_counter++);
            nn_msb = memory_bus.fetch_addr(program_counter++);
            if (flags.zero == false) {
                memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
                memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 6;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0xD7: /* Unconditionall call to fixed address 0x10             */
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = 0x10;
            break;

        case 0xD8: /* Return from call on Conditional Code NZ               */
            if (flags.carry == true) {
                nn_lsb          = memory_bus.fetch_addr(stack_pointer++);
                nn_msb          = memory_bus.fetch_addr(stack_pointer++);
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 5;
            } else {
                instr_cycles = 2;
            }
            break;

        case 0xD9: /* Unconditional Return from Call Enabling Interrupts    */
            nn_lsb             = memory_bus.fetch_addr(stack_pointer++);
            nn_msb             = memory_bus.fetch_addr(stack_pointer++);
            program_counter    = (nn_msb << 8) | nn_lsb;
            instr_cycles       = 4;
            interrupts_enabled = true;
            break;

        case 0xDA: /* Branch absolute on Conditional Code NC                */
            nn_lsb = memory_bus.fetch_addr(program_counter++);
            nn_msb = memory_bus.fetch_addr(program_counter++);
            if (flags.carry == false) {
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 4;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0xDC: /* Branch absolute on Conditional Code C                 */
            nn_lsb = memory_bus.fetch_addr(program_counter++);
            nn_msb = memory_bus.fetch_addr(program_counter++);
            if (flags.carry == true) {
                program_counter = (nn_msb << 8) | nn_lsb;
                instr_cycles    = 4;
            } else {
                instr_cycles = 3;
            }
            break;

        case 0xDF: /* Unconditionall call to fixed address 0x18             */
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = 0x18;
            break;

        case 0xE7: /* Unconditionall call to fixed address 0x20             */
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = 0x20;
            break;

        case 0xE9: /* Unconditional Jump HL                                 */
            program_counter = ((uint16_t)H << 8) | L;
            break;

        case 0xEF: /* Unconditionall call to fixed address 0x28             */
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = 0x28;
            break;

        case 0xF7: /* Unconditionall call to fixed address 0x30             */
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = 0x30;
            break;

        case 0xFF: /* Unconditionall call to fixed address 0x38             */
            // memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter >> 8));
            // memory_bus.store_addr(--stack_pointer, (uint8_t)(program_counter));
            program_counter = 0x38;
            break;

        default:
            crash_cpu(CPU::UNKNOWN_INSTRUCTION);
    }
}

}    // namespace CPU