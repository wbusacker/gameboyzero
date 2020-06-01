#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::perform_mode_3(uint8_t working_line) {

    /* Flip through all of the pixels in the grayscale buffer for this row  */

    uint8_t pixel;
    for (pixel = 0; pixel < Graphics::DISPLAY_COL_COUNT; pixel++) {

        uint8_t color_number = line_buffer[working_line].pixel_color[pixel];

        sf::Color *color;

        switch (line_buffer[working_line].source[pixel]) {
            case BACKGROUND_PIXEL:
            case WINDOW_PIXEL:
                color = background_palette[color_number];
                break;
            case SPRITE_PIXEL_0:
                color = sprite_palette_0[color_number];
                break;
            case SPRITE_PIXEL_1:
                color = sprite_palette_1[color_number];
                break;
            default:
                color = background_palette[0];
        }

        frame_image.setPixel(pixel, working_line, *color);

        // frame_image.setPixel(pixel, working_line, *background_pallete[grayscale_buffer[pixel][working_line]]);
    }

    return;
}

}    // namespace Graphics