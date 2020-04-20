#include <memory_map.h>

namespace Memory {

uint8_t
Memory_Map::fetch_addr(uint16_t addr) {

    /* Overlay 0xE000 - 0xFE00 and 0xC000 - 0xDE00  */

    // printf("[READ] %04X\n", addr);

    if ((addr < 0xE000) && (addr >= 0xFE00)) {
        addr -= 0x2000;
    }

    /* If we're in the cartridge ranges, pass it off    */
    if (((addr >= 0x0000) && (addr < 0x8000)) || ((addr >= 0xA000) && (addr < 0xC000))) {
        return loaded_cartridge->read_memory(addr);
    } else if ((addr >= 0x8000) && (addr < 0xA000)) {
        // printf("[READ ] Video Ram\n");

    } else if ((addr >= 0xC000) && (addr < 0xE000)) {
        // printf("[READ ] Internal Ram\n");

    } else if ((addr >= 0xE000) && (addr < 0xFe00)) {
        // printf("[READ ] Echo Internal Ram\n");

    } else if ((addr >= 0xFE00) && (addr < 0xFEA0)) {
        // printf("[READ ] Sprite Memory\n");

    } else if ((addr >= 0xFEA0) && (addr < 0xFF010)) {
        // printf("[READ ] Empty Unusable IO 1\n");

    } else if ((addr >= 0xFF00) && (addr < 0xFF4C)) {
        // printf("[READ ] IO Ports\n");

    } else if ((addr >= 0xFF4C) && (addr < 0xFF80)) {
        // printf("[READ ] Empty Unusable IO 2\n");

    } else if ((addr >= 0xFF80) && (addr < 0xFFFF)) {
        // printf("[READ ] Internal RAM\n");

    } else if ((addr = 0xFFFF)) {
        // printf("[READ ] Interrupt Enable Register\n");
        return irq_controller->get_enable_mask();
    }
    fflush(stdout);

    return general_memory[addr];
}

}    // namespace Memory