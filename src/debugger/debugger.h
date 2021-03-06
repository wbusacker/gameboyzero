#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <SFML/Graphics.hpp>
#include <cpu_core.h>
#include <sfml_table.h>
#include <stdint.h>

namespace Debug {

const uint16_t DEBUG_WINDOWS_HEIGHT = 700;
const uint16_t DEBUG_WINDOWS_WIDTH  = 1000;
const uint16_t MEMORY_TABLE_HEIGHT  = 32;
const uint16_t MEMORY_TABLE_WIDTH   = 16;
const uint16_t MAX_FILE_NAME_LEN    = 1024;

enum CPU_Debugger_Index_enm {
    FLAGS_SUB = 0,
    FLAGS_ZERO,
    FLAGS_CARRY,
    FLAGS_HALF_CARRY,
    REG_A,
    REG_B,
    REG_C,
    REG_D,
    REG_E,
    REG_H,
    REG_L,
    STACK_POINTER,
    PROGRAM_COUNTER,
    CPU_CYCLES,
    INTERRUPT_ENABLED,
    STALL_PROCESSOR,
    CPU_FREQUENCY,
    CPU_DEBUGGER_INDEX_ENM_SIZE
};

class GB_Debugger {

    public:
    GB_Debugger(CPU::LR35902 *cc, pthread_mutex_t *global_window_lock);

    static void *render_thread(void *arg);

    void kill_threads(void);
    // void draw(void);

    private:
    sf::RenderWindow display_window;

    pthread_t frame_render_thread_handle;

    CPU::LR35902 *cpu_core;

    SFML_Table mem_table;
    sf::Font   loaded_font;

    SFML_Text core_registers[CPU_DEBUGGER_INDEX_ENM_SIZE];
    SFML_Text core_register_names[CPU_DEBUGGER_INDEX_ENM_SIZE];

    bool request_destroy;

    /* Global Window Lock   */
    pthread_mutex_t *gwl;
};

}    // namespace Debug

#endif