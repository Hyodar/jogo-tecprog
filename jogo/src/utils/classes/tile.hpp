
#ifndef _TILE_HPP
#define _TILE_HPP

#include <SFML/Graphics.hpp>

#include "player.hpp"

class Tile {

private:
    sf::RectangleShape* rect;
    sf::FloatRect collider;
    int tileNumber;

public:
    Tile(int tileNumber, sf::RectangleShape* shape, sf::FloatRect coll);
    Tile(int tileNumber, int row, int col);
    Tile() {}

    void draw(sf::Vector2f pos);
    bool collide(Player& player) const;

    char getTileNumber() { return tileNumber; }
    sf::RectangleShape* getTileTexture() const { return rect; }
    sf::FloatRect getTileCollider() const { return collider; }

};

#endif
