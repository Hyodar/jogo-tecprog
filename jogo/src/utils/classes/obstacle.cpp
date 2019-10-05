
#include "obstacle.hpp"

#include <iostream>

int Obstacle::hitDamage = 20;

Obstacle::Obstacle(int type) : obstacleType{type} {}

bool Obstacle::collide(Player& player) {
    if(obstacleType == noCollider) {
        return false;
    } else if(obstacleType == collideNoDamage) {
        return true;
    } else if (obstacleType == collideDamage) {
        if(!player.isInvulnerable()) {
            player.takeDamage(hitDamage);
            std::cout << "Ouch!" << std::endl;
        }
        return true;
    }
}