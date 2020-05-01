#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::perform_mode_1(void) {
    // printf("Perform Mode 1\n");

    static double last_cycle_time = 0;


    sf::Color pixel_white(255,255,255);
    sf::Color pixel_66(170,170,170);
    sf::Color pixel_33(85,85,85);
    sf::Color pixel_black(0,0,0);

    uint16_t px;
    uint16_t py;
    for(px = 0; px < Graphics::DISPLAY_WIDTH; px++){
        for(py = 0; py < Graphics::DISPLAY_HEIGHT; py++){

            // sf::Color * pixel_color;
            uint8_t pixel_color;

            switch(grayscale_buffer[px][py]){
                case 0:
                    // pixel_color = &pixel_black;
                    pixel_color = 0xFF;
                    break;
                case 1:
                    // pixel_color = &pixel_black;
                    pixel_color = 0xAA;
                    break;
                case 2:
                    // pixel_color = &pixel_black;
                    pixel_color = 0x55;
                    break;
                case 3:
                    // pixel_color = &pixel_black;
                    pixel_color = 0x00;
                    break;

                default:
                    pixel_color = 0x25;
            }

            // uint16_t x_offset = px * Graphics::DISPLAY_PIXEL_SIZE;
            // uint16_t y_offset = py * Graphics::DISPLAY_PIXEL_SIZE;

            // uint16_t sx;
            // uint16_t sy;
            // for(sx = 0; sx < Graphics::DISPLAY_PIXEL_SIZE; sx++){
            //     for(sy = 0; sy < Graphics::DISPLAY_PIXEL_SIZE; sy++){
                    // frame_image.setPixel(sx + x_offset,
                    //                      sy + y_offset,
                    //                      sf::Color(pixel_color, pixel_color, pixel_color)
                    //                      );
            //     }
            // }

            frame_image.setPixel(px,
                                 py,
                                 sf::Color(pixel_color,pixel_color,pixel_color)
                                );


        }
    }

    sf::Texture texture;
    texture.loadFromImage(frame_image);

    sf::Sprite sprite(texture);

    sprite.scale(DISPLAY_PIXEL_SIZE, DISPLAY_PIXEL_SIZE);

    pthread_mutex_lock(gwl);

    display_window.clear();

    display_window.draw(sprite);

    display_window.display();

    pthread_mutex_unlock(gwl);

    timespec timer_get;
    double cur_cycle_time;

    clock_gettime(CLOCK_MONOTONIC, &timer_get);
    cur_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    printf("\rFR %f", (cur_cycle_time - last_cycle_time));

    last_cycle_time = cur_cycle_time;

    return;
}

}