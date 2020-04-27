#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::perform_mode_1(void) {
    // printf("Perform Mode 1\n");

    static double last_cycle_time = 0;

    pthread_mutex_lock(gwl);

    display_window.clear();

    uint16_t px;
    uint16_t py;
    for(px = 0; px < Graphics::DISPLAY_WIDTH; px++){
        for(py = 0; py < Graphics::DISPLAY_HEIGHT; py++){
            pixels[px][py].setFillColor(
                sf::Color(grayscale_buffer[px][py], grayscale_buffer[px][py], grayscale_buffer[px][py]));
            display_window.draw(pixels[px][py]);
        }
    }

    display_window.display();

    pthread_mutex_unlock(gwl);

    timespec timer_get;
    double cur_cycle_time;

    clock_gettime(CLOCK_MONOTONIC, &timer_get);
    cur_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    printf("FR %f", 1.0 / (cur_cycle_time - last_cycle_time));

    last_cycle_time = cur_cycle_time;

    return;
}

}