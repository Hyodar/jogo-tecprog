
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "menu.hpp"

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"

using namespace bardadv::core;
using namespace bardadv::menus;

// Methods
// ---------------------------------------------------------------------------

Menu::Menu() : Ent(0, 0) {
    // noop
}

// ---------------------------------------------------------------------------

Menu::~Menu() {
    // noop
}

// ---------------------------------------------------------------------------

void Menu::addButton(int left, int top, int width, int height, MenuCommand action) {
    MenuItem button;
    button.rect.left = left;
    button.rect.top = top;
    button.rect.width = width;
    button.rect.height = height;
    button.action = action;

    menuItems.push_back(button);
}

// ---------------------------------------------------------------------------

void Menu::render(sf::RenderWindow& renderWindow) {
    renderWindow.draw(sprite);
    renderWindow.display();
}

// ---------------------------------------------------------------------------

MenuCommand Menu::handleClick(int x, int y) {
    std::list<MenuItem>::iterator item;

    for(item = menuItems.begin(); item != menuItems.end(); item++) {
        sf::Rect<int> menuItemRect = item->rect;

        if(menuItemRect.contains(x, y)){
            return item->action;
        }
    }

    return MenuCommand::NOOP;
}

// ---------------------------------------------------------------------------

MenuCommand Menu::getMenuResponse(sf::RenderWindow& renderWindow) {
    sf::Event event;

    while(true) {
        while(renderWindow.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::MouseButtonPressed:
                    return handleClick(event.mouseButton.x, event.mouseButton.y);
                case sf::Event::Closed:
                    return MenuCommand::EXIT;
                default:;
            }
        }
    }
}
