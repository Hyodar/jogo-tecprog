
#ifndef _TILE_HPP
#define _TILE_HPP

#include <SFML/Graphics.hpp>

class Tile {

private:
    sf::RectangleShape* TEST_rect;
    int tileNumber;

public:
    Tile(int tileNumber);
    void draw(sf::Vector2f pos);
    virtual bool collide();

    char getTileNumber() { return tileNumber; }

};

#endif
