
#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <list>

#include "ent.hpp"
#include <constants.hpp>

namespace bardadv::menus {

class Menu : public bardadv::core::Ent {
    
public:
    Menu();
    ~Menu();

    struct MenuItem {
        public:
            sf::Rect<int> rect;
            MenuCommand action;
    };

    void render(sf::RenderWindow& renderWindow);
    MenuCommand getMenuResponse(sf::RenderWindow& renderWindow);

protected:
    sf::Sprite sprite;

    void addButton(int left, int top, int width, int height, MenuCommand action);
    MenuCommand handleClick(int x, int y);

    std::list<MenuItem> menuItems;
};

}

#endif // MENU_HPP_
