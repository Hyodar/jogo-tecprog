
#ifndef SPLASH_SCR_H_
#define SPLASH_SCR_H_

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class SplashScreen {

    public:
        void show(sf::RenderWindow& window);

    private:
        void processLoop(sf::RenderWindow& window);
};

#endif // SPLASH_SCR_H_