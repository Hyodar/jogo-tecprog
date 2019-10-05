
#ifndef _TILE_HPP
#define _TILE_HPP

#include <SFML/Graphics.hpp>

class Tile {

private:
    sf::RectangleShape* TEST_rect;
    char tileChar;

public:
    Tile(char tileChar);
    void draw(sf::Vector2f pos);
    virtual bool collide();

};

#endif
