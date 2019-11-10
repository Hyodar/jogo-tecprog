
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "pause_menu.hpp"

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"

// Methods
// ---------------------------------------------------------------------------

PauseMenu::PauseMenu() {
    
    addButton(0, 260, 1023, 110, resume);
    addButton(0, 420, 1023, 80, save);
    addButton(0, 550, 1023, 80, exit);
}

// ---------------------------------------------------------------------------

void PauseMenu::addButton(int left, int top, int width,
                         int height, PauseMenu::MenuResult action) {
    MenuItem button;
    button.rect.left = left;
    button.rect.top = top;
    button.rect.width = width;
    button.rect.height = height;
    button.action = action;

    menuItems.push_back(button);
}

// ---------------------------------------------------------------------------

PauseMenu::MenuResult PauseMenu::show(sf::RenderWindow& renderWindow) {
    sf::Sprite sprite;
    sprite.setTexture(*(GraphicsManager::getInstance()->getPauseMenuTexture()));

    renderWindow.draw(sprite);
    renderWindow.display();

    return getMenuResponse(renderWindow);
}

// ---------------------------------------------------------------------------

PauseMenu::MenuResult PauseMenu::handleClick(int x, int y) {
    std::list<MenuItem>::iterator item;

    for(item = menuItems.begin(); item != menuItems.end(); item++) {
        sf::Rect<int> menuItemRect = item->rect;

        if(menuItemRect.contains(x, y)){
            return item->action;
        }
    }

    return noop;
}

// ---------------------------------------------------------------------------

PauseMenu::MenuResult PauseMenu::getMenuResponse(sf::RenderWindow& renderWindow) {
    sf::Event event;

    while(true) {
        while(renderWindow.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::MouseButtonPressed:
                    return handleClick(event.mouseButton.x, event.mouseButton.y);
                case sf::Event::Closed:
                    return exit;
                default:;
            }
        }
    }
}
