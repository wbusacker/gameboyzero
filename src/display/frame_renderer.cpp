#include <display.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

namespace Graphics {

void *Display::frame_renderer(void *arg) {

    Graphics::Display *disp = reinterpret_cast<Graphics::Display *>(arg);

    /* Acquire GWL before doing anything SFML   */

    pthread_mutex_lock(disp->gwl);
    
    printf("Preparing main display\n");
    fflush(stdout);

    sf::RenderWindow window;
    // sf::Image        frame_image;
    sf::Texture      texture;
    sf::Sprite       sprite;
    sf::Color        pixel_color(0, 0, 0, 255);
    sf::Event        event;

    window.create(sf::VideoMode(DISPLAY_COL_COUNT * DISPLAY_PIXEL_SIZE, DISPLAY_ROW_COUNT * DISPLAY_PIXEL_SIZE),
                  "Gameboy Zero Display");

    // frame_image.create(Graphics::DISPLAY_WIDTH, Graphics::DISPLAY_HEIGHT, sf::Color::Green);

    sprite.scale(Graphics::DISPLAY_PIXEL_SIZE, Graphics::DISPLAY_PIXEL_SIZE);

    pthread_mutex_unlock(disp->gwl);

    while (! disp->request_destroy) {

        // sem_wait(&(disp->frame_sync));
        while (disp->new_frame == false)
            ;
        disp->new_frame = false;

        texture.loadFromImage(disp->frame_image);

        sprite.setTexture(texture);

        pthread_mutex_lock(disp->gwl);

        window.clear();
        window.draw(sprite);
        window.display();

        /* Process events built up  */
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    disp->request_destroy = true;
                    return NULL;
                case sf::Event::Resized:
                    break;
                case sf::Event::LostFocus:
                    break;
                case sf::Event::GainedFocus:
                    break;
                case sf::Event::TextEntered:
                    break;
                case sf::Event::KeyPressed:
                    break;
                case sf::Event::KeyReleased:
                    break;
                case sf::Event::MouseWheelMoved:
                    break;
                case sf::Event::MouseWheelScrolled:
                    break;
                case sf::Event::MouseButtonPressed:
                    break;
                case sf::Event::MouseButtonReleased:
                    break;
                case sf::Event::MouseMoved:
                    break;
                case sf::Event::MouseEntered:
                    break;
                case sf::Event::MouseLeft:
                    break;
                case sf::Event::JoystickButtonPressed:
                    break;
                case sf::Event::JoystickButtonReleased:
                    break;
                case sf::Event::JoystickMoved:
                    break;
                case sf::Event::JoystickConnected:
                    break;
                case sf::Event::JoystickDisconnected:
                    break;
                case sf::Event::TouchBegan:
                    break;
                case sf::Event::TouchMoved:
                    break;
                case sf::Event::TouchEnded:
                    break;
                case sf::Event::SensorChanged:
                    break;
                case sf::Event::Count:
                    break;
            }
        }

        pthread_mutex_unlock(disp->gwl);
        
    }

    return NULL;
}

}    // namespace Graphics