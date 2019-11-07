
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "pause_menu.hpp"

// Methods
// ---------------------------------------------------------------------------

PauseMenu::PauseMenu() {
    texture.loadFromFile("resources/pause_menu.png");
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
    sprite.setTexture(texture);

    addButton(0, 260, 1023, 110, resume);
    addButton(0, 420, 1023, 80, save);
    addButton(0, 550, 1023, 80, exit);

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
