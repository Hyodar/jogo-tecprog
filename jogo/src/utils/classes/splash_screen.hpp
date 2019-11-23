
#ifndef SPLASH_SCREEN_HPP_
#define SPLASH_SCREEN_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace bardadv::menus {

class SplashScreen {

public:
    SplashScreen();
    ~SplashScreen();
    void show(sf::RenderWindow& window);

private:
    void processLoop(sf::RenderWindow& window);
};

}

#endif // SPLASH_SCREEN_HPP_
