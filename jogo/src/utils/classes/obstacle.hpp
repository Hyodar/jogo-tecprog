
#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_

#include "collidable.hpp"
#include "entity.hpp"
#include "database_model.hpp"

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"

class Enemy;
class Bardo;
class FielEscudeiro;

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

    virtual void collideX(Enemy* e) { /* noop */ }
    virtual void collideY(Enemy* e) { /* noop */ }
    virtual void collideX(Bardo* b) { b->takeDamage(getCollisionDmg()); }
    virtual void collideY(Bardo* b) { b->takeDamage(getCollisionDmg()); }
    virtual void collideX(FielEscudeiro* f) { f->takeDamage(getCollisionDmg()); }
    virtual void collideY(FielEscudeiro* f) { f->takeDamage(getCollisionDmg()); }
};

#endif // OBSTACLE_HPP_
