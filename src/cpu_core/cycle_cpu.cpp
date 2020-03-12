#include <cpu_core.h>

namespace CPU{

inline bool check_bits(uint8_t instr, uint8_t term_mask, uint8_t term){

    instr &= term_mask;
    if((instr ^ term) == 0){
        return true;
    } else {
        return false;
    }

}

void LR35902::cycle_cpu(void){

    /* If the processor is halted, don't cycle */
    if(stall_processor){
        return;
    }

    /* Take into account multi-cycle instructions */
    if(instr_cycles > 1){
        instr_cycles--;
        return;
    }

    /* Fetch the next instruction */

    uint8_t instr = memory_bus.fetch_addr(program_counter);
    /* Increment Program Counter */
    program_counter++;

    /* Determine if we match an arithmetic instruction */
    if(         check_bits(instr, 0b01001101, 0b00001001) || 
                check_bits(instr, 0b01100011, 0b00100011) || 
                check_bits(instr, 0b10000111, 0b10000110) || 
                check_bits(instr, 0b01000110, 0b00000100) || 
                check_bits(instr, 0b11000000, 0b10000000) || 
                check_bits(instr, 0b10111111, 0b10101000) || 
                check_bits(instr, 0b01000111, 0b00000011) )
    {
        process_arith(instr);

    /* Flow Control */
    } else if(  check_bits(instr, 0b11111011, 0b11000011) ||
                check_bits(instr, 0b11111010, 0b11001000) ||
                check_bits(instr, 0b11100101, 0b11000000) ||
                check_bits(instr, 0b11101110, 0b11001000) ||
                check_bits(instr, 0b11000111, 0b11000111) ||
                check_bits(instr, 0b11100111, 0b00100000) ||
                check_bits(instr, 0b11011111, 0b00011000) ||
                check_bits(instr, 0b11011111, 0b11001001) ||
                check_bits(instr, 0b11100011, 0b11000000) )
    {
        process_flow(instr);

    /* Load */
    } else if(  check_bits(instr, 0b11100000, 0b01000000) ||
                check_bits(instr, 0b01101110, 0b01100000) ||
                check_bits(instr, 0b11010000, 0b01000000) ||
                check_bits(instr, 0b10111101, 0b00001000) ||
                check_bits(instr, 0b01001011, 0b01000001) ||
                check_bits(instr, 0b11001000, 0b01001000) ||
                check_bits(instr, 0b01100111, 0b01100010) ||
                check_bits(instr, 0b01110110, 0b01110000) ||
                check_bits(instr, 0b11000010, 0b01000000) ||
                check_bits(instr, 0b10001111, 0b00000001) ||
                check_bits(instr, 0b11000011, 0b00000010) ||
                check_bits(instr, 0b11000001, 0b01000001) )
    {
        process_ld(instr);

    /* Logical */
    } else if(  check_bits(instr, 0b11111111, 0b11001011) ||
                check_bits(instr, 0b11100111, 0b00000111) )
    {
        process_logical(instr);

    /* Misc */
    } else if(  check_bits(instr, 0b11110111, 0b11110011) ||
                check_bits(instr, 0b11101111, 0b00000000) ||
                check_bits(instr, 0b11111111, 0b01110110) )
    {
        process_misc(instr);

    /* Invalid Instruction */
    } else {
        crash_cpu(CPU::INVALID_INSTRUCTION);
    }


}

}