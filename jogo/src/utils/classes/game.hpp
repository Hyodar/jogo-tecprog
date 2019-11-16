
#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"
#include "database_model.hpp"

class Game : public DatabaseModel {

enum GameState {
    UNINITIALIZED,
    SHOWING_SPLASH,
    PAUSED,
    SHOWING_START_MENU,
    SHOWING_PAUSE_MENU,
    SHOWING_GAME_OVER_MENU,
    SHOWING_RANKING_SCREEN,
    PLAYING,
    EXITING
};

enum GamePhase {
    NO_PHASE = -1,
    PHASE_1 = 0,
    PHASE_2 = 1
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
    void reset();
    void winGame();

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
    void showRankingScreen();
    void showStartMenu();
    void showPauseMenu();
    void showGameOverMenu();

    void processPlaying();
    void checkPlayerState();

};

#endif // GAME_HPP_
