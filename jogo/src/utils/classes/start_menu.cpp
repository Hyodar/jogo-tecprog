
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "start_menu.hpp"

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"

// Methods
// ---------------------------------------------------------------------------

StartMenu::StartMenu() {
    sprite.setTexture(*(GraphicsManager::getInstance()->getStartMenuTexture()));
    
    addButton(0, 210, 1023, 80, MenuCommand::PLAY_1_TABERNA);
    addButton(0, 300, 1023, 80, MenuCommand::PLAY_1_SALAO);
    addButton(0, 380, 1023, 80, MenuCommand::PLAY_2_TABERNA);
    addButton(0, 470, 1023, 80, MenuCommand::PLAY_2_SALAO);
    addButton(0, 620, 1023, 80, MenuCommand::RECOVER_SAVE);
}

// ---------------------------------------------------------------------------

StartMenu::~StartMenu() {

}
