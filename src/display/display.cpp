#include <display.h>

namespace Graphics {

Display::Display(IRQ::Controller &irq, Memory::Memory_Map &mm, pthread_mutex_t *global_window_lock) :
    irq_controller(irq), main_memory(mm), rate_limit(Graphics::FRAME_PERIOD) {
    gwl             = global_window_lock;
    display_counter = 0;
    h_line          = 0;

    // rate_limit = new Monotonic(Graphics::FRAME_PERIOD);

    frame_image.create(Graphics::DISPLAY_WIDTH, Graphics::DISPLAY_HEIGHT, sf::Color::Green);

    // uint16_t x, y;
    // grayscale_buffer = new uint8_t *[Graphics::DISPLAY_WIDTH];

    // for (x = 0; x < Graphics::DISPLAY_WIDTH; x++) {
    //     grayscale_buffer[x] = new uint8_t[Graphics::DISPLAY_HEIGHT];

    //     for (y = 0; y < Graphics::DISPLAY_HEIGHT; y++) {
    //         grayscale_buffer[x][y] = y + x;
    //     }
    // }

    stat.mode    = MODE_0;
    mode_counter = 0;

    scroll_x = 64;
    scroll_y = 0;

    sem_init(&frame_sync, 0, 0);

    pthread_mutex_init(&list_lock, NULL);
    mode_list = NULL;

    request_destroy = false;
    new_frame       = false;

    pthread_create(&frame_render_thread_handle, NULL, &Display::frame_renderer, this);
    pthread_create(&tile_pattern_buffer_thread_handle, NULL, &Display::tile_pattern_buffer_renderer, this);
    pthread_create(&tile_map_thread_handle, NULL, &Display::tile_map_renderer, this);
}

Display::~Display() {
    // uint16_t col;
    // for (col = 0; col < Graphics::DISPLAY_WIDTH; col++) {
    //     delete[] grayscale_buffer[col];
    // }
    // delete[] grayscale_buffer;

    struct Mode_List *next;
    next = mode_list;
    while (next != NULL) {
        struct Mode_List *working;
        working = next;
        next    = next->next;
        delete working;
    }
}

Monotonic::Monotonic(double rate) {
    struct timespec timer_get;

    clock_gettime(CLOCK_MONOTONIC, &timer_get);

    last_release = timer_get.tv_sec + (static_cast<double>(timer_get.tv_nsec) / 1E9);

    monotonic_rate = rate;
}

}    // namespace Graphics