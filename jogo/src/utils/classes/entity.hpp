
#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "collidable.hpp"
#include "ent.hpp"

#include <SFML/Graphics.hpp>

class Entity : public Collidable, public Ent {
    
protected:
    sf::Vector2i size;

public:
    Entity(int x=0, int y=0, int sizeX=0, int sizeY=0);
    virtual ~Entity();

    int getSizeX() { return size.x; }
    int getSizeY() { return size.y; }

    sf::FloatRect getBoundingBox() const { return sf::FloatRect(position.x, position.y, size.x, size.y); }
    virtual void updatePositionX(float deltaTime) { /* noop */ }
    virtual void updatePositionY(float deltaTime) { /* noop */ }
    virtual void render(sf::RenderWindow& window) { /* noop */ }
    
    virtual void takeDamage(float dmg) = 0;
};

#endif // ENTITY_HPP_
