#ifndef GB_DISPLAY_H
#define GB_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <irq_controller.h>
#include <memory_map.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>

namespace Graphics {

const uint16_t DISPLAY_CLOCK_DIVIDER = 17475;
const uint8_t  DISPLAY_PIXEL_SIZE    = 2;
const uint16_t DISPLAY_WIDTH         = 256;
const uint16_t DISPLAY_HEIGHT        = 256;
const uint16_t H_LINE_CYCLE_COUNT    = 114;
const uint16_t V_LINE_CYCLE_COUNT    = H_LINE_CYCLE_COUNT * 10;
const uint16_t DISPLAY_ROW_COUNT     = 144;
const uint16_t DISPLAY_COL_COUNT     = 160;
const uint16_t TILE_MAP_0_ADDR       = 0x9800;
const uint16_t TILE_MAP_1_ADDR       = 0x9C00;
const uint16_t TILE_PATTERN_BUFFER_0 = 0x8000;
const uint16_t TILE_PATTERN_BUFFER_1 = 0x8800;
const uint16_t TILE_PATTERN_SIZE     = 16;
const uint8_t  TILE_SIZE             = 8;
const uint8_t  TILES_PER_ROW         = (Graphics::DISPLAY_WIDTH / Graphics::TILE_SIZE);

class Display {

    public:
    Display(IRQ::Controller &irq, Memory::Memory_Map &mm);

    ~Display();

    void cycle_display();

    static void *frame_renderer(void *arg);

    IRQ::Controller &   irq_controller;
    Memory::Memory_Map &main_memory;

    uint16_t display_counter;

    uint8_t **grayscale_buffer;

    sf::RenderWindow display_window;

    sf::RectangleShape **pixels;

    pthread_t frame_render_thread_handle;
    sem_t     frame_sync;

    uint16_t h_line;
};

}    // namespace Graphics

#endif