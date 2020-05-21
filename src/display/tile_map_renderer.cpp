#include <display.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace Graphics {

void *Display::tile_map_renderer(void *arg) {

    Graphics::Display *disp = reinterpret_cast<Graphics::Display *>(arg);

    /* Acquire GWL before doing anything SFML   */

    Monotonic rate_limit(0.1);

    pthread_mutex_lock(disp->gwl);

    printf("Preparing Tile Map Buffer Display\n");
    fflush(stdout);

    sf::RenderWindow window;
    sf::Image        tile_map_image;
    sf::Texture      texture;
    sf::Sprite       sprite;
    sf::Color        pixel_color(0, 0, 0, 255);

    window.create(sf::VideoMode(Graphics::DISPLAY_WIDTH * Graphics::DISPLAY_PIXEL_SIZE,
                                Graphics::DISPLAY_HEIGHT * Graphics::DISPLAY_PIXEL_SIZE),
                  "Tile Map");

    tile_map_image.create(Graphics::DISPLAY_WIDTH, Graphics::DISPLAY_HEIGHT, sf::Color::Green);

    sprite.scale(Graphics::DISPLAY_PIXEL_SIZE, Graphics::DISPLAY_PIXEL_SIZE);

    pthread_mutex_unlock(disp->gwl);

    while (! disp->request_destroy) {

        rate_limit.rate_limit();

        uint16_t tile_row;
        uint16_t tile_col;

        for (tile_row = 0; tile_row < Graphics::TILES_PER_COL; tile_row++) {
            for (tile_col = 0; tile_col < Graphics::TILES_PER_ROW; tile_col++) {
                /* Get the Pattern Number                       */
                uint16_t tile_map_index     = tile_col + (tile_row * Graphics::TILES_PER_ROW);
                uint16_t tile_map_addr      = disp->lcdc.bg_tile_map + tile_map_index;
                int16_t  tile_pattern_index = disp->main_memory.fetch_addr(tile_map_addr);

                /* Check if we're in signed index mode          */
                if (disp->lcdc.bg_window_tile_data == Graphics::TILE_PATTERN_BUFFER_1) {
                    /* Sign extend the pattern index if needed  */
                    if ((tile_pattern_index & 0x80) == 0x80) {
                        tile_pattern_index |= 0xFF00;
                    }
                }

                /* Get the address of the tile pattern          */
                uint16_t tile_pattern_addr =
                  disp->lcdc.bg_window_tile_data + (tile_pattern_index * Graphics::TILE_PATTERN_SIZE);

                /* Iterate through the pattern pixels           */
                uint8_t pattern_line;
                uint8_t pattern_column;
                for (pattern_line = 0; pattern_line < Graphics::TILE_SIZE; pattern_line++) {
                    uint8_t pixel_lsb;
                    uint8_t pixel_msb;

                    pixel_lsb = disp->main_memory.fetch_addr(tile_pattern_addr + (pattern_line * 2));
                    pixel_msb = disp->main_memory.fetch_addr(tile_pattern_addr + (pattern_line * 2) + 1);

                    for (pattern_column = 0; pattern_column < Graphics::TILE_SIZE; pattern_column++) {
                        uint8_t pixel_value;

                        /* Calculate the bit value  */
                        pixel_value = (pixel_lsb >> (7 - pattern_column)) & 0b1;
                        pixel_value |= ((pixel_msb >> (7 - pattern_column)) & 0b1) << 1;

                        /* Assert the default pallete values    */
                        uint8_t common_color;
                        switch (pixel_value & 0b11) {
                            case 0:
                                common_color = 0xFF;
                                break;
                            case 1:
                                common_color = 0xAA;
                                break;
                            case 2:
                                common_color = 0x55;
                                break;
                            case 3:
                                common_color = 0x00;
                                break;
                        }

                        pixel_color.r = common_color;
                        pixel_color.g = common_color;
                        pixel_color.b = common_color;

                        tile_map_image.setPixel((Graphics::TILE_SIZE * tile_col) + pattern_column,
                                                (Graphics::TILE_SIZE * tile_row) + pattern_line,
                                                pixel_color);
                    }
                }
            }
        }

        texture.loadFromImage(tile_map_image);

        sprite.setTexture(texture);

        pthread_mutex_lock(disp->gwl);

        window.clear();

        window.draw(sprite);

        window.display();

        pthread_mutex_unlock(disp->gwl);
    }

    return NULL;
}

}    // namespace Graphics