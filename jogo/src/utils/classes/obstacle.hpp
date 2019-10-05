
#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_

class Obstacle {

private:
    enum ObstacleType {
        noCollider,
        nSeiOq,
        collideNoDamage,
        collideDamage
    };

    int obstacleType;

public:
    Obstacle(int type);
    bool collide();

};

#endif // OBSTACLE_HPP_