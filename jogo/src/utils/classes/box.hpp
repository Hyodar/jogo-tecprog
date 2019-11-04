
#ifndef BOX_HPP_
#define BOX_HPP_

#include <SFML/Graphics.hpp>

#include <constants.hpp>

#include "obstacle.hpp"
#include "collidable.hpp"
#include "tile_manager.hpp"
#include "game_map.hpp"
#include "game.hpp"

class Box : public Obstacle {

private:
    sf::RectangleShape* shape;
    static sf::Vector2f boxSize;

    float durability;

public:
    Box(int posX, int posY) : Obstacle(posX, posY, Box::boxSize.x, Box::boxSize.y),
                              durability{100} {
        shape = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
        shape->setTexture(TileManager::getInstance()->getTileSetTexture());
        shape->setTextureRect(sf::IntRect(5*TILE_SIZE, 0, 2*TILE_SIZE, 2*TILE_SIZE));
    }

    ~Box() {
        delete shape;
    }

    bool collide(Collidable& c) {
        return c.getBoundingBox().intersects(getBoundingBox());
    }

    void takeDamage(float dmg) {
        durability -= dmg;
    }

    sf::FloatRect getBoundingBox() const {
        return sf::FloatRect(position.x, position.y, size.x, size.y);
    }

    void draw(sf::RenderWindow& window) {
        shape->setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
        window.draw(*shape);
        //if(position.x < playerPos.x + windowW/2 && position.y > playerPos.x - windowW/2) {
    }
};

#endif // BOX_HPP_
