#include <display.h>
#include <stdio.h>
#include <time.h>

namespace Graphics {

void *
Display::frame_renderer(void *arg) {

    Graphics::Display *disp = reinterpret_cast<Graphics::Display *>(arg);

    timespec timer_get;
    double   last_cycle_time;
    double   cur_cycle_time;

    clock_gettime(CLOCK_MONOTONIC, &timer_get);
    last_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    printf("Preparing to render frame\n");
    fflush(stdout);

    while (1) {

        sem_wait(&(disp->frame_sync));

        disp->display_window.clear();

        uint16_t x, y;
        for (x = 0; x < Graphics::DISPLAY_WIDTH; x++) {
            for (y = 0; y < Graphics::DISPLAY_WIDTH; y++) {
                disp->pixels[x][y].setFillColor(
                  sf::Color(disp->grayscale_buffer[x][y], disp->grayscale_buffer[x][y], disp->grayscale_buffer[x][y]));
                disp->display_window.draw(disp->pixels[x][y]);
            }
        }

        disp->display_window.display();

        clock_gettime(CLOCK_MONOTONIC, &timer_get);
        cur_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);
        double fr      = 1.0 / (cur_cycle_time - last_cycle_time);
        printf("\rFR : %6.2f", fr);
        fflush(stdout);

        last_cycle_time = cur_cycle_time;
    }
}

}    // namespace Graphics