#include "projectile.hpp"

class LevelManager;

class EnergyBall : public Projectile {

private:
    float traveledDist;
    static bool alreadySplited;

public:
    EnergyBall(int posX, int posY, float speedX, float speedY);
    ~EnergyBall();
    void updatePositionX(const float deltaTime);
    void updatePositionY(const float deltaTime);
    void split();
    void setAlreadySplited(bool as){ alreadySplited = as; };
};
