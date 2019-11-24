
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "game.hpp"

// Standard libraries
// ---------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include <wx/wx.h>

// Internal libraries
// ---------------------

#include "tile_manager.hpp"
#include "level_manager.hpp"
#include "game_map.hpp"
#include "splash_screen.hpp"
#include "ranking_screen.hpp"
#include "start_menu.hpp"
#include "pause_menu.hpp"
#include "game_over_menu.hpp"
#include "score_manager.hpp"
#include "game_saver.hpp"
#include "name_prompt.hpp"
#include <game_config.hpp>

using namespace bardadv::core;
using namespace bardadv::map;
using namespace bardadv::menus;
using namespace bardadv::characters;
using namespace bardadv::persistence;

// Attribute Initialization
// ---------------------------------------------------------------------------

Game* Game::instance = nullptr;

// Methods
// ---------------------------------------------------------------------------

Game::Game() : player(WINDOW_W/2, 100), fielEscudeiro(WINDOW_W/2 - 100, 100),
               hasEscudeiro{false} {
    instance = nullptr;

    gameState = UNINITIALIZED;
    gamePhase = NO_PHASE;

    LevelManager::getInstance()->getEntityManager().setBardo(&player);

    srand(time(0));
}

// ---------------------------------------------------------------------------

Game::~Game() {
    delete instance;
}

// ---------------------------------------------------------------------------

Game* Game::getInstance() {
    if(!instance) {
        instance = new Game;
    }
    return instance;
}

// ---------------------------------------------------------------------------

void Game::start() {

    if(gameState != UNINITIALIZED) return;

    std::cout << "[*] Creating window..." << std::endl;
    mainWindow.create(sf::VideoMode(1024, 768), "As aventuras do Bardo");
    TileManager::getInstance()->loadTileSet();

    gameState = SHOWING_SPLASH;
    gamePhase = NO_PHASE;

    player.initThreads();

    while(!isExiting()) {
        gameLoop();
    }

    stop();
}

// ---------------------------------------------------------------------------

Bardo& Game::getPlayer() {
     return player;
 }

 // ---------------------------------------------------------------------------

FielEscudeiro& Game::getFielEscudeiro() {
     return fielEscudeiro;
 }

 // ---------------------------------------------------------------------------

bool Game::getHasEscudeiro() {
     return hasEscudeiro;
 }

 // ---------------------------------------------------------------------------

void Game::setHasEscudeiro(bool b) {
     hasEscudeiro = b;
 }

 // ---------------------------------------------------------------------------

void Game::setPlayerName(std::string s) {
     playerName = s;
 }

 // ---------------------------------------------------------------------------

std::string Game::getPlayerName() {
     return playerName;
 }

 // ---------------------------------------------------------------------------

sf::RenderWindow& Game::getMainWindow() {
     return mainWindow;
 }

 // ---------------------------------------------------------------------------

void Game::setGamePhase(int p) {
     gamePhase = (Game::GamePhase) p;
 }

 // ---------------------------------------------------------------------------

Game::GameState Game::getGameState() {
     return gameState;
 }

// ---------------------------------------------------------------------------

bool Game::isExiting() {
    return gameState == EXITING;
}

// ---------------------------------------------------------------------------

void Game::gameLoop() {
    switch(gameState) {
        case SHOWING_START_MENU:
            showStartMenu();
            break;
        case SHOWING_PAUSE_MENU:
            showPauseMenu();
            break;
        case SHOWING_GAME_OVER_MENU:
            showGameOverMenu();
            break;
        case SHOWING_SPLASH:
            showSplashScreen();
            break;
        case SHOWING_RANKING_SCREEN:
            showRankingScreen();
            break;
        case PLAYING:
            processPlaying();
            break;
        default:;
    }
}

// ---------------------------------------------------------------------------

void Game::showSplashScreen() {
    SplashScreen splashScreen;

    splashScreen.show(mainWindow);
    gameState = SHOWING_START_MENU;
}

// ---------------------------------------------------------------------------

void Game::showRankingScreen() {
    RankingScreen rankingScreen;

    rankingScreen.show(mainWindow);
    reset();
    gameState = SHOWING_START_MENU;
}

// ---------------------------------------------------------------------------

void Game::showStartMenu() {
    StartMenu startMenu;

    startMenu.render(mainWindow);
    MenuCommand result = startMenu.getMenuResponse(mainWindow);
    switch(result) {
        case MenuCommand::EXIT:
            gameState = EXITING;
            break;
        case MenuCommand::PLAY_1_TABERNA:
            gameState = PLAYING;
            gamePhase = PHASE_1;
            hasEscudeiro = false;
            showNamePrompt();
            reset();
            LevelManager::getInstance()->changeLevel(gamePhase);
            break;
        case MenuCommand::PLAY_1_SALAO:
            gameState = PLAYING;
            gamePhase = PHASE_2;
            hasEscudeiro = false;
            showNamePrompt();
            reset();
            LevelManager::getInstance()->changeLevel(gamePhase);
            break;
        case MenuCommand::PLAY_2_TABERNA:
            gameState = PLAYING;
            gamePhase = PHASE_1;
            hasEscudeiro = true;
            showNamePrompt();
            reset();
            LevelManager::getInstance()->getEntityManager().setFielEscudeiro(&fielEscudeiro);
            LevelManager::getInstance()->changeLevel(gamePhase);
            break;
        case MenuCommand::PLAY_2_SALAO:
            gameState = PLAYING;
            gamePhase = PHASE_2;
            hasEscudeiro = true;
            showNamePrompt();
            reset();
            LevelManager::getInstance()->getEntityManager().setFielEscudeiro(&fielEscudeiro);
            LevelManager::getInstance()->changeLevel(gamePhase);
            break;
        case MenuCommand::RECOVER_SAVE:
            gameState = PLAYING;
            resume();
            break;
        default:;
    }

    refreshFrameTime();
}

// ---------------------------------------------------------------------------

void Game::showPauseMenu() {
    PauseMenu pauseMenu;

    pauseMenu.render(mainWindow);
    MenuCommand result = pauseMenu.getMenuResponse(mainWindow);
    switch(result) {
        case MenuCommand::EXIT:
            gameState = EXITING;
            break;
        case MenuCommand::RESUME:
            gameState = PLAYING;
            break;
        case MenuCommand::SAVE:
            GameSaver::getInstance()->saveState();
            break;
        default:;
    }

    refreshFrameTime();
}

// ---------------------------------------------------------------------------

void Game::showGameOverMenu() {
    GameOverMenu gameOverMenu;

    gameOverMenu.render(mainWindow);
    MenuCommand result = gameOverMenu.getMenuResponse(mainWindow);
    switch(result) {
        case MenuCommand::EXIT:
            gameState = EXITING;
            break;
        case MenuCommand::RETURN:
            reset();
            gameState = SHOWING_START_MENU;
            break;
        default:;
    }

    refreshFrameTime();
}

// ---------------------------------------------------------------------------

void Game::processPlaying() {
    sf::Event playingEvent;

    mainWindow.clear(sf::Color::Blue);

    while(gameState != EXITING && gameState != SHOWING_GAME_OVER_MENU && gameState != SHOWING_RANKING_SCREEN) {
        while(mainWindow.pollEvent(playingEvent)) {
            switch(playingEvent.type) {
                case sf::Event::KeyPressed:
                    if(playingEvent.key.code == sf::Keyboard::Key::Escape) {
                        gameState = SHOWING_PAUSE_MENU;
                        showPauseMenu();
                    }
                    break;
                case sf::Event::Closed:
                    gameState = EXITING;
                    break;
                default:
                    break;
            }
        }

        refreshFrameTime();
        mainWindow.clear(sf::Color::Blue);

        GameMap::getInstance()->draw();
        checkPlayerState();

        LevelManager::getInstance()->process(frameTime.asSeconds());
        ScoreManager::getInstance()->process();
        mainWindow.display();

    }
}

// ---------------------------------------------------------------------------

void Game::checkPlayerState() {
    if(player.getPosition().x < (GameMap::getInstance()->getSizeX() - 1)*TILE_SIZE && player.getPosition().x > (GameMap::getInstance()->getSizeX() - 2)*TILE_SIZE) {
        LevelManager::getInstance()->nextLevel();

        player.setPosX(WINDOW_W/2);
        player.setPosY(WINDOW_H/2);

        fielEscudeiro.setPosX(WINDOW_W/2 - 100);
        fielEscudeiro.setPosY(WINDOW_H/2);
    }

    if(!player.isAlive()) {
        gameState = SHOWING_GAME_OVER_MENU;
    }

    if(!fielEscudeiro.isAlive()) {
        hasEscudeiro = false;
        LevelManager::getInstance()->removeFielEscudeiro(&fielEscudeiro);
    }

}

// ---------------------------------------------------------------------------

void Game::refreshFrameTime() {
    frameTime = clock.restart();
}

// ---------------------------------------------------------------------------

void Game::stop() {
    mainWindow.close();
    gameState = EXITING;
}

// ---------------------------------------------------------------------------

json Game::store() {
    json j;

    j["entities"] = LevelManager::getInstance()->getEntityManager().store();
    j["score"] = ScoreManager::getInstance()->getScore();
    j["phase"] = gamePhase;
    j["name"] = playerName;

    return j;
}

// ---------------------------------------------------------------------------

void Game::resume() {
    if(GameSaver::getInstance()->recoverState()) {
        LevelManager::getInstance()->recoverLevel(gamePhase);
    }
    else {
        gamePhase = PHASE_1;
        LevelManager::getInstance()->changeLevel(gamePhase);
    }
}

// ---------------------------------------------------------------------------

void Game::reset() {
    player = Bardo(WINDOW_W/2, 200);
    player.initThreads();
    fielEscudeiro = FielEscudeiro(WINDOW_W/2 - 100, 200);

    ScoreManager::getInstance()->setScore(0);
}

// ---------------------------------------------------------------------------

void Game::winGame() {
    gameState = SHOWING_RANKING_SCREEN;
}

// ---------------------------------------------------------------------------

void Game::showNamePrompt() {
    wxTheApp->OnInit();
    wxTheApp->OnRun();
    wxTheApp->OnExit();
}
