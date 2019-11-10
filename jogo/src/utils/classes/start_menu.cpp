
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
    
    addButton(0, 210, 1023, 80, play1tab);
    addButton(0, 300, 1023, 80, play1sal);
    addButton(0, 380, 1023, 80, play2tab);
    addButton(0, 470, 1023, 80, play2sal);
    addButton(0, 620, 1023, 80, resume);
}

// ---------------------------------------------------------------------------

void StartMenu::addButton(int left, int top, int width,
                         int height, StartMenu::MenuResult action) {
    MenuItem button;
    button.rect.left = left;
    button.rect.top = top;
    button.rect.width = width;
    button.rect.height = height;
    button.action = action;

    menuItems.push_back(button);
}

// ---------------------------------------------------------------------------

StartMenu::MenuResult StartMenu::show(sf::RenderWindow& renderWindow) {
    sf::Sprite sprite;
    sprite.setTexture(*(GraphicsManager::getInstance()->getStartMenuTexture()));

    renderWindow.draw(sprite);
    renderWindow.display();

    return getMenuResponse(renderWindow);
}

// ---------------------------------------------------------------------------

StartMenu::MenuResult StartMenu::handleClick(int x, int y) {
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

StartMenu::MenuResult StartMenu::getMenuResponse(sf::RenderWindow& renderWindow) {
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
