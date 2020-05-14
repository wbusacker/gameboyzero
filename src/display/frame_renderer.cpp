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

    // usleep(1000000);

    disp->frame_image.create(Graphics::DISPLAY_WIDTH, Graphics::DISPLAY_HEIGHT, sf::Color::Green);

    // timespec timer_get;
    // double   last_cycle_time;
    // double   cur_cycle_time;

    // clock_gettime(CLOCK_MONOTONIC, &timer_get);
    // last_cycle_time = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    printf("Preparing to render frame\n");
    fflush(stdout);

    sf::Texture texture;
    sf::Sprite  sprite;
    sprite.scale(Graphics::DISPLAY_PIXEL_SIZE, Graphics::DISPLAY_PIXEL_SIZE);

    sf::Event event;

    while (1) {

        // sem_wait(&(disp->frame_sync));
        while (disp->new_frame == false)
            ;
        disp->new_frame = false;

        texture.loadFromImage(disp->frame_image);

        sprite.setTexture(texture);

        pthread_mutex_lock(disp->gwl);

        disp->display_window.clear();
        disp->display_window.draw(sprite);
        disp->display_window.display();

        pthread_mutex_unlock(disp->gwl);

        /* Process events built up  */
        while (disp->display_window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    disp->request_destroy = true;
                    return NULL;
            }
        }
    }
}

}    // namespace Graphics