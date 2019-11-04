
#ifndef LAVA_HPP_
#define LAVA_HPP_

#include <SFML/Graphics.hpp>

#include <constants.hpp>

#include "obstacle.hpp"
#include "collidable.hpp"
#include "tile_manager.hpp"
#include "game_map.hpp"
#include "game.hpp"

class Lava : public Obstacle {

private:
    sf::RectangleShape* shape;
    static float hitDmg;
    static sf::Vector2f lavaSize;

public:
    Lava(int posX, int posY) : Obstacle(posX, posY, Lava::lavaSize.x, Lava::lavaSize.y) {
        shape = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
        shape->setTexture(TileManager::getInstance()->getTileSetTexture());
        shape->setTextureRect(sf::IntRect(5*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    }

    ~Lava() {
        delete shape;
    }

    bool collide(Collidable& c) {
        if(c.getBoundingBox().intersects(getBoundingBox())) {
            c.takeDamage(hitDmg);
            return true;
        }
        return false;
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

#endif // LAVA_HPP_
