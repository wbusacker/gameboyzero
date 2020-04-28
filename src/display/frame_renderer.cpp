#include <display.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace Graphics {

void *Display::frame_renderer(void *arg) {

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

    while (1) {

        // sem_wait(&(disp->frame_sync));

        // switch(disp->stat.mode){
        //     case MODE_0:
        //         disp->perform_mode_0();
        //         break;
        //     case MODE_1:
        //         disp->perform_mode_1();
        //         break;
        //     case MODE_2:
        //         disp->perform_mode_2();
        //         break;
        //     case MODE_3:
        //         disp->perform_mode_3();
        //         break;
        // }

        disp->perform_mode_2();
        disp->perform_mode_1();

        // clock_gettime(CLOCK_MONOTONIC, &timer_get);
        // cur_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);
        // double fr      = 1.0 / (cur_cycle_time - last_cycle_time);
        // printf("\rFR : %6.2f", fr);
        // fflush(stdout);

        // last_cycle_time = cur_cycle_time;
    }
}

}    // namespace Graphics