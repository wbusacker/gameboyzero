#include <cpu_core.h>

namespace CPU{

enum CB_TYPE{
    RLC,
    RRC,
    RL,
    RR,
    SLA,
    SRA,
    SWAP,
    SRL,
    BIT,
    RES,
    SET
};

void LR35902::process_cb(void){
    
    /* Grab the next instruction */
    uint8_t instr = memory_bus.fetch_addr(program_counter++);

    uint8_t HL;

    HL = memory_bus.fetch_addr(get_HL_indirect());

    /* Select the target register */
    uint8_t *target_reg;
    switch(instr & 0x0F){
        case 0x00:
        case 0x08:
            target_reg = &B;
            break;
            
        case 0x01:
        case 0x09:
            target_reg = &C;
            break;
            
        case 0x02:
        case 0x0A:
            target_reg = &D;
            break;
            
        case 0x03:
        case 0x0B:
            target_reg = &E;
            break;
            
        case 0x04:
        case 0x0C:
            target_reg = &H;
            break;
            
        case 0x05:
        case 0x0D:
            target_reg = &L;
            break;
            
        case 0x06:
        case 0x0E:
            target_reg = &HL;
            break;
            
        case 0x07:
        case 0x0F:
            target_reg = &A;
            break;            
    }

    /* Select Instruction Type */
    enum CB_TYPE type = CPU::RR;

    switch(instr & 0xF0){
        case 0x00:
            if((instr & 0x08) == 0x08){
                type = CPU::RLC;
            } else {
                type = CPU::RRC;
            }
            break;

        case 0x10:
            if((instr & 0x08) == 0x08){
                type = CPU::RL;
            } else {
                type = CPU::RR;
            }
            break;

        case 0x20:
            if((instr & 0x08) == 0x08){
                type = CPU::SLA;
            } else {
                type = CPU::SRA;
            }
            break;

        case 0x30:
            if((instr & 0x08) == 0x08){
                type = CPU::SWAP;
            } else {
                type = CPU::SRL;
            }
            break;

        case 0x40:
        case 0x50:
        case 0x60:
        case 0x70:
            type = CPU::BIT;
            break;

        case 0x80:
        case 0x90:
        case 0xA0:
        case 0xB0:
            type = CPU::RES;
            break;

        case 0xC0:
        case 0xD0:
        case 0xE0:
        case 0xF0:
            type = CPU::SET;
            break;


    }

    /* For the bit manipulation instructions, pick the target bit */
    uint8_t target_bit;
    switch(instr & 0xF0){
        case 0x40:
        case 0x80:
        case 0xC0:
            target_bit = ((instr & 0x08) == 0x08) ? 0 : 1;
            break;

        case 0x50:
        case 0x90:
        case 0xD0:
            target_bit = ((instr & 0x08) == 0x08) ? 2 : 3;
            break;

        case 0x60:
        case 0xA0:
        case 0xE0:
            target_bit = ((instr & 0x08) == 0x08) ? 4 : 5;
            break;

        case 0x70:
        case 0xB0:
        case 0xF0:
            target_bit = ((instr & 0x08) == 0x08) ? 6 : 7;
            break;

        default:
            target_bit = 0;
    }

    /* If we targeted the HL register, populat */

    /* Give ourselves a nicer working register, GCC will optimize it out anyways */
    uint8_t wr = *target_reg;
    uint8_t rotate_bit;
    uint8_t check_mask;
    uint8_t upper_bit;
    switch(type){
        case CPU::RLC:  /* Rotate Left Circular         */
            rotate_bit = (wr & 0x80) >> 7;
            wr <<= 1;
            wr |= rotate_bit;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(wr == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;

        case CPU::RRC:  /* Rotate Right Circular        */
            rotate_bit = (wr & 0x01);
            wr >>= 1;
            wr |= rotate_bit << 7;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(wr == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;
            
        case CPU::RL:   /* Rotate Left                  */
            rotate_bit = (wr & 0x80) >> 7;
            wr <<= 1;
            wr |= flags.carry ? 0x01 : 0x00;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(wr == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;
            
        case CPU::RR:   /* Rotate Right                 */
            rotate_bit = (wr & 0x01);
            wr >>= 1;
            wr |= flags.carry ? 0x80 : 0x00;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(wr == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;

        case CPU::SLA:  /* Shift Left Arithmetic        */
            rotate_bit = (wr & 0x80) >> 7;
            wr <<= 1;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(wr == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;

        case CPU::SRA:  /* Shift Right Arithmetic       */
            rotate_bit = (wr & 0x01);
            upper_bit = (wr & 0x80);
            wr >>= 1;
            wr |= upper_bit;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(wr == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;

        case CPU::SRL:  /* Shift Right Logical          */
            rotate_bit = (wr & 0x01);
            wr >>= 1;
            flags.carry = (rotate_bit == 1) ? true : false;
            if(wr == 0){
                flags.zero = true;
            } else {
                flags.zero = false;
            }
            flags.half_carry    = false;
            flags.sub           = false;
            instr_cycles = 2;
            break;

        case CPU::SWAP: /* Swap Nibbles of Register     */
            uint8_t upper_nibble;
            uint8_t lower_nibble;
            upper_nibble = wr & 0xF0;
            lower_nibble = wr & 0x0F;
            wr = (lower_nibble << 4) | (upper_nibble >> 4);
            if(wr == 0){
                flags.zero = true;
            }
            flags.sub           = false;
            flags.carry         = false;
            flags.half_carry    = false;
            instr_cycles        = 2;
            break;


        case CPU::BIT:  /* Test if BIT is set           */
            check_mask = 1 << target_bit;
            if((wr & check_mask) == 0){
                flags.zero = true;
            }
            flags.sub           = false;
            flags.half_carry    = true;
            instr_cycles = 2;
            break;

        case CPU::RES:  /* Reset BIT                    */
            check_mask = 1 << target_bit;
            wr &= ~check_mask;
            instr_cycles = 2;
            break;

        case CPU::SET:  /* Set BIT                      */
            check_mask = 1 << target_bit;
            wr |= check_mask;
            instr_cycles = 2;
            break;
    }
    /* Put the working register value back */
    *target_reg = wr;

    /* If we targeted HL indirect, go place that back in memory
        and add 4 to the instruction counter
    */
    if(target_reg == &HL){
        memory_bus.store_addr(get_HL_indirect(), HL);
        instr_cycles += 4;
    }

}

}