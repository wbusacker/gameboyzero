#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <SFML/Graphics.hpp>
#include <cpu_core.h>
#include <sfml_table.h>
#include <stdint.h>

namespace Debug {

const uint16_t DEBUG_WINDOWS_HEIGHT = 800;
const uint16_t DEBUG_WINDOWS_WIDTH  = 800;
const uint16_t MEMORY_TABLE_HEIGHT  = 16;
const uint16_t MEMORY_TABLE_WIDTH   = 64;

class GB_Debugger {

    public:
    GB_Debugger(CPU::LR35902 *cc);

    static void *render_thread(void *arg);

    private:
    sf::RenderWindow display_window;

    pthread_t frame_render_thread_handle;

    CPU::LR35902 *cpu_core;

    SFML_Table mem_table;
    sf::Font   loaded_font;
};

}    // namespace Debug

#endif