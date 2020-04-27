#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::perform_mode_2(void) {
    // printf("Perform Mode 2\n");

    /* Update the tile frame buffer */

    uint8_t x_tile;
    uint8_t y_tile;
    for(y_tile = 0; y_tile < Graphics::TILES_PER_COL; y_tile++){
        for(x_tile = 0; x_tile < Graphics::TILES_PER_ROW; x_tile++){

            /* Find which Tile to use   */
            // uint16_t tile_pattern_num = lcdc.bg_tile_map + (y_tile * Graphics::TILES_PER_ROW) + x_tile;
            uint16_t tile_pattern_num = (y_tile * Graphics::TILES_PER_ROW) + x_tile;

            tile_pattern_num %= (256 + 128);

            /* Find the Address of the tile to use  */
            uint16_t pattern_addr = lcdc.bg_window_tile_data + (tile_pattern_num * Graphics::TILE_PATTERN_SIZE);

            // pattern_addr = 0x8000;

            uint8_t tile_row;
            for(tile_row = 0; tile_row < Graphics::TILE_SIZE; tile_row++){
                /* Get the two bytes that make up the tile  */
                uint8_t lsb;
                uint8_t msb;

                lsb = main_memory.fetch_addr(pattern_addr + (tile_row * 2));
                msb = main_memory.fetch_addr(pattern_addr + (tile_row * 2) + 1);

                uint8_t bit;
                for(bit = 0; bit < Graphics::TILE_SIZE; bit++){

                    uint8_t val;

                    val = (lsb >> (7 - bit)) & 0b1;
                    val |= ((msb >> (7 - bit)) & 0b1) << 1;

                    uint8_t *pixel = &(grayscale_buffer[(x_tile * Graphics::TILE_SIZE) + bit][(y_tile * Graphics::TILE_SIZE) + tile_row]);

                    switch (val) {
                        case 0:
                            *pixel = 0xFF;
                            break;
                        case 1:
                            *pixel = 0xAA;
                            break;
                        case 2:
                            *pixel = 0x55;
                            break;
                        case 3:
                            *pixel = 0x00;
                            break;
                        default:
                            *pixel = 0x88;
                    }
                }
            }
        }
    }

    return;
}

}