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

    disp->frame_image.create(Graphics::DISPLAY_WIDTH,
                        Graphics::DISPLAY_HEIGHT,
                        sf::Color::Green);

    // timespec timer_get;
    // double   last_cycle_time;
    // double   cur_cycle_time;

    // clock_gettime(CLOCK_MONOTONIC, &timer_get);
    // last_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    printf("Preparing to render frame\n");
    fflush(stdout);

    while (1) {

        Graphics::LCDC_Modes mode;

        sem_wait(&(disp->frame_sync));

        pthread_mutex_lock(&(disp->list_lock));

        /* Nothing for us to do, more of a safety measure   */
        if(disp->mode_list == NULL){
            printf("Warning! Nothing in mode list!\n");
            fflush(stdout);
            pthread_mutex_unlock(&(disp->list_lock));
            continue;
        }

        /* Get the mode to act on   */
        mode = disp->mode_list->mode;

        /* Delete the acted on mode and then move the pointer to the next   */
        struct Mode_List* ptr;
        ptr = disp->mode_list;

        disp->mode_list = disp->mode_list->next;

        delete ptr;

        pthread_mutex_unlock(&(disp->list_lock));

        switch(mode){
            case MODE_0:
                disp->perform_mode_0();
                // printf("Recv Mode 0\n");
                break;
            case MODE_1:
                disp->perform_mode_1();
                // printf("Recv Mode 1\n");
                break;
            case MODE_2:
                disp->perform_mode_2();
                // printf("Recv Mode 2\n");
                break;
            case MODE_3:
                disp->perform_mode_3();
                // printf("Recv Mode 3\n");
                break;
        }

        // disp->perform_mode_2();
        // disp->perform_mode_1();

        // clock_gettime(CLOCK_MONOTONIC, &timer_get);
        // cur_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);
        // double fr      = 1.0 / (cur_cycle_time - last_cycle_time);
        // printf("\rFR : %6.2f", fr);
        // fflush(stdout);

        // last_cycle_time = cur_cycle_time;
    }
}

}    // namespace Graphics