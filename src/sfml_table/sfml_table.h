#ifndef SFML_TABLE_H
#define SFML_TABLE_H

#include <SFML/Graphics.hpp>
#include <sfml_text.h>
#include <string>

#define TABLE_ENTRY_WIDTH     70
#define TABLE_ENTRY_HEIGHT    20
#define TABLE_ENTRY_TEXT_SIZE 10

class SFML_Table {
    public:
    SFML_Table();
    SFML_Table(sf::RenderWindow *scr, sf::Font *lf, int16_t x, int16_t y, int16_t len, int16_t hgt);

    void configure(sf::RenderWindow *scr, sf::Font *lf, int16_t x, int16_t y, int16_t len, int16_t hgt);

    inline void
    set_table_title(std::string title) {
        table_title.set_string(title);
    }

    void set_table_size(uint8_t rows, uint8_t columns);

    void draw();

    void set_column_headers(uint8_t column_num, std::string header);
    void set_table_entry(uint8_t col, uint8_t row, std::string s);

    private:
    sf::RenderWindow *screen;
    sf::Font *        loaded_font;

    int16_t x_pos;
    int16_t y_pos;
    int16_t length;
    int16_t height;

    SFML_Text table_title;

    std::vector<SFML_Text>              column_headers;
    std::vector<std::vector<SFML_Text>> table_entries;
};

#endif