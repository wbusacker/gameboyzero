#include <display.h>

namespace Graphics {

Display::Display(IRQ::Controller &irq, Memory::Memory_Map &mm, pthread_mutex_t *global_window_lock) :
    irq_controller(irq), main_memory(mm) {
    gwl             = global_window_lock;
    display_counter = 0;
    h_line          = 0;

    display_window.create(sf::VideoMode(DISPLAY_COL_COUNT * DISPLAY_PIXEL_SIZE, DISPLAY_ROW_COUNT * DISPLAY_PIXEL_SIZE),
                          "Gameboy Zero Display");

    tile_pattern_buffer_display.create(sf::VideoMode(TILE_DP_TILE_ROW * DISPLAY_PIXEL_SIZE * TILE_SIZE,
                                                     TILE_DP_TILE_COL * DISPLAY_PIXEL_SIZE * TILE_SIZE),
                                       "Tile Pattern Buffer Display");

    frame_image.create(Graphics::DISPLAY_WIDTH, Graphics::DISPLAY_HEIGHT, sf::Color::Green);


    uint16_t x, y;
    grayscale_buffer = new uint8_t *[Graphics::DISPLAY_WIDTH];

    for (x = 0; x < Graphics::DISPLAY_WIDTH; x++) {
        grayscale_buffer[x] = new uint8_t[Graphics::DISPLAY_HEIGHT];

        for (y = 0; y < Graphics::DISPLAY_HEIGHT; y++) {
            grayscale_buffer[x][y] = y + x;
        }
    }

    stat.mode    = MODE_0;
    mode_counter = 0;

    scroll_x = 64;
    scroll_y = 0;

    sem_init(&frame_sync, 0, 0);

    pthread_mutex_init(&list_lock, NULL);
    mode_list = NULL;

    // pthread_create(&frame_render_thread_handle, NULL, &Display::frame_renderer, this);
    pthread_create(&tile_pattern_buffer_thread_handle, NULL, &Display::tile_pattern_buffer_renderer, this);
}

Display::~Display() {
    uint16_t col;
    for (col = 0; col < Graphics::DISPLAY_WIDTH; col++) {
        delete[] grayscale_buffer[col];
    }
    delete[] grayscale_buffer;

    struct Mode_List *next;
    next = mode_list;
    while (next != NULL) {
        struct Mode_List *working;
        working = next;
        next    = next->next;
        delete working;
    }
}

}    // namespace Graphics