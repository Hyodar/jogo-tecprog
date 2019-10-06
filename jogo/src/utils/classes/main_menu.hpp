
#ifndef MAIN_MENU_HPP_
#define MAIN_MENU_HPP_

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

    MainMenu();
    MenuResult show(sf::RenderWindow& renderWindow);

private:
    void addButton(int left, int top, int width,
                    int height, MenuResult action);
    MenuResult getMenuResponse(sf::RenderWindow& renderWindow);
    MenuResult handleClick(int x, int y);

    std::list<MenuItem> menuItems;
    sf::Texture texture;
    
};

#endif // MAIN_MENU_HPP_
