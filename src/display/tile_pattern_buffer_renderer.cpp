#include <display.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace Graphics {

void *Display::tile_pattern_buffer_renderer(void *arg) {

    Graphics::Display *disp = reinterpret_cast<Graphics::Display *>(arg);

    /* Good chance this starts up before the rest of the system is ready to go
        so sleep for a bit
    */

    usleep(1000000);

    // timespec timer_get;
    // double   last_cycle_time;
    // double   cur_cycle_time;

    // clock_gettime(CLOCK_MONOTONIC, &timer_get);
    // last_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    printf("Preparing to render frame\n");
    fflush(stdout);

    sf::Image tile_pattern_image;

    tile_pattern_image.create(Graphics::TILE_DP_TILE_ROW * Graphics::TILE_SIZE,
                              Graphics::TILE_DP_TILE_COL * Graphics::TILE_SIZE,
                              sf::Color::Green);

    while (1) {

        uint16_t tile_no;
        
        for( tile_no = 0; tile_no < SYSTEM_TILE_COUNT; tile_no++){

            uint16_t pattern_addr = TILE_PATTERN_BUFFER_0 + (tile_no * Graphics::TILE_PATTERN_SIZE);

            uint16_t display_row = tile_no / Graphics::TILE_DP_TILE_ROW;
            uint16_t display_col = tile_no % Graphics::TILE_DP_TILE_ROW;

            uint8_t tile_row;

            for(tile_row = 0; tile_row < Graphics::TILE_SIZE; tile_row++){

                uint8_t lsb = disp->main_memory.fetch_addr(pattern_addr + (tile_row * 2));
                uint8_t msb = disp->main_memory.fetch_addr(pattern_addr + (tile_row * 2) + 1);

                uint8_t bit;
                for( bit = 0; bit < Graphics::TILE_SIZE; bit++){
                    uint8_t val;

                    val = (lsb >> (7 - bit)) & 0b1;
                    val |= ((msb >> (7 - bit)) & 0b1) << 1;

                    sf::Color color(0,0,0,255);

                    switch(val & 0b11){
                        case 0:
                            color.r = 0xFF;
                            color.g = 0xFF;
                            color.b = 0xFF;
                            break;
                        case 1:
                            color.r = 0xAA;
                            color.g = 0xAA;
                            color.b = 0xAA;
                            break;
                        case 2:
                            color.r = 0x55;
                            color.g = 0x55;
                            color.b = 0x55;
                            break;
                        case 3:
                            color.r = 0x00;
                            color.g = 0x00;
                            color.b = 0x00;
                            break;
                    }

                    // color.r = 0;
                    // color.b = 255;
                    // color.g = 0;

                    tile_pattern_image.setPixel((Graphics::TILE_SIZE * display_col) + bit,
                                                (Graphics::TILE_SIZE * display_row) + tile_row,
                                                color);

                }


            }


        }

        sf::Texture texture;
        texture.loadFromImage(tile_pattern_image);

        sf::Sprite sprite(texture);

        sprite.scale(Graphics::DISPLAY_PIXEL_SIZE, Graphics::DISPLAY_PIXEL_SIZE);

        pthread_mutex_lock(disp->gwl);

        disp->tile_pattern_buffer_display.clear();

        disp->tile_pattern_buffer_display.draw(sprite);

        disp->tile_pattern_buffer_display.display();

        pthread_mutex_unlock(disp->gwl);

    }
}

}    // namespace Graphics