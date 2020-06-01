#include <display.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace Graphics {

void Display::kill_threads(void) {

    request_destroy = true;

    pthread_join(frame_render_thread_handle, NULL);
    pthread_join(tile_pattern_buffer_thread_handle, NULL);
    pthread_join(tile_map_thread_handle, NULL);
}

}    // namespace Graphics