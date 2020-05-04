#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::perform_mode_2(uint8_t working_line) {

    /* Calculate which line and tile to read    */

    uint8_t tile_map_row     = working_line / Graphics::TILE_SIZE;
    uint8_t tile_pattern_row = working_line % Graphics::TILE_SIZE;

    uint8_t pixel = 0;

    while (pixel < Graphics::DISPLAY_COL_COUNT) {

        /* Figure out which tile to grab    */
        uint8_t  tile_map_no   = tile_map_row + (pixel / Graphics::TILE_SIZE);
        uint16_t tile_map_addr = lcdc.bg_tile_map + tile_map_no;

        /* Get the pattern address          */
        uint16_t tile_pattern_no = main_memory.fetch_addr(tile_map_addr);

        // tile_pattern_no = tile_map_no;

        uint16_t tile_pattern_addr = lcdc.bg_window_tile_data + (tile_pattern_no * Graphics::TILE_PATTERN_SIZE);

        /* Get the tile pattern data        */

        uint8_t lsb;
        uint8_t msb;

        lsb = main_memory.fetch_addr(tile_pattern_addr + (tile_pattern_row * 2));
        msb = main_memory.fetch_addr(tile_pattern_addr + (tile_pattern_row * 2) + 1);

        /* Run through all of the bits in the tile  */
        uint8_t bit;
        for (bit = pixel % Graphics::TILE_SIZE; bit < Graphics::TILE_SIZE; bit++) {

            uint8_t val;

            val = (lsb >> (7 - bit)) & 0b1;
            val |= ((msb >> (7 - bit)) & 0b1) << 1;

            grayscale_buffer[pixel][working_line] = val;

            pixel++;
        }

        // grayscale_buffer[pixel++][working_line] = working_line % 4;
    }

    return;
}

}    // namespace Graphics