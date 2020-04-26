#include <sfml_table.h>

void SFML_Table::draw() {

    /* Draw the title */
    table_title.draw();

    uint8_t col;
    for (col = 0; col < column_headers.size(); col++) {
        column_headers[col].draw();
    }

    uint8_t row;
    for (row = 0; row < table_entries.size(); row++) {
        for (col = 0; col < table_entries[row].size(); col++) {
            table_entries[row][col].draw();
        }
    }
}