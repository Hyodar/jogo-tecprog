
#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_

#include "collidable.hpp"
#include "entity.hpp"
#include "database_model.hpp"

class Obstacle : public Entity, public DatabaseModel<Obstacle*> {

public:
    Obstacle(int posX, int posY, int sizeX, int sizeY) : Entity(posX, posY, sizeX, sizeY) {
        // noop
    }

    virtual sf::FloatRect getBoundingBox() const = 0;
    virtual void takeDamage(float dmg) { 
        // noop
    }
    virtual void updatePosition(float deltaTime) { /* noop */ }

    virtual float getCollisionDmg() { return 10; }
};

#endif // OBSTACLE_HPP_
