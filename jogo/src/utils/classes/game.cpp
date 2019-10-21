
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
#include "game_map.hpp"
#include "splash_screen.hpp"
#include "main_menu.hpp"

// Attribute initialization
// ---------------------------------------------------------------------------

Game::GameState Game::gameState = uninitialized;
Game::GamePhase Game::gamePhase = noPhase;

sf::Clock Game::clock;
sf::Time Game::frameTime;

sf::RenderWindow Game::mainWindow;
Player Game::player(windowW/2, 100);

// Methods
// ---------------------------------------------------------------------------

Game::Game() {

}

// ---------------------------------------------------------------------------

void Game::start() {

    if(gameState != uninitialized) return;

    std::cout << "[*] Creating window..." << std::endl;
    mainWindow.create(sf::VideoMode(1024, 768), "Game title");
    TileManager::loadTileSet();

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
        case showingMenu:
            showMenu();
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
    gameState = showingMenu;
}

// ---------------------------------------------------------------------------

void Game::showMenu() {
    MainMenu mainMenu;

    MainMenu::MenuResult result = mainMenu.show(mainWindow);
    switch(result) {
        case MainMenu::exit:
            gameState = exiting;
            break;
        case MainMenu::play:
            gameState = playing;
            gamePhase = phase1;
            break;
        default:;
    }

    refreshFrameTime();
}

// ---------------------------------------------------------------------------

void Game::processPlaying() {
    sf::Event playingEvent;

    mainWindow.clear(sf::Color::Blue);
    GameMap::loadMap();

    while(gameState != exiting) {
        while(mainWindow.pollEvent(playingEvent)) {
            switch(playingEvent.type) {
                case sf::Event::KeyPressed:
                    if(playingEvent.key.code == sf::Keyboard::Key::Escape) {
                        gameState = paused;
                        showMenu();
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
        player.update(frameTime.asSeconds());

        GameMap::draw(player.getPosition());
        player.render(mainWindow);

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
