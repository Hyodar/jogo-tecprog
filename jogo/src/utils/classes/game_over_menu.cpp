
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "game_over_menu.hpp"

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"

// Methods
// ---------------------------------------------------------------------------

GameOverMenu::GameOverMenu() {
    sprite.setTexture(*(GraphicsManager::getInstance()->getGameOverMenuTexture()));
    
    addButton(250, 400, 500, 80, MenuCommand::RETURN);
    addButton(420, 500, 180, 80, MenuCommand::EXIT);
}

// ---------------------------------------------------------------------------

GameOverMenu::~GameOverMenu() {

}
