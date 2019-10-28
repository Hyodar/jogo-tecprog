
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <SFML/Graphics.hpp>

#include"entity.hpp"

class Character : public Entity {

    protected:
        sf::Vector2f speed;

        double hitPoints;
        double maxHitPoints;
        bool onGround;
        static const int jumpSpeed;
        static const int walkSpeed;

    public:
        Character(int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0);
        ~Character();

};

#endif //Character.hpp
