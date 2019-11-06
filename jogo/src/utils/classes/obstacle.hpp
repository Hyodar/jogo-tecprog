
#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_

#include "collidable.hpp"
#include "entity.hpp"

class Obstacle : public Entity {

public:
    Obstacle(int posX, int posY, int sizeX, int sizeY) : Entity(posX, posY, sizeX, sizeY) {
        // noop
    }

    virtual bool collide(Collidable& c) = 0;
    virtual sf::FloatRect getBoundingBox() const = 0;
    virtual void takeDamage(float dmg) { 
        // noop
    }
    virtual void updatePosition() { /* noop */ }
};

#endif // OBSTACLE_HPP_
