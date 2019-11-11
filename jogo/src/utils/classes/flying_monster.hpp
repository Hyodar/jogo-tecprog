#ifndef FLYINGMONSTER_HPP_
#define FLYINGMONSTER_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "enemy.hpp"
#include "bardo.hpp"

class FlyingMonster : public Enemy {

protected:
    sf::Vector2f startingPos;

public:
    FlyingMonster(int x=0, int y=0, Bardo* pp = nullptr);
    ~FlyingMonster();
    void checkPlayerPos();
    void update(const float deltaTime);
    void updatePositionX(const float deltaTime);
    void updatePositionY(const float deltaTime);

};
#endif //FLYINGMONSTER_HPP_
