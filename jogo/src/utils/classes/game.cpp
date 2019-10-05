
#include "game.hpp"

#include <iostream>
#include <string>
#include <constants.hpp>

#include "tile_manager.hpp"
#include "game_map.hpp"
#include "splash_screen.hpp"
#include "main_menu.hpp"

// -------------------------------------------------------------

Game::GameState Game::gameState = uninitialized;
Game::GamePhase Game::gamePhase = noPhase;
sf::RenderWindow Game::mainWindow;
Player Game::player(windowW/2, 100);

Game::Game() {
    
}

// -------------------------------------------------------------

void Game::start() {

    if(gameState != uninitialized) return;

    std::cout << "[*] Creating window..." << std::endl;
    mainWindow.create(sf::VideoMode(1024, 768), "Game title");
    TileManager::loadTileSet();
    GameMap::loadMap();
    
    gameState = showingSplash;
    gamePhase = noPhase;

    while(!isExiting()) {
        gameLoop();
    }

    stop();
}

// -------------------------------------------------------------

bool Game::isExiting() {
    return gameState == exiting;
}

// -------------------------------------------------------------

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
    }
}

// -------------------------------------------------------------

void Game::showSplashScreen() {
    SplashScreen splashScreen;

    splashScreen.show(mainWindow);
    gameState = showingMenu;
}

// -------------------------------------------------------------

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
    }
}

// -------------------------------------------------------------

void Game::processPlaying() {
    sf::Event playingEvent;
    sf::Clock clock;

    mainWindow.clear(sf::Color(0, 0, 255));
    GameMap::loadMap();

    while(mainWindow.isOpen()) {
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
                    stop();
                    break;
            }
        }
        if(gameState != paused) {
            sf::Time frameTime = clock.restart();

            mainWindow.clear(sf::Color(0, 0, 255));
            player.update(frameTime.asSeconds());
            
            GameMap::drawTiles(player.getPosition());
            player.render(mainWindow);

            mainWindow.display();
        }
    }
}

// -------------------------------------------------------------

void Game::stop() {
    mainWindow.close();
}
