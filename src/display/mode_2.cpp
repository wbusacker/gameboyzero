#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::perform_mode_2(uint8_t working_line) {

    uint8_t tile_line = (working_line + scroll_y) % Graphics::DISPLAY_HEIGHT;

    /* Calculate which line and tile to read    */

    uint8_t tile_map_row     = tile_line / Graphics::TILE_SIZE;
    uint8_t tile_pattern_row = tile_line % Graphics::TILE_SIZE;

    uint8_t pixel = 0;

    /* Draw all of the needed pixels on screen  */
    while (pixel < Graphics::DISPLAY_COL_COUNT) {

        uint16_t scrolled_pixel = (pixel + scroll_x) % Graphics::DISPLAY_WIDTH;

        /* Figure out which tile to grab    */
        uint16_t tile_map_no = tile_map_row * Graphics::TILES_PER_ROW;
        tile_map_no += scrolled_pixel / Graphics::TILE_SIZE;
        uint16_t tile_map_addr = lcdc.bg_tile_map + tile_map_no;

        /* Get the pattern address          */
        int16_t tile_pattern_no = main_memory.fetch_addr(tile_map_addr);

        /* Sign extend the 8 bit pattern number into a 16 bit*/
        if (lcdc.bg_window_tile_data == Graphics::TILE_PATTERN_BUFFER_1) {
            if ((tile_pattern_no & 0x80) == 0x80) {
                tile_pattern_no |= 0xFF00;
            }
        }

        uint16_t tile_pattern_addr = lcdc.bg_window_tile_data + (tile_pattern_no * Graphics::TILE_PATTERN_SIZE);

        /* Get the tile pattern data        */

        uint8_t lsb;
        uint8_t msb;

        lsb = main_memory.fetch_addr(tile_pattern_addr + (tile_pattern_row * 2));
        msb = main_memory.fetch_addr(tile_pattern_addr + (tile_pattern_row * 2) + 1);

        /* Run through all of the bits in the tile  */
        uint8_t bit;
        for (bit = (scrolled_pixel) % Graphics::TILE_SIZE; bit < Graphics::TILE_SIZE; bit++) {

            uint8_t val;

            val = (lsb >> (7 - bit)) & 0b1;
            val |= ((msb >> (7 - bit)) & 0b1) << 1;

            line_buffer[working_line].pixel_color[pixel] = val;
            line_buffer[working_line].source[pixel]      = Graphics::BACKGROUND_PIXEL;
            // grayscale_buffer[pixel][working_line] = val;

            pixel++;
        }
    }

    // /* Determine if any sprites need to be drawn    */
    // uint8_t sprite_num;
    // for (sprite_num = 0; sprite_num < Graphics::MAX_NUM_SPRITES; sprite_num++) {

    //     /* Calculate the OAM Address    */
    //     uint16_t oam_addr = Graphics::OAM_BUFFER_ADDR + (sprite_num * Graphics::OAM_SIZE_BYTES);

    //     /* Grab the sprite position data */
    //     uint8_t sprite_y_pos = main_memory.fetch_addr(oam_addr + Graphics::OAM_Y_LINE_OFFSET);
    //     uint8_t sprite_x_pos = main_memory.fetch_addr(oam_addr + Graphics::OAM_X_LINE_OFFSET);

    //     /* Is this sprite enabled or drawable?
    //         Coordinate 0,0 disable a sprite,
    //         and the offset position must be on screen
    //     */
    //     if (((sprite_y_pos != 0) && (sprite_x_pos != 0)) &&
    //         (sprite_y_pos < (Graphics::DISPLAY_ROW_COUNT + Graphics::SPRITE_Y_OFFSET)) &&
    //         (sprite_x_pos < (Graphics::DISPLAY_COL_COUNT + Graphics::SPRITE_X_OFFSET))) {

    //         /* Calculate the working sprite line    */
    //         uint8_t working_sprite_line = working_line - (sprite_y_pos - Graphics::SPRITE_Y_OFFSET);

    //         /* Does the sprite go down into into this line?
    //             Two conditions for this, one of 8px and
    //             another for 16px sprites
    //         */
    //         if (((working_sprite_line < Graphics::TILE_SIZE) && (lcdc.tall_sprites == false)) ||
    //             ((working_sprite_line < (Graphics::TILE_SIZE * 2)) && (lcdc.tall_sprites == true))) {

    //             /* Pull in the rest of the OAM Data */
    //             uint8_t tile_pattern_no = main_memory.fetch_addr(oam_addr + Graphics::OAM_PATTERN_OFFSET);
    //             uint8_t sprite_flags    = main_memory.fetch_addr(oam_addr + Graphics::OAM_FLAG_OFFSET);

    //             /* If we're on the second tile of the sprite,
    //                 increase the tile_pattern_no by one and
    //                 module the working sprite line into the
    //                 tile space
    //             */
    //             if ((working_sprite_line >= Graphics::TILE_SIZE) && (lcdc.tall_sprites == true)) {
    //                 tile_pattern_no++;
    //             }

    //             /* Sprite patterns always come from buffer 0    */
    //             uint16_t tile_pattern_addr =
    //               Graphics::TILE_PATTERN_BUFFER_0 + (tile_pattern_no * Graphics::TILE_PATTERN_SIZE);

    //             /* Get the tile pattern data        */
    //             uint8_t lsb;
    //             uint8_t msb;

    //             lsb = main_memory.fetch_addr(tile_pattern_addr + (working_sprite_line * 2));
    //             msb = main_memory.fetch_addr(tile_pattern_addr + (working_sprite_line * 2) + 1);

    //             /* Run through all of the bits in the tile  */
    //             uint8_t bit;
    //             for (bit = 0; bit < Graphics::TILE_SIZE; bit++) {

    //                 uint8_t val;

    //                 val = (lsb >> (7 - bit)) & 0b1;
    //                 val |= ((msb >> (7 - bit)) & 0b1) << 1;

    //                 uint8_t working_pixel = sprite_x_pos - Graphics::SPRITE_X_OFFSET;
    //                 /* Test if the tile is being rendered backwards */
    //                 if ((sprite_flags & (1 << OAM_X_FLIP_BTT)) != 0) {
    //                     /* Being flipped */
    //                     switch (bit) {
    //                         case 7:
    //                             working_pixel += 0;
    //                             break;
    //                         case 6:
    //                             working_pixel += 1;
    //                             break;
    //                         case 5:
    //                             working_pixel += 2;
    //                             break;
    //                         case 4:
    //                             working_pixel += 3;
    //                             break;
    //                         case 3:
    //                             working_pixel += 4;
    //                             break;
    //                         case 2:
    //                             working_pixel += 5;
    //                             break;
    //                         case 1:
    //                             working_pixel += 6;
    //                             break;
    //                         case 0:
    //                             working_pixel += 7;
    //                             break;
    //                     }
    //                 } else {
    //                     working_pixel += bit;
    //                 }

    //                 line_buffer[working_line].source[working_pixel] = Graphics::BACKGROUND_PIXEL;

    //                 bool overwritten_pixel = false;

    //                 /* Check the priority bit for color */
    //                 if ((sprite_flags & (1 << OAM_PRIORITY_BIT)) == 0) {
    //                     /* Only color 0 wins, don't modify otherwise    */
    //                     if (val == 0) {
    //                         line_buffer[working_line].pixel_color[working_pixel] = val;
    //                         overwritten_pixel                                    = true;
    //                         // grayscale_buffer[working_pixel][working_line] = val;
    //                     }
    //                 } else {
    //                     line_buffer[working_line].pixel_color[working_pixel] = val;
    //                     overwritten_pixel                                    = true;
    //                     // grayscale_buffer[working_pixel][working_line] = val;
    //                 }

    //                 /*  Determine the pallete source    */
    //                 if (overwritten_pixel == true) {
    //                     /* This is stupidly backwards, but it is what it is    */
    //                     if ((sprite_flags & (1 << OAM_PALETTE_BIT)) == 0) {
    //                         line_buffer[working_line].source[working_pixel] = SPRITE_PIXEL_1;
    //                     } else {
    //                         line_buffer[working_line].source[working_pixel] = SPRITE_PIXEL_0;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    return;
}

}    // namespace Graphics