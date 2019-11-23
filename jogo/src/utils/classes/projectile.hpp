
#ifndef PROJECTILE_HPP_
#define PROJECTILE_HPP_

#include "entity.hpp"

#include <SFML/Graphics.hpp>

namespace bardadv::characters {
class Bardo;
class FielEscudeiro;
}

namespace bardadv::projectiles {

using bardadv::characters::Bardo;
using bardadv::characters::FielEscudeiro;

class Projectile : public bardadv::core::Entity {

protected:
    sf::Vector2f speed;
    sf::RectangleShape shape;
    float collisionDmg;
    float traveledDist;

public:
    Projectile(int posX, int posY, int sizeX, int sizeY, float speedX, float speedY, int classification);
    virtual ~Projectile();

    float getTraveledDist() const;

    void takeDamage(float dmg);
    virtual void updatePositionX(const float deltaTime);
    virtual void updatePositionY(const float deltaTime);

    virtual void collideX(Bardo* b);
    virtual void collideY(Bardo* b);

    virtual void collideX(FielEscudeiro* f);
    virtual void collideY(FielEscudeiro* f);

    void render(sf::RenderWindow& window);
    virtual float getCollisionDmg();

    json store();

};

}

#endif // PROJECTILE_HPP_
