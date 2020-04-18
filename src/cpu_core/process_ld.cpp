#include <cpu_core.h>
#include <string.h>
#include <unistd.h>

namespace CPU {

void
  LR35902::process_ld(uint8_t instr) {
    uint8_t *dst_reg;
    uint8_t *src_reg;
    uint8_t  hl_wr;
    uint16_t nn_lsb;
    uint16_t nn_msb;
    uint16_t nn;
    uint8_t  F;

    /* Register to Register Transfer    */
    if (check_bits(instr, 0b11000000, 0b01000000)) {

        dst_reg = get_reg_ptr_from_number(instr >> 3);
        src_reg = get_reg_ptr_from_number(instr >> 0);

        /* Check for HL Indirect */
        if (dst_reg == NULL) {
            dst_reg      = &hl_wr;
            instr_cycles = 2;
        } else if (src_reg == NULL) {
            src_reg      = &hl_wr;
            hl_wr        = memory_bus.fetch_addr(get_HL_indirect());
            instr_cycles = 2;
        } else {
            instr_cycles = 1;
        }

        *dst_reg = *src_reg;

        /* If the destination was HL, put it back */
        if (dst_reg == &hl_wr) {
            memory_bus.store_addr(get_HL_indirect(), hl_wr);
        }

        /* Immediate to Register            */
    } else if (check_bits(instr, 0b11010111, 0b00000110) || check_bits(instr, 0b11001111, 0b00001110) ||
               check_bits(instr, 0b11100111, 0b00000110)) {
        dst_reg      = get_reg_ptr_from_number(instr >> 3);
        *dst_reg     = memory_bus.fetch_addr(program_counter++);
        instr_cycles = 2;

        /* Immediate to Register Pair       */
    } else if (check_bits(instr, 0b11001111, 0b00000001)) {

        nn_lsb = memory_bus.fetch_addr(program_counter++);
        nn_msb = memory_bus.fetch_addr(program_counter++);

        switch (instr & 0xF0) {
            case 0x00:
                B = nn_msb;
                C = nn_lsb;
                break;

            case 0x10:
                D = nn_msb;
                E = nn_lsb;
                break;

            case 0x20:
                H = nn_msb;
                L = nn_lsb;
                break;

            case 0x30:
                stack_pointer = (static_cast<uint16_t>(nn_msb) << 8) | nn_lsb;
        }

        instr_cycles = 3;

        /* Start using the switch statement */
    } else {
        switch (instr) {
            case 0x02: /* A to BC Indirect                      */
                memory_bus.store_addr(get_BC_indirect(), A);
                instr_cycles = 2;
                break;

            case 0x08: /* Stack Pointer to Immediate Indirect   */
                nn_lsb = memory_bus.fetch_addr(program_counter++);
                nn_msb = memory_bus.fetch_addr(program_counter++);
                nn     = (nn_msb << 8) | nn_lsb;
                memory_bus.store_addr(nn, static_cast<uint8_t>(stack_pointer & 0xFF));
                memory_bus.store_addr(nn + 1, static_cast<uint8_t>((stack_pointer >> 8) & 0xFF));
                instr_cycles = 5;
                break;

            case 0x0A: /* BC Indirect to A                      */
                A            = memory_bus.fetch_addr(get_BC_indirect());
                instr_cycles = 2;
                break;

            case 0x12: /* A to DE Indirect                      */
                memory_bus.store_addr(get_DE_indirect(), A);
                instr_cycles = 2;
                break;

            case 0x1A: /* DE Indirect to A                      */
                A            = memory_bus.fetch_addr(get_DE_indirect());
                instr_cycles = 2;
                break;

            case 0x22: /* A to HL Indirect ++                   */
                memory_bus.store_addr(get_HL_indirect(), A);
                HL_inc();
                instr_cycles = 2;
                break;

            case 0x2A: /* HL Indirect ++ to A                   */
                A = memory_bus.fetch_addr(get_HL_indirect());
                HL_inc();
                instr_cycles = 2;
                break;

            case 0x32: /* A to HL Indirect --                   */
                memory_bus.store_addr(get_HL_indirect(), A);
                HL_dec();
                instr_cycles = 2;
                break;

            case 0x36: /* Immediate to HL Indirect              */
                memory_bus.store_addr(get_HL_indirect(), memory_bus.fetch_addr(program_counter++));
                instr_cycles = 3;
                break;

            case 0x3A: /* HL Indirect -- to A                   */
                A = memory_bus.fetch_addr(get_HL_indirect());
                HL_dec();
                instr_cycles = 2;
                break;

            case 0xC1: /* POP BC                                */
                C            = memory_bus.fetch_addr(stack_pointer++);
                B            = memory_bus.fetch_addr(stack_pointer++);
                instr_cycles = 3;
                break;

            case 0xC5: /* PUSH BC                               */
                stack_pointer--;
                memory_bus.store_addr(stack_pointer--, B);
                memory_bus.store_addr(stack_pointer, C);
                instr_cycles = 4;
                break;

            case 0xD1: /* POP DE                                */
                E            = memory_bus.fetch_addr(stack_pointer++);
                D            = memory_bus.fetch_addr(stack_pointer++);
                instr_cycles = 3;
                break;

            case 0xD5: /* PUSH DE                               */
                stack_pointer--;
                memory_bus.store_addr(stack_pointer--, D);
                memory_bus.store_addr(stack_pointer, E);
                instr_cycles = 4;
                break;

            case 0xE0: /* A to High Immediate Indirect          */
                nn_lsb = memory_bus.fetch_addr(program_counter++);
                memory_bus.store_addr(0xFF00 | nn_lsb, A);
                instr_cycles = 3;
                break;

            case 0xE1: /* POP HL                                */
                L            = memory_bus.fetch_addr(stack_pointer++);
                H            = memory_bus.fetch_addr(stack_pointer++);
                instr_cycles = 3;
                break;

            case 0xE2: /* A to High C Indirect                  */
                memory_bus.store_addr(0xFF | C, A);
                instr_cycles = 2;
                break;

            case 0xE5: /* PUSH HL                               */
                stack_pointer--;
                memory_bus.store_addr(stack_pointer--, H);
                memory_bus.store_addr(stack_pointer, L);
                instr_cycles = 4;
                break;

            case 0xEA: /* A to Immediate Indirect               */
                nn_lsb = memory_bus.fetch_addr(program_counter++);
                nn_msb = memory_bus.fetch_addr(program_counter++);
                memory_bus.store_addr((static_cast<uint16_t>(nn_msb) << nn_lsb) | C, A);
                instr_cycles = 4;
                break;

            case 0xF0: /* High Immediate Indirect to A          */
                nn_lsb       = memory_bus.fetch_addr(program_counter++);
                A            = memory_bus.fetch_addr(0xFF | nn_lsb);
                instr_cycles = 3;
                break;

            case 0xF1: /* POP AF                                */
                F = memory_bus.fetch_addr(stack_pointer++);
                memcpy(&flags, &F, 1);
                A            = memory_bus.fetch_addr(stack_pointer++);
                instr_cycles = 3;
                break;

            case 0xF2: /* High C Indirect to A                  */
                A            = memory_bus.fetch_addr(0xFF00 | C);
                instr_cycles = 2;
                break;

            case 0xF5: /* PUSH AF                               */
                stack_pointer--;
                memory_bus.store_addr(stack_pointer--, A);
                memcpy(&F, &flags, 1);
                memory_bus.store_addr(stack_pointer, F);
                instr_cycles = 3;
                break;

            case 0xF8: /* Stack Pointer Offset into HL          */
                nn_lsb     = memory_bus.fetch_addr(program_counter++);
                nn         = stack_pointer + nn_lsb;
                H          = (nn >> 8);
                L          = (nn & 0xFF);
                flags.zero = false;
                flags.sub  = false;
                break;

            case 0xF9: /* HL to Stack Pointer                   */
                stack_pointer = get_HL_indirect();
                instr_cycles  = 2;
                break;

            case 0xFA: /* Immediate Indirect to A               */
                nn_lsb       = memory_bus.fetch_addr(program_counter++);
                nn_msb       = memory_bus.fetch_addr(program_counter++);
                A            = memory_bus.fetch_addr((static_cast<uint16_t>(nn_msb) << nn_lsb) | C);
                instr_cycles = 4;
                break;
        }
    }
}

}    // namespace CPU