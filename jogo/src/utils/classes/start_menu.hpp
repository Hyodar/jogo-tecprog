
#ifndef START_MENU_HPP_
#define START_MENU_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <list>

class StartMenu {
    
public:
    // menu options
    enum MenuResult {
        exit,
        noop,
        play1tab,
        play1sal,
        play2tab,
        play2sal,
        resume
    };

    struct MenuItem {
        public:
            sf::Rect<int> rect;
            MenuResult action;
    };

    StartMenu();
    MenuResult show(sf::RenderWindow& renderWindow);

private:
    void addButton(int left, int top, int width,
                    int height, MenuResult action);
    MenuResult getMenuResponse(sf::RenderWindow& renderWindow);
    MenuResult handleClick(int x, int y);

    std::list<MenuItem> menuItems;
    
};

#endif // START_MENU_HPP_
