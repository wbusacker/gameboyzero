#include <debugger.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace Debug {

// GB_Debugger::render_thread(void *arg) {
void GB_Debugger::draw(void) {

    Debug::GB_Debugger *gbdb = reinterpret_cast<Debug::GB_Debugger *>(this);

    // while (1) {

        /* Populate the table with all of the memory addresses  */
        uint16_t address = 0;
        uint16_t row;
        uint16_t col;

        char hex[8];
        for(row = 0; row < Debug::MEMORY_TABLE_HEIGHT; row++){
            for(col = 0; col <= Debug::MEMORY_TABLE_WIDTH; col++){
                /* First column entry holds the starting address    */
                if(col == 0){
                    sprintf(hex, "%04X", address);
                } else {
                    /* Get the value through the CPU Core           */
                    sprintf(hex,
                            "%02X",
                            gbdb->cpu_core->memory_bus.fetch_addr(address++)
                            );
                }

                gbdb->mem_table.set_table_entry(col, row, std::string(hex));
            }
        }

        gbdb->display_window.clear();

        /* Draw the table   */
        gbdb->mem_table.draw();
        gbdb->display_window.display();

        // usleep(100);
    // }
}

}    // namespace Debug