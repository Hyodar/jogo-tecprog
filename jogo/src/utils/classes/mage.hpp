#ifndef MAGE_HPP_
#define MAGE_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "enemy.hpp"

namespace bardadv::characters {

class Bardo;

class Mage : public bardadv::characters::Enemy {

private:
    int attackCounter;
    int attackInterval;

public:
    Mage(int x=0, int y=0, Bardo* pp = nullptr);
    Mage(int id=-1, float hp=-1, int x=0, int y=0, Bardo* pp = nullptr);
    ~Mage();
    void checkPlayerPos();
    void update(const float deltaTime);
    void updatePositionX(float deltaTime);
    void updatePositionY(float deltaTime);
    void launchEnergyBall();

};

}

#endif // MAGE_HPP_
