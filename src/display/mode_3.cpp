#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::perform_mode_3(uint8_t working_line) {


    /* Flip through all of the pixels in the grayscale buffer for this row  */

    uint8_t pixel;
    for (pixel = 0; pixel < Graphics::DISPLAY_COL_COUNT; pixel++) {

        frame_image.setPixel(pixel,
                             working_line,
                             *background_pallete[grayscale_buffer[pixel][working_line]]);
    }

    return;
}

}    // namespace Graphics