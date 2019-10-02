
#include "game.hpp"

#include <iostream>
#include <string>

#include "splash_screen.hpp"
#include "main_menu.hpp"

// -------------------------------------------------------------

Game::GameState Game::gameState = uninitialized;
sf::RenderWindow Game::mainWindow;
Player Game::player(100, 100);

Game::Game() {
    
}

// -------------------------------------------------------------

void Game::start() {

    if(gameState != uninitialized) return;

    std::cout << "Creating window" << std::endl;
    mainWindow.create(sf::VideoMode(1024, 768), "Game title");
    gameState = showingSplash;

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

    sf::Event event;
    while(mainWindow.pollEvent(event)) {
        switch(gameState) {            
            case showingMenu:
                showMenu();
                break;
            case showingSplash:
                showSplashScreen();
                break;
            case playing:
                sf::Event playingEvent;
                while(mainWindow.pollEvent(playingEvent)) {
                    
                    mainWindow.clear(sf::Color(0, 0, 255));
                    player.render(mainWindow);
                    mainWindow.display();

                    switch(playingEvent.type) {
                        case sf::Event::KeyPressed:
                            std::cout << "Key pressed. \n";
                            player.move(playingEvent.key.code);
                            break;
                        case sf::Event::Closed:
                            gameState = exiting;
                            break;
                    }
                }
            break;
        }
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
            break;
    }
}

// -------------------------------------------------------------

void Game::processPlaying(sf::Event& event) {
    //mainWindow.clear(sf::Color(0, 255, 0));

}

// -------------------------------------------------------------

void Game::stop() {
    mainWindow.close();
}

