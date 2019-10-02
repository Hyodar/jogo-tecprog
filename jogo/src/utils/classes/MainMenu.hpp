
#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include <list>

class MainMenu {
    
    public:
        // menu options
        enum MenuResult {
            noop,
            exit,
            play
        };

        struct MenuItem {
            public:
                sf::Rect<int> rect;
                MenuResult action;
        };

        MenuResult show(sf::RenderWindow& renderWindow);

    private:
        MenuResult getMenuResponse(sf::RenderWindow& renderWindow);

        MenuResult handleClick(int x, int y);

        std::list<MenuItem> menuItems;
};

#endif // MAIN_MENU_H_