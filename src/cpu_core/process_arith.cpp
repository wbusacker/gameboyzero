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

    /* ADD to A     */
    if(       check_bits(instr, 0b11111000, 0b10000000)){
        wr = get_reg_ptr_from_number(instr);

        /* If wr is NULL, dereference HL */
        if(wr == NULL){
            wr_val = memory_bus.fetch_addr(get_HL_indirect());
            instr_cycles = 2;
        } else {
            wr_val = static_cast<uint16_t>(*wr);
            instr_cycles = 1;
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

    /* ADD to A with Carry */
    } else if(check_bits(instr, 0b11111000, 0b10001000)){
        wr = get_reg_ptr_from_number(instr);

        /* If wr is NULL, dereference HL */
        if(wr == NULL){
            wr_val = memory_bus.fetch_addr(get_HL_indirect());
            instr_cycles = 2;
        } else {
            wr_val = static_cast<uint16_t>(*wr);
            instr_cycles = 1;
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

    /* Sub From A   */
    } else if(check_bits(instr, 0b11111000, 0b10010000)){
        wr = get_reg_ptr_from_number(instr);

        /* If wr is NULL, dereference HL */
        if(wr == NULL){
            wr_val = memory_bus.fetch_addr(get_HL_indirect());
            instr_cycles = 2;
        } else {
            wr_val = static_cast<uint16_t>(*wr);
            instr_cycles = 1;
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

    /* Sub From A with Carry  */
    } else if(check_bits(instr, 0b11111000, 0b10011000)){
        wr = get_reg_ptr_from_number(instr);

        /* If wr is NULL, dereference HL */
        if(wr == NULL){
            wr_val = memory_bus.fetch_addr(get_HL_indirect());
            instr_cycles = 2;
        } else {
            wr_val = static_cast<uint16_t>(*wr);
            instr_cycles = 1;
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

    }

}

}