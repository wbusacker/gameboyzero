#include <memory_map.h>

namespace Memory {

void Memory_Map::store_addr(uint16_t addr, uint8_t val) {

    /* Overlay 0xE000 - 0xFE00 and 0xC000 - 0xDE00  */

    if ((addr < 0xE000) && (addr >= 0xFE00)) {
        addr -= 0x2000;
    }

    /* If we're in the cartridge ranges, pass it off    */
    if (((addr >= 0x0000) && (addr < 0x8000)) || ((addr >= 0xA000) && (addr < 0xC000))) {
        loaded_cartridge->write_memory(addr, val);
        return;

    } else if ((addr >= 0x8000) && (addr < 0xA000)) {
        // printf("[WRITE] Video Ram\n");

    } else if ((addr >= 0xC000) && (addr < 0xE000)) {
        // printf("[WRITE] Internal Ram\n");

    } else if ((addr >= 0xE000) && (addr < 0xFE00)) {
        // printf("[WRITE] Echo Internal Ram\n");

    } else if ((addr >= 0xFE00) && (addr < 0xFEA0)) {
        // printf("[WRITE] Sprite Memory\n");

    } else if ((addr >= 0xFEA0) && (addr < 0xFF00)) {
        // printf("[WRITE] Empty Unusable IO 1\n");

    } else if ((addr >= 0xFF00) && (addr < 0xFF4C)) {
        // printf("[WRITE] IO Ports %x\n", addr);

    } else if ((addr >= 0xFF4C) && (addr < 0xFF80)) {
        // printf("[WRITE] Empty Unusable IO 2\n");

    } else if ((addr >= 0xFF80) && (addr < 0xFFFF)) {
        // printf("[WRITE] Internal RAM\n");

    } else if ((addr = 0xFFFF)) {
        irq_controller->set_enable_mask(val);
    }

    fflush(stdout);

    general_memory[addr] = val;
}

}    // namespace Memory