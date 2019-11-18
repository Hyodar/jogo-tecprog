
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

class Obstacle : public Entity {

public:
    Obstacle(int posX, int posY, int sizeX, int sizeY, int classification);
    ~Obstacle();

    virtual sf::FloatRect getBoundingBox() const = 0;
    virtual void takeDamage(float dmg);

    virtual void updatePosition(float deltaTime);

    json store();

    virtual float getCollisionDmg();

    virtual void collideX(Enemy* e);
    virtual void collideY(Enemy* e);
    virtual void collideX(Bardo* b);
    virtual void collideY(Bardo* b);
    virtual void collideX(FielEscudeiro* f);
    virtual void collideY(FielEscudeiro* f);
};

#endif // OBSTACLE_HPP_
