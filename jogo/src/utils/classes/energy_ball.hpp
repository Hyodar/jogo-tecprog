
#ifndef ENERGY_BALL_HPP_
#define ENERGY_BALL_HPP_

#include "projectile.hpp"

namespace bardadv::projectiles {

class EnergyBall : public Projectile {

private:
    bool alreadySplited;

public:
    EnergyBall(int posX, int posY, float speedX, float speedY, bool as = false);
    ~EnergyBall();

    void updatePositionX(const float deltaTime);
    void updatePositionY(const float deltaTime);

    void split();
    void setAlreadySplited(bool as);
};

}

#endif // ENERGY_BALL_HPP_
