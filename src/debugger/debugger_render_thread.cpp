#include <debugger.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace Debug {
void *GB_Debugger::render_thread(void *arg) {
    // void
    // GB_Debugger::draw(void) {

    Debug::GB_Debugger *gbdb = reinterpret_cast<Debug::GB_Debugger *>(arg);
    // Debug::GB_Debugger *gbdb = reinterpret_cast<Debug::GB_Debugger *>(this);

    uint64_t last_cpu_cycle_count;

    while (1) {

        /* Populate the table with all of the memory addresses  */
        uint16_t address = (gbdb->cpu_core->program_counter) / Debug::MEMORY_TABLE_WIDTH;
        address *= Debug::MEMORY_TABLE_WIDTH;
        uint16_t row;
        uint16_t col;

        address = 0x9800;

        char hex[32];
        for (row = 0; row < Debug::MEMORY_TABLE_HEIGHT; row++) {
            for (col = 0; col <= Debug::MEMORY_TABLE_WIDTH; col++) {
                /* First column entry holds the starting address    */
                if (col == 0) {
                    sprintf(hex, "%04X", address);
                } else {
                    /* Get the value through the CPU Core           */
                    sprintf(hex, "%02X", gbdb->cpu_core->memory_bus.fetch_addr(address++));
                    // hex[0] = '\0';
                }

                gbdb->mem_table.set_table_entry(col, row, std::string(hex));
            }
        }

        /* Grab the CPU Core Data   */
        uint8_t i;
        for (i = 0; i < CPU_DEBUGGER_INDEX_ENM_SIZE; i++) {
            switch (i) {
                case FLAGS_SUB:
                    sprintf(hex, "%s", gbdb->cpu_core->flags.sub ? "true" : "false");
                    break;

                case FLAGS_ZERO:
                    sprintf(hex, "%s", gbdb->cpu_core->flags.zero ? "true" : "false");
                    break;

                case FLAGS_CARRY:
                    sprintf(hex, "%s", gbdb->cpu_core->flags.carry ? "true" : "false");
                    break;

                case FLAGS_HALF_CARRY:
                    sprintf(hex, "%s", gbdb->cpu_core->flags.half_carry ? "true" : "false");
                    break;

                case REG_A:
                    sprintf(hex, "%02X", gbdb->cpu_core->A);
                    break;

                case REG_B:
                    sprintf(hex, "%02X", gbdb->cpu_core->B);
                    break;

                case REG_C:
                    sprintf(hex, "%02X", gbdb->cpu_core->C);
                    break;

                case REG_D:
                    sprintf(hex, "%02X", gbdb->cpu_core->D);
                    break;

                case REG_E:
                    sprintf(hex, "%02X", gbdb->cpu_core->E);
                    break;

                case REG_H:
                    sprintf(hex, "%02X", gbdb->cpu_core->H);
                    break;

                case REG_L:
                    sprintf(hex, "%02X", gbdb->cpu_core->L);
                    break;

                case STACK_POINTER:
                    sprintf(hex, "%04X", gbdb->cpu_core->stack_pointer);
                    break;

                case PROGRAM_COUNTER:
                    sprintf(hex, "%04X", gbdb->cpu_core->program_counter);
                    break;

                case INTERRUPT_ENABLED:
                    sprintf(hex, "%s", gbdb->cpu_core->enable_interrupt ? "true" : "false");
                    break;

                case STALL_PROCESSOR:
                    sprintf(hex, "%s", gbdb->cpu_core->stall_processor ? "true" : "false");
                    break;

                case CPU_CYCLES:
                    sprintf(hex, "%-20ld", gbdb->cpu_core->num_clock_cycles);
                    break;

                case CPU_FREQUENCY:
                    sprintf(hex, "%-08.6f", gbdb->cpu_core->cpu_frequency / 1E6);
                    break;
            }

            gbdb->core_registers[i].set_string(std::string(hex));
        }

        /* Get the global window lock   */
        pthread_mutex_lock(gbdb->gwl);

        gbdb->display_window.clear();
        /* Draw the table   */
        gbdb->mem_table.draw();

        for (i = 0; i < CPU_DEBUGGER_INDEX_ENM_SIZE; i++) {
            gbdb->core_register_names[i].draw();
            gbdb->core_registers[i].draw();
        }

        gbdb->display_window.display();

        pthread_mutex_unlock(gbdb->gwl);

        usleep( ((1.0/60.0) * 1000000));
    }
}

}    // namespace Debug