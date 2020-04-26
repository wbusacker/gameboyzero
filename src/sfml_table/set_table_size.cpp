#include <sfml_table.h>

void SFML_Table::set_table_size(uint8_t rows, uint8_t columns) {

    /* Configure each entry in the table */
    uint8_t row;
    uint8_t col;
    /* The zeroth row of the table is for the headers */
    for (row = 1; row <= rows; row++) {
        std::vector<SFML_Text> col_v;
        for (col = 0; col < columns; col++) {

            /* Build a new SFML_Text object to place in the vector */

            SFML_Text entry;

            entry.configure(screen,
                            loaded_font,
                            x_pos + (col * TABLE_ENTRY_WIDTH),
                            y_pos + (row * TABLE_ENTRY_HEIGHT),
                            TABLE_ENTRY_WIDTH,
                            TABLE_ENTRY_HEIGHT);

            entry.set_text_size(TABLE_ENTRY_TEXT_SIZE);

            entry.disable_border();
            entry.set_string(std::string("--"));

            col_v.push_back(entry);
        }
        table_entries.push_back(col_v);
    }

    /* Build headers */
    row = 0;
    for (col = 0; col < columns; col++) {
        SFML_Text entry;
        entry.configure(screen,
                        loaded_font,
                        x_pos + (col * TABLE_ENTRY_WIDTH),
                        y_pos + (row * TABLE_ENTRY_HEIGHT),
                        TABLE_ENTRY_WIDTH,
                        TABLE_ENTRY_HEIGHT);
        entry.set_text_size(TABLE_ENTRY_TEXT_SIZE);

        entry.disable_border();
        entry.set_string(std::string("HDR"));
        column_headers.push_back(entry);
    }
}