
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "main_menu.hpp"

// Methods
// ---------------------------------------------------------------------------

MainMenu::MainMenu() {
    texture.loadFromFile("resources/main_menu.png");
}

// ---------------------------------------------------------------------------

void MainMenu::addButton(int left, int top, int width,
                         int height, MainMenu::MenuResult action) {
    MenuItem button;
    button.rect.left = left;
    button.rect.top = top;
    button.rect.width = width;
    button.rect.height = height;
    button.action = action;

    menuItems.push_back(button);
}

// ---------------------------------------------------------------------------

MainMenu::MenuResult MainMenu::show(sf::RenderWindow& renderWindow) {
    sf::Sprite sprite;
    sprite.setTexture(texture);

    addButton(0, 145, 1023, 177, play);
    addButton(0, 383, 1023, 177, exit);

    renderWindow.draw(sprite);
    renderWindow.display();

    return getMenuResponse(renderWindow);
}

// ---------------------------------------------------------------------------

MainMenu::MenuResult MainMenu::handleClick(int x, int y) {
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

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow& renderWindow) {
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
