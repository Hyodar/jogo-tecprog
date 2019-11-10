
#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "collidable.hpp"
#include <SFML/Graphics.hpp>

class Entity : public Collidable {
    
protected:
    sf::Vector2i size;
    sf::Vector2f position;

public:
    Entity(int x=0, int y=0, int sizeX=0, int sizeY=0);
    virtual ~Entity();

    int getSizeX() { return size.x; }
    int getSizeY() { return size.y; }

    sf::FloatRect getBoundingBox() const { return sf::FloatRect(position.x, position.y, size.x, size.y); }
    virtual void updatePositionX(float deltaTime) { /* noop */ }
    virtual void updatePositionY(float deltaTime) { /* noop */ }
    
    virtual void takeDamage(float dmg) = 0;
    
    sf::Vector2f getPosition() { return position; }    
    void setPosX(float p) { position.x = p; }
    void setPosY(float p) { position.y = p; }
    float getPosX() { return position.x; }
    float getPosY() { return position.y; }

};

#endif // ENTITY_HPP_
