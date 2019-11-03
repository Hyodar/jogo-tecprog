
#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_

#include "collidable.hpp"
#include "entity.hpp"

class Obstacle : public Entity, public Collidable {

public:
    Obstacle(int posX, int posY, int sizeX, int sizeY) : Entity(posX, posY, sizeX, sizeY) {
        // noop
    }

    virtual bool collide(Collidable& c) = 0;
    virtual sf::FloatRect getBoundingBox() = 0;
    void takeDamage(float dmg) { 
        // noop
    }
};

#endif // OBSTACLE_HPP_
