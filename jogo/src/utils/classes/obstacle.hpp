
#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_

#include "bardo.hpp"

class Obstacle {

private:
    enum ObstacleType {
        noCollider,
        nSeiOq,
        collideNoDamage,
        collideDamage
    };

    int obstacleType;
    static int hitDamage;

public:
    Obstacle(int type);
    bool collide(Bardo& player);
};

#endif // OBSTACLE_HPP_
