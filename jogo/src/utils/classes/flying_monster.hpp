
#ifndef FLYINGMONSTER_HPP_
#define FLYINGMONSTER_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "enemy.hpp"

namespace bardadv::characters {
class Bardo;
}

namespace bardadv::characters {

using bardadv::characters::Bardo;

class FlyingMonster : public bardadv::characters::Enemy {

private:
    sf::Vector2f startingPos;
    float absoluteTime;

public:
    FlyingMonster(int x=0, int y=0, Bardo* pp = nullptr);
    FlyingMonster(int id=-1, float hp=-1, float abstime=-1, int x=0, int y=0, Bardo* pp = nullptr);
    ~FlyingMonster();
    void checkPlayerPos();
    void update(const float deltaTime);
    void updatePositionX(const float deltaTime);
    void updatePositionY(const float deltaTime);

    void setAbsoluteTime(float absTime);

    json store();

};

}

#endif // FLYINGMONSTER_HPP_
