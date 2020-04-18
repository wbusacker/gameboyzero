#include <debugger.h>

namespace Debug {

GB_Debugger::GB_Debugger(CPU::LR35902 *cc) {
    cpu_core = cc;

    display_window.create(sf::VideoMode(Debug::DEBUG_WINDOWS_WIDTH, DEBUG_WINDOWS_HEIGHT), "Gameboy Zero Memory Map");

    /* Load Dejavu Font     */
    if (! loaded_font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        printf("Warnings! Cannot load font\n");
        return;
    }

    mem_table.configure(&display_window, &loaded_font, 0, 0, DEBUG_WINDOWS_WIDTH, DEBUG_WINDOWS_HEIGHT);

    // mem_table.set_table_entry

    pthread_create(&frame_render_thread_handle, NULL, &GB_Debugger::render_thread, this);
}

}    // namespace Debug