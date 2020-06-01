#include <display.h>
#include <memory_map.h>

namespace Memory {

void Memory_Map::oam_dma(uint8_t index) {
    /* Main memory isn't accessed during DMA, so just bulk copy */
    uint16_t start_addr = static_cast<uint16_t>(index) << 8;
    uint8_t  i;
    for (i = 0; i < (Graphics::MAX_NUM_SPRITES * Graphics::OAM_SIZE_BYTES); i++) {
        store_addr(Graphics::OAM_BUFFER_ADDR + i, fetch_addr(start_addr + i));
    }
}

}    // namespace Memory