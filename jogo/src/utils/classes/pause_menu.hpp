
#ifndef PAUSE_MENU_HPP_
#define PAUSE_MENU_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <list>

class PauseMenu {
    
public:
    // menu options
    enum MenuResult {
        exit,
        noop,
        resume,
        save
    };

    struct MenuItem {
        public:
            sf::Rect<int> rect;
            MenuResult action;
    };

    PauseMenu();
    MenuResult show(sf::RenderWindow& renderWindow);

private:
    void addButton(int left, int top, int width,
                    int height, MenuResult action);
    MenuResult getMenuResponse(sf::RenderWindow& renderWindow);
    MenuResult handleClick(int x, int y);

    std::list<MenuItem> menuItems;
    sf::Texture texture;
    
};

#endif // PAUSE_MENU_HPP_
