#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::perform_mode_3(uint8_t working_line) {

    static sf::Color pixel_white(255, 255, 255);
    static sf::Color pixel_66(170, 170, 170);
    static sf::Color pixel_33(85, 85, 85);
    static sf::Color pixel_black(0, 0, 0);

    /* Flip through all of the pixels in the grayscale buffer for this row  */

    uint8_t pixel;
    for (pixel = 0; pixel < Graphics::DISPLAY_COL_COUNT; pixel++) {

        switch (grayscale_buffer[pixel][working_line]) {
            case 0:
                frame_image.setPixel(pixel, working_line, pixel_white);
                break;
            case 1:
                frame_image.setPixel(pixel, working_line, pixel_66);
                break;
            case 2:
                frame_image.setPixel(pixel, working_line, pixel_33);
                break;
            case 3:
                frame_image.setPixel(pixel, working_line, pixel_black);
                break;
        }
    }

    return;
}

}    // namespace Graphics