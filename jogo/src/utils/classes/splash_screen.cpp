
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "splash_screen.hpp"

// Standard libraries
// ---------------------

#include <iostream>

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"

using namespace bardadv::core;
using namespace bardadv::menus;

// Methods
// ---------------------------------------------------------------------------

SplashScreen::SplashScreen() {

}

//----------------------------------------------------------------------------

SplashScreen::~SplashScreen() {

}


// ---------------------------------------------------------------------------

void SplashScreen::show(sf::RenderWindow& renderWindow) {
    sf::Sprite sprite(*(GraphicsManager::getInstance()->getSplashScreenTexture()));

    renderWindow.draw(sprite);
    renderWindow.display();

    processLoop(renderWindow);
}

// ---------------------------------------------------------------------------

void SplashScreen::processLoop(sf::RenderWindow& renderWindow) {
    sf::Event event;

    while(true) {
        while(renderWindow.pollEvent(event)) {

            switch(event.type) {
                case sf::Event::MouseButtonPressed:
                case sf::Event::KeyPressed:
                case sf::Event::Closed:
                    return;
                default:;

            }
        }
    }
}
