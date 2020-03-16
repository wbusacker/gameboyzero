#include <cpu_core.h>
#include <unistd.h>

namespace CPU{

bool check_bit_for_carry(uint16_t A, uint16_t B, uint16_t bit_place){
    uint16_t A_bit = (A >> bit_place) & 0x1;
    uint16_t B_bit = (B >> bit_place) & 0x1;
    uint16_t S_bit = ((A + B) >> bit_place) & 0x1;

    if( ((A_bit == 0) && (B_bit == 0) && (S_bit == 1)) ||
        ((A_bit == 0) && (B_bit == 1) && (S_bit == 0)) ||
        ((A_bit == 1) && (B_bit == 0) && (S_bit == 0)) ||
        ((A_bit == 1) && (B_bit == 1) && (S_bit == 1)) )
    {
        return true;
    } else {
        return false;
    }

}

void LR35902::process_arith(uint8_t instr){
    
    uint8_t *wr;
    uint16_t wr_val;
    uint16_t new_A;
    uint16_t new_wr_val;
    uint16_t n;

    /* ADD to A                 */
    if(       check_bits(instr, 0b11111000, 0b10000000) ||
              (instr == 0xC6)                           ){

        if(instr == 0xC6){
            /* We're grabbing an immediate */
            wr_val = memory_bus.fetch_addr(program_counter++);
            instr_cycles = 2;
        } else {

            wr = get_reg_ptr_from_number(instr);

            /* If wr is NULL, dereference HL */
            if(wr == NULL){
                wr_val = memory_bus.fetch_addr(get_HL_indirect());
                instr_cycles = 2;
            } else {
                wr_val = static_cast<uint16_t>(*wr);
                instr_cycles = 1;
            }
        }

        /* Perform the sum */
        new_A = A + wr_val;

        /* Check for half carry */
        if(check_bit_for_carry(A,wr_val,4)){
            flags.half_carry = true;
        } else {
            flags.half_carry = false;
        }

        /* Check for full carry */
        if(check_bit_for_carry(A,wr_val,8)){
            flags.carry = true;
        } else {
            flags.carry = false;
        }

        /* Reduce new_A to just 8 bits */
        new_A &= 0xFF;

        /* Check for Zero */
        if(new_A == 0){
            flags.zero = true;
        } else {
            flags.zero = false;
        }

        flags.sub = false;

        A = static_cast<uint8_t>(new_A);

    /* ADD to A with Carry      */
    } else if(check_bits(instr, 0b11111000, 0b10001000) ||
             (instr == 0xCE)                            ){

        if(instr == 0xCE){
            /* We're grabbing an immediate */
            wr_val = memory_bus.fetch_addr(program_counter++);
            instr_cycles = 2;

        } else {

            wr = get_reg_ptr_from_number(instr);

            /* If wr is NULL, dereference HL */
            if(wr == NULL){
                wr_val = memory_bus.fetch_addr(get_HL_indirect());
                instr_cycles = 2;
            } else {
                wr_val = static_cast<uint16_t>(*wr);
                instr_cycles = 1;
            }
        }

        /* Add to wr_val if needed */
        if(flags.carry){
            wr_val += 1;
        }

        /* Perform the sum */
        new_A = A + wr_val;

        /* Check for half carry */
        if(check_bit_for_carry(A,wr_val,4)){
            flags.half_carry = true;
        } else {
            flags.half_carry = false;
        }

        /* Check for full carry */
        if(check_bit_for_carry(A,wr_val,8)){
            flags.carry = true;
        } else {
            flags.carry = false;
        }

        /* Reduce new_A to just 8 bits */
        new_A &= 0xFF;

        /* Check for Zero */
        if(new_A == 0){
            flags.zero = true;
        } else {
            flags.zero = false;
        }

        flags.sub = false;

        A = static_cast<uint8_t>(new_A);

    /* Sub From A               */
    } else if(check_bits(instr, 0b11111000, 0b10010000) ||
             (instr == 0xD6)                            ){

        if(instr == 0xD6){
            /* We're grabbing an immediate */
            wr_val = memory_bus.fetch_addr(program_counter++);
            instr_cycles = 2;

        } else {

            wr = get_reg_ptr_from_number(instr);

            /* If wr is NULL, dereference HL */
            if(wr == NULL){
                wr_val = memory_bus.fetch_addr(get_HL_indirect());
                instr_cycles = 2;
            } else {
                wr_val = static_cast<uint16_t>(*wr);
                instr_cycles = 1;
            }
        }

        /* Force 2's compliment to make the overflow checking work */
        wr_val ^= 0xFF;
        wr_val += 1;

        /* Perform the addition of the negated number */
        new_A = A + wr_val;

        /* Check for half carry */
        if(check_bit_for_carry(A,wr_val,4)){
            flags.half_carry = true;
        } else {
            flags.half_carry = false;
        }

        /* Check for full carry */
        if(check_bit_for_carry(A,wr_val,8)){
            flags.carry = true;
        } else {
            flags.carry = false;
        }

        /* Reduce new_A to just 8 bits */
        new_A &= 0xFF;

        /* Check for Zero */
        if(new_A == 0){
            flags.zero = true;
        } else {
            flags.zero = false;
        }

        flags.sub = true;

        A = static_cast<uint8_t>(new_A);

    /* Sub From A with Carry    */
    } else if(check_bits(instr, 0b11111000, 0b10011000) ||
             (instr == 0xDE)                            ){

        if(instr == 0xDE){
            /* We're grabbing an immediate */
            wr_val = memory_bus.fetch_addr(program_counter++);
            instr_cycles = 2;

        } else {

            wr = get_reg_ptr_from_number(instr);

            /* If wr is NULL, dereference HL */
            if(wr == NULL){
                wr_val = memory_bus.fetch_addr(get_HL_indirect());
                instr_cycles = 2;
            } else {
                wr_val = static_cast<uint16_t>(*wr);
                instr_cycles = 1;
            }
        }

        /* Force 2's compliment to make the overflow checking work */
        wr_val ^= 0xFF;
        wr_val += 1;

        /* If there is a carry bit, add that too */
        uint8_t carry_invert;
        if(flags.carry){
            carry_invert = 1;
        } else {
            carry_invert = 0;
        }

        carry_invert ^= 0xFF;
        carry_invert += 1;

        wr_val += carry_invert;

        /* Perform the addition of the negated number */
        new_A = A + wr_val;

        /* Check for half carry */
        if(check_bit_for_carry(A,wr_val,4)){
            flags.half_carry = true;
        } else {
            flags.half_carry = false;
        }

        /* Check for full carry */
        if(check_bit_for_carry(A,wr_val,8)){
            flags.carry = true;
        } else {
            flags.carry = false;
        }

        /* Reduce new_A to just 8 bits */
        new_A &= 0xFF;

        /* Check for Zero */
        if(new_A == 0){
            flags.zero = true;
        } else {
            flags.zero = false;
        }

        flags.sub = true;

        A = static_cast<uint8_t>(new_A);

    /* Logical AND A            */
    } else if(check_bits(instr, 0b11111000, 0b10100000) ||
             (instr == 0xE6)                            ){

        if(instr == 0xE6){
            /* We're grabbing an immediate */
            wr_val = memory_bus.fetch_addr(program_counter++);
            instr_cycles = 2;

        } else {

            wr = get_reg_ptr_from_number(instr);

            /* If wr is NULL, dereference HL */
            if(wr == NULL){
                wr_val = memory_bus.fetch_addr(get_HL_indirect());
                instr_cycles = 2;
            } else {
                wr_val = static_cast<uint16_t>(*wr);
                instr_cycles = 1;
            }
        }

        /* Perform the operation */
        new_A = A & wr_val;

        /* Check for half carry */
        flags.half_carry = true;

        /* Check for full carry */
        flags.carry = false;

        /* Reduce new_A to just 8 bits */
        new_A &= 0xFF;

        /* Check for Zero */
        if(new_A == 0){
            flags.zero = true;
        } else {
            flags.zero = false;
        }

        flags.sub = false;

        A = static_cast<uint8_t>(new_A);

    /* Logical XOR A            */
    } else if(check_bits(instr, 0b11111000, 0b10101000) ||
             (instr == 0xEE)                            ){

        if(instr == 0xEE){
            /* We're grabbing an immediate */
            wr_val = memory_bus.fetch_addr(program_counter++);
            instr_cycles = 2;

        } else {

            wr = get_reg_ptr_from_number(instr);

            /* If wr is NULL, dereference HL */
            if(wr == NULL){
                wr_val = memory_bus.fetch_addr(get_HL_indirect());
                instr_cycles = 2;
            } else {
                wr_val = static_cast<uint16_t>(*wr);
                instr_cycles = 1;
            }
        }

        /* Perform the operation */
        new_A = A ^ wr_val;

        /* Check for half carry */
        flags.half_carry = false;

        /* Check for full carry */
        flags.carry = false;

        /* Reduce new_A to just 8 bits */
        new_A &= 0xFF;

        /* Check for Zero */
        if(new_A == 0){
            flags.zero = true;
        } else {
            flags.zero = false;
        }

        flags.sub = false;

        A = static_cast<uint8_t>(new_A);

    /* Logical OR A             */
    } else if(check_bits(instr, 0b11111000, 0b10110000) ||
             (instr == 0xF6)                            ){

        if(instr == 0xF6){
            /* We're grabbing an immediate */
            wr_val = memory_bus.fetch_addr(program_counter++);
            instr_cycles = 2;

        } else {

            wr = get_reg_ptr_from_number(instr);

            /* If wr is NULL, dereference HL */
            if(wr == NULL){
                wr_val = memory_bus.fetch_addr(get_HL_indirect());
                instr_cycles = 2;
            } else {
                wr_val = static_cast<uint16_t>(*wr);
                instr_cycles = 1;
            }
        }

        /* Perform the operation */
        new_A = A | wr_val;

        /* Check for half carry */
        flags.half_carry = false;

        /* Check for full carry */
        flags.carry = false;

        /* Reduce new_A to just 8 bits */
        new_A &= 0xFF;

        /* Check for Zero */
        if(new_A == 0){
            flags.zero = true;
        } else {
            flags.zero = false;
        }

        flags.sub = false;

        A = static_cast<uint8_t>(new_A);

    /* Logical CP A             */
    } else if(check_bits(instr, 0b11111000, 0b10111000) ||
             (instr == 0xFE)                            ){

        if(instr == 0xFE){
            /* We're grabbing an immediate */
            wr_val = memory_bus.fetch_addr(program_counter++);
            instr_cycles = 2;

        } else {

            wr = get_reg_ptr_from_number(instr);

            /* If wr is NULL, dereference HL */
            if(wr == NULL){
                wr_val = memory_bus.fetch_addr(get_HL_indirect());
                instr_cycles = 2;
            } else {
                wr_val = static_cast<uint16_t>(*wr);
                instr_cycles = 1;
            }
        }

        /* Perform the operation */
        new_A = A - wr_val;

        /* Check for half carry */
        if(check_bit_for_carry(A,wr_val,4)){
            flags.half_carry = true;
        } else {
            flags.half_carry = false;
        }

        /* Check for full carry */
        if(check_bit_for_carry(A,wr_val,8)){
            flags.carry = true;
        } else {
            flags.carry = false;
        }

        /* Reduce new_A to just 8 bits */
        new_A &= 0xFF;

        /* Check for Zero */
        if(new_A == 0){
            flags.zero = true;
        } else {
            flags.zero = false;
        }

        flags.sub = true;

        /* Don't actually change the state of A */

    /* INC Register             */
    } else if(check_bits(instr, 0b11000111, 0b00000100)) {
    
        wr = get_reg_ptr_from_number(instr >> 3);

        /* If wr is NULL, dereference HL */
        if(wr == NULL){
            wr_val = memory_bus.fetch_addr(get_HL_indirect());
            instr_cycles = 2;
        } else {
            wr_val = static_cast<uint16_t>(*wr);
            instr_cycles = 1;
        }

        /* Perform the addition of the negated number */
        new_wr_val = wr_val + 1;

        /* Check for half carry */
        if(check_bit_for_carry(0x1,wr_val,4)){
            flags.half_carry = true;
        } else {
            flags.half_carry = false;
        }

        /* Check for full carry */
        if(check_bit_for_carry(0x1,wr_val,8)){
            flags.carry = true;
        } else {
            flags.carry = false;
        }

        /* Reduce new_A to just 8 bits */
        new_wr_val &= 0xFF;

        /* Check for Zero */
        if(new_wr_val == 0){
            flags.zero = true;
        } else {
            flags.zero = false;
        }

        flags.sub = true;

        /* Put it back in the correct place */
        if(wr == NULL){
            memory_bus.store_addr(get_HL_indirect(), new_wr_val);
        } else {
            *wr = static_cast<uint8_t>(new_wr_val);
        }

    /* DEC Register             */
    } else if(check_bits(instr, 0b11000111, 0b00000100)) {
    
        wr = get_reg_ptr_from_number(instr >> 3);

        /* If wr is NULL, dereference HL */
        if(wr == NULL){
            wr_val = memory_bus.fetch_addr(get_HL_indirect());
            instr_cycles = 2;
        } else {
            wr_val = static_cast<uint16_t>(*wr);
            instr_cycles = 1;
        }

        /* Perform the addition of the negated number */
        new_wr_val = wr_val - 1;

        /* Check for half carry */
        if(check_bit_for_carry(0xfF,wr_val,4)){
            flags.half_carry = true;
        } else {
            flags.half_carry = false;
        }

        /* Check for full carry */
        if(check_bit_for_carry(0x1,wr_val,8)){
            flags.carry = true;
        } else {
            flags.carry = false;
        }

        /* Reduce new_A to just 8 bits */
        new_wr_val &= 0xFF;

        /* Check for Zero */
        if(new_wr_val == 0){
            flags.zero = true;
        } else {
            flags.zero = false;
        }

        flags.sub = true;

        /* Put it back in the correct place */
        if(wr == NULL){
            memory_bus.store_addr(get_HL_indirect(), new_wr_val);
        } else {
            *wr = static_cast<uint8_t>(new_wr_val);
        }
    
    /* 16 bit INC               */
    } else if(check_bits(instr, 0b11001111, 0b00000011)){
        instr_cycles = 2;
        switch(instr & 0xF0){
            case 0x00:
                C++;
                if(C == 0){ 
                    B++;
                }
                break;
            case 0x10:
                E++;
                if(E == 0){ 
                    D++;
                }
                break;
            case 0x20:
                HL_inc();
            case 0x30:
                stack_pointer++;
                break;
        }
    /* 16 bit DEC               */
    } else if(check_bits(instr, 0b11001111, 0b00001011)){
        instr_cycles = 2;
        switch(instr & 0xF0){
            case 0x00:
                C--;
                if(C == 0xFF){ 
                    B--;
                }
                break;
            case 0x10:
                E--;
                if(E == 0xFF){ 
                    D--;
                }
                break;
            case 0x20:
                HL_dec();
            case 0x30:
                stack_pointer--;
                break;
        }

    /* 16 Bit ADD */
    } else if(check_bits(instr, 0b11001111, 0b00001001)){
        instr_cycles = 2;
        switch(instr & 0xF0){
            case 0x00:
                C--;
                if(C == 0xFF){ 
                    B--;
                }
                break;
            case 0x10:
                E--;
                if(E == 0xFF){ 
                    D--;
                }
                break;
            case 0x20:
                HL_dec();
            case 0x30:
                stack_pointer--;
                break;
        }

    /* Switch to handle one offs    */
    } else {
        switch(instr){
            case 0x27:  /* Decimal Adjust A */
                /* Check if lower nibble violates BCD */
                if( ((A & 0x0F) > 9) || (flags.half_carry) ){
                    A += 0x06;
                }

                /* Check if upper nibble violates BCD */
                if( ((A & 0xF0) > 9) || (flags.carry)){
                    A += 0x60;
                    flags.carry = true;
                } else {
                    flags.carry = false;
                }

                if(A == 0){
                    flags.zero = true;
                } else {
                    flags.zero = false;
                }

                flags.half_carry = false;
                instr_cycles = 1;
                break;

            case 0x37:  /* Set Carry Flag   */
                flags.carry = true;
                break;

            case 0x2F:  /* Compliment A     */
                A = ~A;
                flags.half_carry = true;
                flags.sub = true;
                break;

            case 0x3F:  /* Clear Carry Flag */
                flags.carry = false;
                break;

            case 0xE8:  /* Add Immediate to Stack Pointer   */
                flags.zero = false;
                flags.sub = false;
                n = static_cast<uint16_t>(memory_bus.fetch_addr(program_counter++));

                if(check_bit_for_carry(stack_pointer, n, 4)){
                    flags.half_carry = true;
                } else {
                    flags.half_carry = false;
                }

                if(check_bit_for_carry(stack_pointer, n, 8)){
                    flags.carry = true;
                } else {
                    flags.carry = false;
                }

                stack_pointer += (n & 0xFF);

                break;

            default:
                crash_cpu(CPU::UNKNOWN_INSTRUCTION);
        }
    }


}

}