
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "pause_menu.hpp"

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"

using namespace bardadv::core;
using namespace bardadv::menus;

// Methods
// ---------------------------------------------------------------------------

PauseMenu::PauseMenu() {
    sprite.setTexture(*(GraphicsManager::getInstance()->getPauseMenuTexture()));

    addButton(0, 260, 1023, 110, MenuCommand::RESUME);
    addButton(0, 420, 1023, 80, MenuCommand::SAVE);
    addButton(0, 550, 1023, 80, MenuCommand::EXIT);
}

// ---------------------------------------------------------------------------

PauseMenu::~PauseMenu() {
    // noop
}
