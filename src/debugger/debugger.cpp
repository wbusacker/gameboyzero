#include <debugger.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace Debug {

static uint8_t search_depth = 0;

uint8_t find_file(const char *start_dir, const char *file_name, char *full_path) {

    if (search_depth == 10) {
        printf("Warning! Search Depth Exceeded!\n");
        return 0;
    }

    /* Search all files in the current directory    */

    char search_buffer[Debug::MAX_FILE_NAME_LEN];

    memset(search_buffer, 0, Debug::MAX_FILE_NAME_LEN);

    DIR *          directory_handle;
    struct dirent *dir;
    directory_handle = opendir(start_dir);
    if (directory_handle == NULL) {
        printf("Search directory %s cannot be read\n", start_dir);
        fflush(stdout);
        return 0;
    }

    dir = readdir(directory_handle);

    while (dir != NULL) {

        /* Make sure the entry is a file    */
        if (dir->d_type == DT_REG) {

            /* Check if the file name matches   */
            if (strcmp(dir->d_name, file_name) == 0) {
                /* Place the fully qualified path into full_path    */
                strcpy(full_path, start_dir);
                strcat(full_path, dir->d_name);

                closedir(directory_handle);

                return 1;
            }
        }

        /* If the entry is a directory, traverse    */
        if (dir->d_type == DT_DIR) {

            /* If directory is . or .., ignore  */
            if ((strcmp(".", dir->d_name) != 0) && (strcmp("..", dir->d_name) != 0)) {
                strcpy(search_buffer, start_dir);
                strcat(search_buffer, dir->d_name);
                strcat(search_buffer, "/");

                uint8_t status;
                status = find_file(search_buffer, file_name, full_path);
                if (status != 0) {

                    closedir(directory_handle);
                    return 1;
                }
            }
        }

        /* Iterate to the next item */
        dir = readdir(directory_handle);
    }

    closedir(directory_handle);
    return 0;
}

GB_Debugger::GB_Debugger(CPU::LR35902 *cc, pthread_mutex_t *global_window_lock) {
    cpu_core = cc;
    gwl      = global_window_lock;

    pthread_mutex_lock(gwl);

    display_window.create(sf::VideoMode(Debug::DEBUG_WINDOWS_WIDTH, DEBUG_WINDOWS_HEIGHT), "Gameboy Zero Memory Map");

    /* Try to find the font */
    char font_name[Debug::MAX_FILE_NAME_LEN];
    memset(font_name, 0, Debug::MAX_FILE_NAME_LEN);

    uint8_t status;
    status = find_file("/usr/share/fonts/", "DejaVuSans.ttf", font_name);
    if (status == 0) {
        printf("Failed to find font\n");
        fflush(stdout);
    } else {
        printf("Found Font at %s\n", font_name);
        fflush(stdout);
    }

    /* Load Dejavu Font     */
    if (! loaded_font.loadFromFile(font_name)) {
        printf("Font loading failed, disabling debugger\n");
        fflush(stdout);
        display_window.close();
        return;
    }

    mem_table.configure(&display_window, &loaded_font, 0, 0, DEBUG_WINDOWS_WIDTH, DEBUG_WINDOWS_HEIGHT);

    mem_table.set_table_size(MEMORY_TABLE_HEIGHT + 1, MEMORY_TABLE_WIDTH + 1);

    uint16_t i;
    char     hex[5];
    for (i = 0; i < MEMORY_TABLE_WIDTH; i++) {
        sprintf(hex, "%02X", i);
        fflush(stdout);
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
    core_register_names[INTERRUPT_ENABLED].set_string(std::string("INTERRUPT_ENABLED"));
    core_register_names[STALL_PROCESSOR].set_string(std::string("STALL_PROCESSOR"));
    core_register_names[CPU_CYCLES].set_string(std::string("CPU_CYCLES"));
    core_register_names[CPU_FREQUENCY].set_string(std::string("CPU_FREQUENCY"));

    pthread_mutex_unlock(gwl);

    pthread_create(&frame_render_thread_handle, NULL, &GB_Debugger::render_thread, this);
}

}    // namespace Debug