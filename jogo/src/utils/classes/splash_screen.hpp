
#ifndef SPLASH_SCREEN_HPP_
#define SPLASH_SCREEN_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class SplashScreen {

public:
    SplashScreen();
    void show(sf::RenderWindow& window);

private:
    sf::Texture texture;
    void processLoop(sf::RenderWindow& window);
};

#endif // SPLASH_SCREEN_HPP_