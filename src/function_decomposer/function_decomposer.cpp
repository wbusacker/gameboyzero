#include <function_decomposer.h>

namespace Disassembler {

Function_Decomposer::Function_Decomposer(Memory::Memory_Map &mem) : memory_bus(mem) {
    out_handle = fopen(OUTPUT_NAME, "w");

    if (out_handle == NULL) {
        printf("Failed to create Function Log... Disabling Function Decomposer\n");
        decomposer_enabled = false;

        return;
    } else {
        decomposer_enabled = true;
    }

    known_calls = (bool *)malloc(sizeof(bool) * CALL_MAP_SIZE);

    uint32_t i;
    for (i = 0; i < CALL_MAP_SIZE; i++) {
        known_calls[i] = false;
    }

    known_functions = 0;

    fclose(out_handle);
}

void Function_Decomposer::register_call(uint16_t addr, uint16_t blind_grab) {

    if (decomposer_enabled == false) {
        return;
    }

    /* Check if we know already know about this function    */
    if (known_calls[addr]) {
        return;
    }

    uint16_t starting_addr = addr;

    out_handle = fopen(OUTPUT_NAME, "a");

    known_calls[addr] = true;

    if (blind_grab != 0) {
        fprintf(out_handle, "\nBLIND GRAB OF 0x%04X Bytes\n", blind_grab);
        printf("\nBLIND GRAB OF 0x%04X Bytes\n", blind_grab);
        fflush(stdout);
    }

    fprintf(out_handle, "\n####################\n");
    fprintf(out_handle, "# Function %d\n", known_functions++);
    fprintf(out_handle, "####################\n");

    /* Run in a loop unless we see return                   */

    /* For grabbing instruction data                        */
    uint8_t lower;
    uint8_t upper;

    while (addr) {
        uint8_t instr = memory_bus.fetch_addr(addr++);

        /* Store the address in the out file    */
        fprintf(out_handle, "%04X %s", addr - 1, get_instr_mnemonic(instr));

        /* If the instruction is a CB Op, print the operation mnemonic  */
        if (instr == 0xCB) {
            fprintf(out_handle, "%s", get_cb_mnemonic(memory_bus.fetch_addr(addr++)));
        }

        /* How many bytes are we supposed to grab   */
        switch (get_instr_bytes(instr)) {
            /* One byte is always reserved for the instruction  */
            case 2:
                /* Just append a single byte to output stream   */
                fprintf(out_handle, "0x%02X\n", memory_bus.fetch_addr(addr++));
                break;

            case 3:
                /* Reorder the bytes to make sense              */
                lower = memory_bus.fetch_addr(addr++);
                upper = memory_bus.fetch_addr(addr++);
                fprintf(out_handle, "0x%02X%02X\n", upper, lower);
                break;

            default:
                fprintf(out_handle, "\n");
                break;
        }

        /* Check if this is the end of the function             */

        if ((instr == 0xC9) || (instr == 0xD9)) {
            fclose(out_handle);
            return;
        }

        /* If we were a blind grab, check how many bits are left    */
        if (blind_grab != 0) {
            if ((addr - starting_addr) > blind_grab) {
                fclose(out_handle);
                return;
            }
        }
    }
}

}    // namespace Disassembler