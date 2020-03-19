#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include <stdint.h>
#include <cartridge.h>

namespace Memory{

class Memory_Map{

public:

    Memory_Map(Cart::Cartridge *c);

    virtual uint8_t fetch_addr(uint16_t addr);
    virtual void    store_addr(uint16_t addr, uint8_t val);

private:

    Cart::Cartridge *loaded_cartridge;

    uint8_t* general_memory;

};

}

#endif