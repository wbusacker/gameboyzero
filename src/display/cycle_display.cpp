#include <display.h>
#include <stdio.h>

namespace Graphics {

void
  Display::cycle_display() {
    display_counter++;
    // printf("DC = %d HL = %d\n", display_counter, h_line);

    /* If we're still drawing the h_line, do that   */
    if (h_line < Graphics::DISPLAY_HEIGHT) {

        uint8_t tile_row;
        tile_row = h_line / Graphics::TILE_SIZE;

        /* Iterate across the tiles in the h_line   */
        uint8_t tile;
        for (tile = 0; tile < Graphics::TILES_PER_ROW; tile++) {

            /* Get Tile Index   */
            uint16_t tile_index_num = TILE_MAP_0_ADDR + (tile_row * Graphics::TILES_PER_ROW) + tile;

            /* Get the tile pattern number          */
            uint8_t pattern_id = main_memory.fetch_addr(tile_index_num);

            /* Get pattern address  */
            uint16_t pattern_addr = TILE_PATTERN_BUFFER_0 + (pattern_id * Graphics::TILE_PATTERN_SIZE);

            uint16_t line_index = (h_line % 8);

            uint8_t lsb = main_memory.fetch_addr(pattern_addr + line_index);
            uint8_t msb = main_memory.fetch_addr(pattern_addr + line_index + 1);

            /* Encode the Tile Pattern              */
            uint8_t i;
            for (i = 0; i < 8; i++) {
                uint8_t val;
                val = (lsb >> (7 - i)) & 0b1;
                val |= ((msb >> (7 - i)) & 0b1) << 1;

                val &= 0b11;

                uint8_t *pixel = &(grayscale_buffer[h_line][(tile * Graphics::TILE_SIZE) + i]);

                switch (val) {
                    case 0:
                        *pixel = 0x00;
                        break;
                    case 1:
                        *pixel = 0x55;
                        break;
                    case 2:
                        *pixel = 0xAA;
                        break;
                    case 3:
                        *pixel = 0xFF;
                        break;
                    default:
                        *pixel = 0x88;
                }
            }
        }

        if (display_counter == Graphics::H_LINE_CYCLE_COUNT) {
            display_counter = 0;
            h_line++;
        }

    } else {

        if (display_counter == 0) {
            irq_controller.raise_interrupt(IRQ::INTERRUPT_BIT_V_BLANK);
        }
        // printf("\n");
        sem_post(&frame_sync);

        if (display_counter == Graphics::V_LINE_CYCLE_COUNT) {
            display_counter = 0;
            h_line          = 0;
        }
    }
}

}    // namespace Graphics