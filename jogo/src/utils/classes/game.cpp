
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "game.hpp"

// Standard libraries
#include <iostream>
#include <string>
#include <constants.hpp>

// Internal libraries
#include "tile_manager.hpp"
#include "level_manager.hpp"
#include "game_map.hpp"
#include "splash_screen.hpp"
#include "start_menu.hpp"
#include "pause_menu.hpp"

#include "spike.hpp"

// Attribute Initialization
// ---------------------------------------------------------------------------

Game* Game::instance = nullptr;

// Methods
// ---------------------------------------------------------------------------

Game::Game() : player(windowW/2, 100), fielEscudeiro(windowW/2 - 100, 100),
               hasEscudeiro{false} {
    instance = nullptr;

    gameState = uninitialized;
    gamePhase = noPhase;

    LevelManager::getInstance()->getEntityManager().setBardo(&player);
    LevelManager::getInstance()->getEntityManager().setFielEscudeiro(&fielEscudeiro);
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

    if(gameState != uninitialized) return;

    std::cout << "[*] Creating window..." << std::endl;
    mainWindow.create(sf::VideoMode(1024, 768), "Game title");
    TileManager::getInstance()->loadTileSet();

    gameState = showingSplash;
    gamePhase = noPhase;

    while(!isExiting()) {
        gameLoop();
    }

    stop();
}

// ---------------------------------------------------------------------------

bool Game::isExiting() {
    return gameState == exiting;
}

// ---------------------------------------------------------------------------

void Game::gameLoop() {
    switch(gameState) {
        case showingStartMenu:
            showStartMenu();
            break;
        case showingPauseMenu:
            showPauseMenu();
            break;
        case showingSplash:
            showSplashScreen();
            break;
        case playing:
            processPlaying();
            break;
        default:;
    }
}

// ---------------------------------------------------------------------------

void Game::showSplashScreen() {
    SplashScreen splashScreen;

    splashScreen.show(mainWindow);
    gameState = showingStartMenu;
}

// ---------------------------------------------------------------------------

void Game::showStartMenu() {
    StartMenu startMenu;

    StartMenu::MenuResult result = startMenu.show(mainWindow);
    switch(result) {
        case StartMenu::exit:
            gameState = exiting;
            break;
        case StartMenu::play1tab:
            gameState = playing;
            gamePhase = phase1;
            LevelManager::getInstance()->changeLevel(gamePhase);
            break;
        case StartMenu::play1sal:
            gameState = playing;
            gamePhase = phase2;
            LevelManager::getInstance()->changeLevel(gamePhase);
            break;
        case StartMenu::play2tab:
            gameState = playing;
            gamePhase = phase1;
            LevelManager::getInstance()->getEntityManager().setHasEscudeiro(true);
            LevelManager::getInstance()->changeLevel(gamePhase);
            break;
        case StartMenu::play2sal:
            gameState = playing;
            gamePhase = phase2;
            hasEscudeiro = true;
            LevelManager::getInstance()->getEntityManager().setHasEscudeiro(true);
            LevelManager::getInstance()->changeLevel(gamePhase);
            break;
        case StartMenu::resume:
            // TODO logic
            break;
        default:;
    }
    // TODO - talvez colocar aqui o negocio pra pegar o numero de jogadores

    refreshFrameTime();
}

// ---------------------------------------------------------------------------

void Game::showPauseMenu() {
    PauseMenu pauseMenu;

    PauseMenu::MenuResult result = pauseMenu.show(mainWindow);
    switch(result) {
        case PauseMenu::exit:
            gameState = exiting;
            break;
        case PauseMenu::resume:
            gameState = playing;
            break;
        case PauseMenu::save:
            // TODO - logic
            break;
        default:;
    }

    refreshFrameTime();
}

// ---------------------------------------------------------------------------

void Game::processPlaying() {
    sf::Event playingEvent;

    mainWindow.clear(sf::Color::Blue);

    while(gameState != exiting) {
        while(mainWindow.pollEvent(playingEvent)) {
            switch(playingEvent.type) {
                case sf::Event::KeyPressed:
                    if(playingEvent.key.code == sf::Keyboard::Key::Escape) {
                        gameState = showingPauseMenu;
                        showPauseMenu();
                    }
                    break;
                case sf::Event::KeyReleased:
                    break;
                case sf::Event::Closed:
                    gameState = exiting;
                    break;
                default:
                    break;
            }
        }

        refreshFrameTime();
        mainWindow.clear(sf::Color(0, 0, 255));

        GameMap::getInstance()->draw(player.getPosition());
        player.render(mainWindow);
        if(hasEscudeiro) fielEscudeiro.render(mainWindow);
        player.updateStartPosition(0);

        if(player.getPosition().x == 48*TILE_SIZE) {
            LevelManager::getInstance()->nextLevel();

            player.setPosX(windowW/2);
        }
        
        LevelManager::getInstance()->process(frameTime.asSeconds());
        mainWindow.display();
    }
}

// ---------------------------------------------------------------------------

void Game::refreshFrameTime() {
    frameTime = clock.restart();
}

// ---------------------------------------------------------------------------

void Game::stop() {
    mainWindow.close();
}
