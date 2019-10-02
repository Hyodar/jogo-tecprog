
#ifndef GAME_H_
#define GAME_H_

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game {

    public: 
        Game();

        static void start();

    private:

        static bool isExiting();
        static void gameLoop();

        static void showSplashScreen();
        static void showMenu();

        enum GameState {
            uninitialized,
            showingSplash,
            paused,
            showingMenu,
            playing,
            exiting
        };

        static GameState gameState;
        static sf::RenderWindow mainWindow;
};

#endif // GAME_H_