#include <debugger.h>
#include <stdio.h>
#include <stdlib.h>

namespace Debug {

GB_Debugger::GB_Debugger(CPU::LR35902 *cc, pthread_mutex_t *global_window_lock) {
    cpu_core = cc;
    gwl      = global_window_lock;

    display_window.create(sf::VideoMode(Debug::DEBUG_WINDOWS_WIDTH, DEBUG_WINDOWS_HEIGHT), "Gameboy Zero Memory Map");

    /* Load Dejavu Font     */
    if (! loaded_font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        printf("Warnings! Cannot load font\n");
        return;
    }

    mem_table.configure(&display_window, &loaded_font, 0, 0, DEBUG_WINDOWS_WIDTH, DEBUG_WINDOWS_HEIGHT);

    mem_table.set_table_size(MEMORY_TABLE_HEIGHT + 1, MEMORY_TABLE_WIDTH + 1);

    uint16_t i;
    char     hex[5];
    for (i = 0; i < MEMORY_TABLE_WIDTH; i++) {
        sprintf(hex, "%02X", i);
        mem_table.set_column_headers(i + 1, std::string(hex));
    }
    mem_table.set_column_headers(0, std::string("Addr"));

    uint16_t line = 0;

    for (line = 0; line < CPU_DEBUGGER_INDEX_ENM_SIZE; line++) {
        core_register_names[line].configure(&display_window,
                                            &loaded_font,
                                            (MEMORY_TABLE_WIDTH + 1) * TABLE_ENTRY_WIDTH,
                                            TABLE_ENTRY_HEIGHT * line,
                                            TABLE_ENTRY_WIDTH,
                                            TABLE_ENTRY_HEIGHT);
        core_register_names[line].set_text_size(TABLE_ENTRY_TEXT_SIZE);
        core_register_names[line].disable_border();

        core_registers[line].configure(&display_window,
                                       &loaded_font,
                                       (TABLE_ENTRY_WIDTH * 5) + ((MEMORY_TABLE_WIDTH + 1) * TABLE_ENTRY_WIDTH),
                                       TABLE_ENTRY_HEIGHT * line,
                                       TABLE_ENTRY_WIDTH,
                                       TABLE_ENTRY_HEIGHT);
        core_registers[line].set_text_size(TABLE_ENTRY_TEXT_SIZE);
        core_registers[line].disable_border();
    }

    core_register_names[FLAGS_SUB].set_string(std::string("FLAGS_SUB"));
    core_register_names[FLAGS_ZERO].set_string(std::string("FLAGS_ZERO"));
    core_register_names[FLAGS_CARRY].set_string(std::string("FLAGS_CARRY"));
    core_register_names[FLAGS_HALF_CARRY].set_string(std::string("FLAGS_HALF_CARRY"));
    core_register_names[REG_A].set_string(std::string("REG_A"));
    core_register_names[REG_B].set_string(std::string("REG_B"));
    core_register_names[REG_C].set_string(std::string("REG_C"));
    core_register_names[REG_D].set_string(std::string("REG_D"));
    core_register_names[REG_E].set_string(std::string("REG_E"));
    core_register_names[REG_H].set_string(std::string("REG_H"));
    core_register_names[REG_L].set_string(std::string("REG_L"));
    core_register_names[STACK_POINTER].set_string(std::string("STACK_POINTER"));
    core_register_names[PROGRAM_COUNTER].set_string(std::string("PROGRAM_COUNTER"));
    core_register_names[CPU_CYCLES].set_string(std::string("CPU_CYCLES"));

    pthread_create(&frame_render_thread_handle, NULL, &GB_Debugger::render_thread, this);
}

}    // namespace Debug