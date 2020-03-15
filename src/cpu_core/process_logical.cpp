#include <cpu_core.h>

namespace CPU{

void LR35902::process_logical(uint8_t instr){
    
    uint8_t rotate_bit;

    switch(instr){
        case 0x07: /* RLCA  */
            rotate_bit = (A & 0x80) >> 7;
            A <<= 1;
            A |= rotate_bit;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(A == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;

        case 0x0F: /* RRCA  */
            rotate_bit = (A & 0x01);
            A >>= 1;
            A |= rotate_bit << 7;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(A == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;

        case 0x17: /* RLA   */
            rotate_bit = (A & 0x80) >> 7;
            A <<= 1;
            A |= flags.carry ? 0x01 : 0x00;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(A == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;

        case 0x1F: /* RRA   */
            rotate_bit = (A & 0x01);
            A >>= 1;
            A |= flags.carry ? 0x80 : 0x00;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(A == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;

        case 0xCB: /* CB Op */
            process_cb();
            break;

    }

}

}