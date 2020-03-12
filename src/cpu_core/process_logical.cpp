#include <cpu_core.h>

namespace CPU{

void LR35902::process_logical(uint8_t instr){
    
    switch(instr){
        case 0x07: /* RLCA  */
            /* Check if the upper most bit is 1 */
            flags.carry = (A & 0x80) == 0x80? true : false;
            A <<= 1;
            if(A == 0){
                flags.zero          = true;
            }
            flags.sub          = false;
            flags.half_carry    = false;
            break;

        case 0x0F: /* RRCA  */
            /* Check if the upper most bit is 1 */
            flags.carry = (A & 0x01) == 0x01? true : false;
            A >>= 1;
            if(A == 0){
                flags.zero          = true;
            }
            flags.sub          = false;
            flags.half_carry    = false;
            break;

        case 0x17: /* RLA   */
            /* Check if the upper most bit is 1 */
            flags.carry = (A & 0x80) == 0x80? true : false;
            A <<= 1;
            /* Place carry bit in zeroth bit */
            A |= flags.carry ? 0x01 : 0x00;
            if(A == 0){
                flags.zero          = true;
            }
            flags.sub          = false;
            flags.half_carry    = false;
            break;

        case 0x1F: /* RRA   */
            /* Check if the upper most bit is 1 */
            flags.carry = (A & 0x01) == 0x01? true : false;
            A <<= 1;
            /* Place carry bit in upper bit */
            A |= flags.carry ? 0x80 : 0x00;
            if(A == 0){
                flags.zero          = true;
            }
            flags.sub          = false;
            flags.half_carry    = false;
            break;

        case 0xCB: /* CB Op */
            process_cb();
            break;

    }

}

}