#include "projectile.hpp"

class LevelManager;

class EnergyBall : public Projectile {

private:
    float traveledDist;
    bool alreadySplited;
    bool child;

public:
    EnergyBall(int posX, int posY, float speedX, float speedY, bool child=false);
    ~EnergyBall();
    void updatePositionX(const float deltaTime);
    void updatePositionY(const float deltaTime);
    void split();
    void setAlreadySplited(bool as){ alreadySplited = as; };
};
