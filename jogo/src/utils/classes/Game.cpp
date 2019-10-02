
#include "game.hpp"

#include "splash_screen.hpp"
#include "main_menu.hpp"

// -------------------------------------------------------------

Game::GameState Game::gameState = uninitialized;
sf::RenderWindow Game::mainWindow;

Game::Game() {
    
}

// -------------------------------------------------------------

void Game::start() {

    if(gameState != uninitialized) return;

    mainWindow.create(sf::VideoMode(1024, 768), "Game title");
    gameState = showingSplash;

    while(!isExiting()) {
        gameLoop();
    }

    mainWindow.close();
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
            
            case Game::showingMenu:
                showMenu();
                break;

            case Game::showingSplash:
                showSplashScreen();
                break;
            
            // playing stage
            case Game::playing:
                mainWindow.clear(sf::Color(0, 255, 0));
                mainWindow.display();

                switch(event.type) {
                    case sf::Event::Closed:
                        gameState = exiting;
                        break;
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