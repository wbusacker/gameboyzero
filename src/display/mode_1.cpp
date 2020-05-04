#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::perform_mode_1(uint8_t working_line) {
    // printf("Perform Mode 1\n");

    static double last_cycle_time = 0;

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
    double   cur_cycle_time;

    clock_gettime(CLOCK_MONOTONIC, &timer_get);
    cur_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    printf("\rFR %f", 1.0 / (cur_cycle_time - last_cycle_time));

    last_cycle_time = cur_cycle_time;

    return;
}

}    // namespace Graphics