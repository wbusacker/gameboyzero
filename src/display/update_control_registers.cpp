#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::update_control_registers(void) {

    static sf::Color pixel_white(255, 255, 255);
    static sf::Color pixel_66(170, 170, 170);
    static sf::Color pixel_33(85, 85, 85);
    static sf::Color pixel_black(0, 0, 0);

    /* Update the LCDC Register */
    uint8_t lcdc_register = main_memory.fetch_addr(Graphics::LCDC_ADDR);

    lcdc.operation           = ((lcdc_register & 0x80) != 0) ? true : false;
    lcdc.windows_tile_map    = ((lcdc_register & 0x40) != 0) ? TILE_MAP_1_ADDR : TILE_MAP_0_ADDR;
    lcdc.window_display      = ((lcdc_register & 0x20) != 0) ? true : false;
    lcdc.bg_window_tile_data = ((lcdc_register & 0x10) != 0) ? TILE_PATTERN_BUFFER_0 : TILE_PATTERN_BUFFER_1;
    lcdc.bg_tile_map         = ((lcdc_register & 0x08) != 0) ? TILE_MAP_1_ADDR : TILE_MAP_0_ADDR;
    lcdc.tall_sprites        = ((lcdc_register & 0x04) != 0) ? true : false;
    lcdc.display_sprites     = ((lcdc_register & 0x02) != 0) ? true : false;
    lcdc.bg_window_display   = ((lcdc_register & 0x01) != 0) ? true : false;

    /* Update the STAT Register */

    uint8_t stat_register = main_memory.fetch_addr(Graphics::STAT_ADDR);

    stat.lyc_selectable = ((stat_register & 0x40) != 0) ? true : false;
    // stat.mode_10 = ((stat_register & 0x20) != 0) ? true : false;
    // stat.mode_01 = ((stat_register & 0x10) != 0) ? true : false;
    // stat.mode_00 = ((stat_register & 0x08) != 0) ? true : false;
    stat.lyc_coincidence = ((stat_register & 0x04) != 0) ? true : false;
    // stat.mode = stat_register & 0x3;

    scroll_x = main_memory.fetch_addr(Graphics::SCX_ADDR);
    scroll_y = main_memory.fetch_addr(Graphics::SCY_ADDR);

    /* Update the background palette    */
    uint8_t pallete_map = main_memory.fetch_addr(Graphics::BGP_ADDR);

    uint8_t pallete_no;
    for (pallete_no = 0; pallete_no < Graphics::PIXEL_COLOR_DEPTH; pallete_no++) {
        uint8_t color = (pallete_map >> (pallete_no * 2)) & 0b11;

        switch (color) {
            case 0:
                background_palette[pallete_no] = &pixel_white;
                break;
            case 1:
                background_palette[pallete_no] = &pixel_66;
                break;
            case 2:
                background_palette[pallete_no] = &pixel_33;
                break;
            case 3:
                background_palette[pallete_no] = &pixel_black;
                break;
        }
    }

    /* Update the sprite palette 0   */
    pallete_map = main_memory.fetch_addr(Graphics::OBP0_ADDR);

    for (pallete_no = 0; pallete_no < Graphics::PIXEL_COLOR_DEPTH; pallete_no++) {
        uint8_t color = (pallete_map >> (pallete_no * 2)) & 0b11;

        switch (color) {
            case 0:
                sprite_palette_0[pallete_no] = &pixel_white;
                break;
            case 1:
                sprite_palette_0[pallete_no] = &pixel_66;
                break;
            case 2:
                sprite_palette_0[pallete_no] = &pixel_33;
                break;
            case 3:
                sprite_palette_0[pallete_no] = &pixel_black;
                break;
        }
    }

    /* Update the sprite palette 1   */
    pallete_map = main_memory.fetch_addr(Graphics::OBP1_ADDR);

    for (pallete_no = 0; pallete_no < Graphics::PIXEL_COLOR_DEPTH; pallete_no++) {
        uint8_t color = (pallete_map >> (pallete_no * 2)) & 0b11;

        switch (color) {
            case 0:
                sprite_palette_1[pallete_no] = &pixel_white;
                break;
            case 1:
                sprite_palette_1[pallete_no] = &pixel_66;
                break;
            case 2:
                sprite_palette_1[pallete_no] = &pixel_33;
                break;
            case 3:
                sprite_palette_1[pallete_no] = &pixel_black;
                break;
        }
    }
}

}    // namespace Graphics