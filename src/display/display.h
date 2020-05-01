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
const uint8_t  DISPLAY_PIXEL_SIZE    = 3;
const uint16_t DISPLAY_WIDTH         = 256;
const uint16_t DISPLAY_HEIGHT        = 256;
const uint16_t DISPLAY_ROW_COUNT     = 144;
const uint16_t DISPLAY_COL_COUNT     = 160;
const uint16_t TILE_MAP_0_ADDR       = 0x9800;
const uint16_t TILE_MAP_1_ADDR       = 0x9C00;
const uint16_t TILE_PATTERN_BUFFER_0 = 0x8000;
const uint16_t TILE_PATTERN_BUFFER_1 = 0x8800;
const uint16_t TILE_PATTERN_SIZE     = 16;
const uint8_t  TILE_SIZE             = 8;
const uint8_t  TILES_PER_ROW         = (Graphics::DISPLAY_WIDTH / Graphics::TILE_SIZE);
const uint8_t  TILES_PER_COL         = (Graphics::DISPLAY_HEIGHT / Graphics::TILE_SIZE);

const uint16_t  SYSTEM_TILE_COUNT   = 256 + 128;
const uint8_t   TILE_DP_TILE_ROW    = 16;
const uint8_t   TILE_DP_TILE_COL    = SYSTEM_TILE_COUNT / TILE_DP_TILE_ROW;

const uint16_t   MODE_0_CYCLE_COUNT = 51;
const uint16_t   MODE_1_CYCLE_COUNT = 20;
const uint16_t   MODE_2_CYCLE_COUNT = 43;
const uint16_t   MODE_3_CYCLE_COUNT = 1140;
const uint16_t   H_LINE_CYCLE_COUNT = MODE_0_CYCLE_COUNT + 
                                      MODE_1_CYCLE_COUNT + 
                                      MODE_2_CYCLE_COUNT;

const uint16_t LCDC_ADDR = 0xFF40;
const uint16_t STAT_ADDR = 0xFF41;

const uint16_t LY_ADDR = 0xFF44;
const uint16_t LYC_ADDR = 0xFF45;

enum LCDC_Modes{
    MODE_0,
    MODE_1,
    MODE_2,
    MODE_3
};

struct LCDC_Register {
    bool     operation;
    uint16_t windows_tile_map;
    bool     window_display;
    uint16_t bg_window_tile_data;
    uint16_t bg_tile_map;
    bool     tall_sprites;
    bool     display_sprites;
    bool     bg_window_display;
};

struct STAT_Register {
    bool    lyc_selectable;
    bool    mode_10;
    bool    mode_01;
    bool    mode_00;
    bool    lyc_coincidence;
    LCDC_Modes mode;
};

class Display {

    public:
    Display(IRQ::Controller &irq, Memory::Memory_Map &mm, pthread_mutex_t *global_window_lock);

    ~Display();

    void cycle_display();

    void update_control_registers(void);

    static void *frame_renderer(void *arg);

    static void *tile_pattern_buffer_renderer(void *arg);

    void perform_mode_0(void);
    void perform_mode_1(void);
    void perform_mode_2(void);
    void perform_mode_3(void);

    IRQ::Controller &   irq_controller;
    Memory::Memory_Map &main_memory;

    uint32_t display_counter;
    uint32_t mode_counter;

    uint8_t **grayscale_buffer;

    sf::RenderWindow display_window;
    sf::RenderWindow tile_pattern_buffer_display;

    sf::RectangleShape **pixels;

    sf::Image frame_image;

    sf::Image tile_pattern_buffer_image;

    pthread_t frame_render_thread_handle;
    sem_t     frame_sync;

    pthread_t tile_pattern_buffer_thread_handle;

    uint16_t h_line;

    struct LCDC_Register lcdc;
    struct STAT_Register stat;

    /* Global Window Lock   */
    pthread_mutex_t *gwl;
};

}    // namespace Graphics

#endif