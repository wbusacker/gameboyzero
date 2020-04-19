#include <sfml_table.h>

void
SFML_Table::set_column_headers(uint8_t column_num, std::string header) {

    if (column_num >= table_entries[0].size()) {
        return;
    }

    column_headers[column_num].set_string(header);

}