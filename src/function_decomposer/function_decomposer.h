#ifndef FUNCTION_DECOMPOSER_H
#define FUNCTION_DECOMPOSER_H

#include <memory_map.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

namespace Disassembler {

const uint32_t CALL_MAP_SIZE = 65536;

const char* const OUTPUT_NAME = "function_decomposition.txt";

class Function_Decomposer {

    public:
    Function_Decomposer(Memory::Memory_Map &mem);

    void register_call(uint16_t addr);

    private:
    Memory::Memory_Map &memory_bus;
    bool *              known_calls;

    FILE *out_handle;

    uint32_t known_functions;
};

void    print_instr_mnemonic(uint8_t instr);
char *  get_instr_mnemonic(uint8_t instr);
void    print_cb_mnemonic(uint8_t instr);
char *  get_cb_mnemonic(uint8_t instr);
uint8_t get_instr_bytes(uint8_t instr);

}    // namespace Disassembler

#endif