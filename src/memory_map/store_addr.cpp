#include <memory_map.h>

namespace Memory{

void Memory_Map::store_addr(uint16_t addr, uint8_t val){

    /* Overlay 0xE000 - 0xFE00 and 0xC000 - 0xDE00  */

    if((addr <= 0xDE00) && (addr >= 0xC000)){
        addr += 0x2000;
    }

    /* If we're in the cartridge ranges, pass it off    */
    if( ((addr >= 0x0000) && (addr < 0x8000)) ||
        ((addr >= 0xA000) && (addr < 0xC000)) )
    {
        loaded_cartridge->write_memory(addr, val);
    }

    general_memory[addr] = val;


}


}