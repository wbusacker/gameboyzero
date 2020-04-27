#include <display.h>

namespace Graphics {

Display::Display(IRQ::Controller &irq, Memory::Memory_Map &mm, pthread_mutex_t *global_window_lock) :
    irq_controller(irq), main_memory(mm) {
    gwl             = global_window_lock;
    display_counter = 0;
    h_line          = 0;

    display_window.create(sf::VideoMode(DISPLAY_WIDTH * DISPLAY_PIXEL_SIZE, DISPLAY_WIDTH * DISPLAY_PIXEL_SIZE),
                          "Gameboy Zero Display");

    uint16_t x, y;
    grayscale_buffer = new uint8_t *[Graphics::DISPLAY_WIDTH];
    pixels           = new sf::RectangleShape *[Graphics::DISPLAY_WIDTH];

    for (x = 0; x < Graphics::DISPLAY_WIDTH; x++) {
        grayscale_buffer[x] = new uint8_t[Graphics::DISPLAY_HEIGHT];
        pixels[x]           = new sf::RectangleShape[Graphics::DISPLAY_HEIGHT];

        for (y = 0; y < Graphics::DISPLAY_HEIGHT; y++) {
            grayscale_buffer[x][y] = y + x;
            pixels[x][y].setPosition(x * DISPLAY_PIXEL_SIZE, y * DISPLAY_PIXEL_SIZE);
            pixels[x][y].setSize(sf::Vector2f(DISPLAY_PIXEL_SIZE, DISPLAY_PIXEL_SIZE));
        }
    }

    stat.mode = MODE_0;
    mode_counter = 0;

    sem_init(&frame_sync, 0, 0);

    pthread_create(&frame_render_thread_handle, NULL, &Display::frame_renderer, this);
}

Display::~Display() {
    uint16_t col;
    for (col = 0; col < Graphics::DISPLAY_WIDTH; col++) {
        delete[] pixels[col];
        delete[] grayscale_buffer[col];
    }
    delete[] pixels;
    delete[] grayscale_buffer;
}

}    // namespace Graphics