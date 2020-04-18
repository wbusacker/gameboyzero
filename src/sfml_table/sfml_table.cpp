#include <sfml_table.h>
#include <stdlib.h>

SFML_Table::SFML_Table() {
}

SFML_Table::SFML_Table(sf::RenderWindow *scr, sf::Font *lf, int16_t x, int16_t y, int16_t len, int16_t hgt) {
    configure(scr, lf, x, y, len, hgt);
}

void
SFML_Table::configure(sf::RenderWindow *scr, sf::Font *lf, int16_t x, int16_t y, int16_t len, int16_t hgt) {
    x_pos  = x;
    y_pos  = y;
    length = len;
    height = hgt;

    screen      = scr;
    loaded_font = lf;

    /* Configure the table title */
    table_title.set_string("Default Title");

    table_title.configure(scr, lf, x, y, len, TABLE_ENTRY_HEIGHT);
}