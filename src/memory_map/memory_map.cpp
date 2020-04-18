#include <memory_map.h>
#include <stdlib.h>

namespace Memory {

Memory_Map::Memory_Map(Cart::Cartridge *c, IRQ::Controller *irq) {

    /* Allocate out main memory */
    general_memory   = (uint8_t *)malloc(sizeof(uint8_t) * 0xFFFF);
    loaded_cartridge = c;
    irq_controller   = irq;
}

}    // namespace Memory