
#include "MainMenu.hpp"

// -------------------------------------------------------------

MainMenu::MenuResult MainMenu::show(sf::RenderWindow& renderWindow) {

    sf::Texture texture;
    texture.loadFromFile("resources/main_menu.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);

    MenuItem playButton;
    playButton.rect.left = 0;
    playButton.rect.top = 145;
    playButton.rect.width = 1023; // 1023 - 0
    playButton.rect.height = 177; // 380 - 145
    playButton.action = play;

    MenuItem exitButton;
    exitButton.rect.left = 0;
    exitButton.rect.top = 383;
    exitButton.rect.width = 1023; // 0 - 1023
    exitButton.rect.height = 223; //560 - 383
    exitButton.action = exit;

    menuItems.push_back(playButton);
    menuItems.push_back(exitButton);

    renderWindow.draw(sprite);
    renderWindow.display();

    return getMenuResponse(renderWindow);
}

// -------------------------------------------------------------

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

// -------------------------------------------------------------

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow& renderWindow) {
    sf::Event event;

    while(true) {
        while(renderWindow.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::MouseButtonPressed:
                    return handleClick(event.mouseButton.x, event.mouseButton.y);
                case sf::Event::Closed:
                    return exit;
            }
        }
    }
}