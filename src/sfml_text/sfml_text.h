#ifndef SFML_TEXT_H
#define SFML_TEXT_H

#include <SFML/Graphics.hpp>
#include <string>

class SFML_Text {
    public:
    SFML_Text();
    SFML_Text(sf::RenderWindow *scr, sf::Font *lf, int16_t x, int16_t y, int16_t len, int16_t hgt);

    void configure(sf::RenderWindow *scr, sf::Font *lf, int16_t x, int16_t y, int16_t len, int16_t hgt);

    void draw();

    inline void
      set_text_size(uint8_t s) {
        text_size = s;
    }

    inline void
      set_string(std::string s) {
        text_string = s;
    }

    inline void
      clear_string() {
        text_string = "";
    }

    inline void
      disable_border() {
        draw_border = false;
    }

    inline void
      enable_border() {
        draw_border = true;
    }

    private:
    sf::RenderWindow *screen;
    sf::Font *        loaded_font;

    bool draw_border;

    int16_t x_pos;
    int16_t y_pos;
    int16_t length;
    int16_t height;
    uint8_t text_size;

    std::string text_string;
};

#endif