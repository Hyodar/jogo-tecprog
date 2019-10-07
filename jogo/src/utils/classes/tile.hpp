
#ifndef TILE_HPP_
#define TILE_HPP_

#include <SFML/Graphics.hpp>

#include "player.hpp"

class Tile {

protected:
    sf::RectangleShape* rect;
    sf::FloatRect collider;
    int tileNumber;

public:
    Tile(int tileNumber, sf::RectangleShape* shape, sf::FloatRect coll);
    Tile(int tileNumber, int row, int col);
    Tile() {}
    virtual ~Tile() {}

    void draw(sf::Vector2f pos);
    virtual bool collide(Player& player) const;

    char getTileNumber() { return tileNumber; }
    sf::RectangleShape* getTileTexture() const { return rect; }
    sf::FloatRect getTileCollider() const { return collider; }

};

#endif // TILE_HPP_
