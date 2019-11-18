
#ifndef GAME_HPP_
#define GAME_HPP_

#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"
#include "database_model.hpp"

class Game : public DatabaseModel {

public:

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

    Bardo& getPlayer();
    FielEscudeiro& getFielEscudeiro();

    bool getHasEscudeiro();
    void setHasEscudeiro(bool b);

    void setPlayerName(std::string s);
    std::string getPlayerName();

    sf::RenderWindow& getMainWindow();

    void setGamePhase(int p);
    Game::GameState getGameState();

    json store();
    void resume();

    void reset();
    void stop();

    void winGame();

private:
    Game();

    static Game* instance;

    std::string playerName;

    Bardo player;
    FielEscudeiro fielEscudeiro;
    bool hasEscudeiro;

    GameState gameState;
    GamePhase gamePhase;
    sf::RenderWindow mainWindow;

    sf::Clock clock;
    sf::Time frameTime;

    int score;

    bool isExiting();
    void refreshFrameTime();

    void gameLoop();

    void showSplashScreen();
    void showRankingScreen();
    void showStartMenu();
    void showPauseMenu();
    void showGameOverMenu();

    void showNamePrompt();

    void processPlaying();
    void checkPlayerState();

};

#endif // GAME_HPP_
