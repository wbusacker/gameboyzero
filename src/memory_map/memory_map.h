#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include <cartridge.h>
#include <irq_controller.h>
#include <stdint.h>

namespace Memory {

class Memory_Map {

    public:
    Memory_Map(Cart::Cartridge *c, IRQ::Controller *irq);

    virtual uint8_t fetch_addr(uint16_t addr);
    virtual void    store_addr(uint16_t addr, uint8_t val);
    virtual uint8_t get_rom_bank(void) { return loaded_cartridge->get_rom_bank(); }

    private:
    Cart::Cartridge *loaded_cartridge;
    IRQ::Controller *irq_controller;

    uint8_t *general_memory;
};

}    // namespace Memory

#endif