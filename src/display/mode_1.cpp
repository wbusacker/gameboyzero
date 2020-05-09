#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::perform_mode_1(uint8_t working_line) {
    // printf("Perform Mode 1\n");

    // sem_post(&frame_sync);
    new_frame = true;

    // timespec timer_get;
    // double   cur_cycle_time;

    // clock_gettime(CLOCK_MONOTONIC, &timer_get);
    // cur_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    // /* Get any updates from the screen  */
    // sf::Event event;
    // while(display_window.pollEvent(event)){
    //     if(event.type == sf::Event::Closed){
    //         request_destroy = true;
    //     }
    // }

    // printf("\rFR %f", 1.0 / (cur_cycle_time - last_cycle_time));

    // last_cycle_time = cur_cycle_time;

    return;
}

}    // namespace Graphics