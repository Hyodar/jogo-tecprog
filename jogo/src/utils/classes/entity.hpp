
#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <SFML/Graphics.hpp>


class Entity {
    protected:
        sf::Vector2i size;
        sf::Vector2f position;

    public:
        Entity(int x=0, int y=0, int sizeX=0, int sizeY=0);
        ~Entity();

};

#endif //Entity.hpp
