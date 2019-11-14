
#ifndef PROJECTILE_HPP_
#define PROJECTILE_HPP_

#include "entity.hpp"

#include <SFML/Graphics.hpp>

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"

class Projectile : public Entity {

protected:
    sf::Vector2f speed;
    sf::RectangleShape shape;
    float collisionDmg;

public:
    Projectile(int posX, int posY, int sizeX, int sizeY, float speedX, float speedY);
    virtual ~Projectile();

    void takeDamage(float dmg);
    virtual void updatePositionX(const float deltaTime);
    virtual void updatePositionY(const float deltaTime);

    virtual void collideX(Bardo* b) { b->takeDamage(getCollisionDmg()); }
    virtual void collideY(Bardo* b) { b->takeDamage(getCollisionDmg()); }
    
    virtual void collideX(FielEscudeiro* f) { f->takeDamage(getCollisionDmg()); }
    virtual void collideY(FielEscudeiro* f) { f->takeDamage(getCollisionDmg()); }

    void render(sf::RenderWindow& window);
    virtual float getCollisionDmg();

};

#endif // PROJECTILE_HPP_
