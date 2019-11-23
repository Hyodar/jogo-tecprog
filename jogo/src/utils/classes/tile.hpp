
#ifndef TILE_HPP_
#define TILE_HPP_

#include <SFML/Graphics.hpp>

#include "collidable.hpp"

namespace bardadv::map {

class Tile : public bardadv::collision::Collidable {

protected:
    int tileNumber;
    sf::RectangleShape* rect;
    sf::FloatRect collider;

public:
    Tile(int tileNumber, sf::RectangleShape* shape, sf::FloatRect coll);
    Tile(int tileNumber, int row, int col);
    Tile();
    ~Tile();

    void draw(sf::Vector2f pos);

    char getTileNumber()const;
    sf::RectangleShape* getTileTexture() const;
    sf::FloatRect getBoundingBox() const;

};

}

#endif // TILE_HPP_
