
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
    Bardo& getPlayer() { return player; }
    sf::RenderWindow& getMainWindow() { return mainWindow; }

private:
    Game();
    
    enum GameState {
        uninitialized,
        showingSplash,
        paused,
        showingStartMenu,
        showingPauseMenu,
        playing,
        exiting
    };

    enum GamePhase {
        noPhase = -1,
        phase1 = 0,
        phase2 = 1
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
    void showPauseMenu();
    void showStartMenu();

    void processPlaying();

};

#endif // GAME_HPP_
