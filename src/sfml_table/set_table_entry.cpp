#include <sfml_table.h>

void SFML_Table::set_table_entry(uint8_t col, uint8_t row, std::string s) {

    /* Make sure the selected index is sane */
    if (row >= table_entries.size()) {
        return;
    }

    if (col >= table_entries[0].size()) {
        return;
    }

    table_entries[row][col].set_string(s);
}