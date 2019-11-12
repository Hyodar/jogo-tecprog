#include "projectile.hpp"

class Bardo;

class EnergyBall : public Projectile {

private:
    Bardo* player;

public:
    EnergyBall(int posX, int posY, float speedX, float speedY, Bardo* pp);
    ~EnergyBall();
    void updatePositionX(const float deltaTime);
    void updatePositionY(const float deltaTime);

};
