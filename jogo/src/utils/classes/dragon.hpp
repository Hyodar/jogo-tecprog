
#ifndef DRAGON_HPP_
#define DRAGON_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "enemy.hpp"

class Bardo;

class Dragon : public Enemy {

private:
    
    int attackCounter;
    int attackInterval;

public:
    Dragon(int x=0, int y=0, Bardo* pp = nullptr);
    ~Dragon();
    void checkPlayerPos();
    void update(const float deltaTime);
    void updatePositionX(float deltaTime);
    void updatePositionY(float deltaTime);
    void launchFireball();

};
#endif // DRAGON_HPP_
