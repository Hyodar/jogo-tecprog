
#ifndef _TILE_HPP
#define _TILE_HPP

#include <SFML/Graphics.hpp>

class Tile {

private:
    sf::RectangleShape* rect;
    int tileNumber;

public:
    Tile(int tileNumber);
    void draw(sf::Vector2f pos);

    char getTileNumber() { return tileNumber; }

};

#endif
