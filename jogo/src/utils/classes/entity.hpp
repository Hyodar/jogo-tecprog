
#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "collidable.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity : public Collidable {
    protected:
        sf::Vector2i size;
        sf::Vector2f position;

    public:
        Entity(int x=0, int y=0, int sizeX=0, int sizeY=0);
        virtual ~Entity();

        int getSizeX() { return size.x; }
        int getSizeY() { return size.y; }

        sf::Vector2f getPosition() { return position; }
        virtual void updatePosition(float deltaTime) { /* noop */ }
        sf::FloatRect getBoundingBox() const { return sf::FloatRect(position.x, position.y, size.x, size.y); }
        virtual void takeDamage(float dmg) = 0;
        virtual bool collide(Collidable& e) { /* noop */ return false; }

};

#endif // ENTITY_HPP_
