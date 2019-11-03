
#ifndef TILE_HPP_
#define TILE_HPP_

#include <SFML/Graphics.hpp>
#include "collidable.hpp"

#include "entity.hpp"

class Tile : public Collidable {

protected:
    int tileNumber;
    sf::RectangleShape* rect;
    sf::FloatRect collider;

public:
    Tile(int tileNumber, sf::RectangleShape* shape, sf::FloatRect coll);
    Tile(int tileNumber, int row, int col);
    Tile() {}
    virtual ~Tile() {}

    void draw(sf::Vector2f pos);
    virtual bool collide(Collidable& c) {
        return c.getBoundingBox().intersects(this->getBoundingBox());
    };

    char getTileNumber() { return tileNumber; }
    sf::RectangleShape* getTileTexture() const { return rect; }
    sf::FloatRect getBoundingBox() const { return collider; }

};

#endif // TILE_HPP_
