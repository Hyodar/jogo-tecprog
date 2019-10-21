
#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_

#include "player.hpp"

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
    bool collide(Player& player);
};

#endif // OBSTACLE_HPP_
