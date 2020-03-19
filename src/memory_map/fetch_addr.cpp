#include <memory_map.h>

namespace Memory{

uint8_t Memory_Map::fetch_addr(uint16_t addr){

    /* Overlay 0xE000 - 0xFE00 and 0xC000 - 0xDE00  */

    if((addr < 0xDE00) && (addr >= 0xC000)){
        addr += 0x2000;
    }

    /* If we're in the cartridge ranges, pass it off    */
    if( ((addr >= 0x0000) && (addr < 0x8000)) ||
        ((addr >= 0xA000) && (addr < 0xC000)) )
    {
        return loaded_cartridge->read_memory(addr);
    }

    return general_memory[addr];

}


}