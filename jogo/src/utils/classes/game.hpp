
#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "bardo.hpp"

class Game {

public:
    ~Game();
    static Game* getInstance();
    
    void start();
    sf::RenderWindow& getMainWindow() { return mainWindow; }

private:
    Game();
    
    enum GameState {
        uninitialized,
        showingSplash,
        paused,
        showingMenu,
        showingPreferences,
        playing,
        exiting
    };

    enum GamePhase {
        noPhase,
        phase1,
        phase2,
        boss
    };

    static Game* instance;

    Bardo player;

    GameState gameState;
    GamePhase gamePhase;
    sf::RenderWindow mainWindow;

    sf::Clock clock;
    sf::Time frameTime;

    void stop();
    bool isExiting();
    void refreshFrameTime();

    void gameLoop();

    void showSplashScreen();
    void showMenu();

    void processPlaying();

};

#endif // GAME_HPP_
