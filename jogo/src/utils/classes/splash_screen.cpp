
#include "splash_screen.hpp"
#include <iostream>

// -------------------------------------------------------------

SplashScreen::SplashScreen() : texture() {
    if(!texture.loadFromFile("resources/splash_screen.png")) {
        std::cout << "[!] Could not load splash screen image!";
        return;
    }
}

void SplashScreen::show(sf::RenderWindow& renderWindow) {
    sf::Sprite sprite(texture);

    renderWindow.draw(sprite);
    renderWindow.display();

    processLoop(renderWindow);
}

void SplashScreen::processLoop(sf::RenderWindow& renderWindow) {
    sf::Event event;

    while(true) {
        while(renderWindow.pollEvent(event)) {

            switch(event.type) {
                case sf::Event::MouseButtonPressed:
                case sf::Event::KeyPressed:
                case sf::Event::Closed:
                    return;
                
            }
        }
    }
}
