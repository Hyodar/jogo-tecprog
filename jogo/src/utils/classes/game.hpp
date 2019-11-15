
#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"
#include "database_model.hpp"

class Game : public DatabaseModel {

enum GameState {
    uninitialized,
    showingSplash,
    paused,
    showingStartMenu,
    showingPauseMenu,
    showingGameOverMenu,
    showingRankingMenu,
    playing,
    exiting
};

enum GamePhase {
    noPhase = -1,
    phase1 = 0,
    phase2 = 1
};

public:
    ~Game();
    static Game* getInstance();
    
    void start();
    
    Bardo& getPlayer() { return player; }
    FielEscudeiro& getFielEscudeiro() { return fielEscudeiro; }

    bool getHasEscudeiro() { return hasEscudeiro; }
    void setHasEscudeiro(bool b) { hasEscudeiro = b; }

    sf::RenderWindow& getMainWindow() { return mainWindow; }

    void setGamePhase(int p) { gamePhase = (Game::GamePhase) p; }

    json store();
    void resume();

private:
    Game();

    static Game* instance;

    Bardo player;
    FielEscudeiro fielEscudeiro;
    bool hasEscudeiro;

    GameState gameState;
    GamePhase gamePhase;
    sf::RenderWindow mainWindow;

    sf::Clock clock;
    sf::Time frameTime;

    int score;

    void stop();
    bool isExiting();
    void refreshFrameTime();

    void gameLoop();

    void showSplashScreen();
    void showPauseMenu();
    void showStartMenu();

    void processPlaying();
    void checkPlayerState();

};

#endif // GAME_HPP_
