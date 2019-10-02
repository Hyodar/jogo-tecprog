
#ifndef GAME_H_
#define GAME_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game {

    public: 
        Game();

        static void start();

    private:
        enum GameState {
            uninitialized,
            showingSplash,
            paused,
            showingMenu,
            showingPreferences,
            playing,
            exiting
        };

        static GameState gameState;
        static sf::RenderWindow mainWindow;

        static void stop();
        static bool isExiting();

        static void gameLoop();

        static void showSplashScreen();
        static void showMenu();

        static void processPlaying(sf::Event& e);

};

#endif // GAME_H_
