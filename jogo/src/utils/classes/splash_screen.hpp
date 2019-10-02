
#ifndef SPLASH_SCR_H_
#define SPLASH_SCR_H_

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

#endif // SPLASH_SCR_H_