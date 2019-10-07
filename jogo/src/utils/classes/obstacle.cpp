
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "obstacle.hpp"

// Standard libraries
#include <iostream>

// Attribute initialization
// ---------------------------------------------------------------------------

int Obstacle::hitDamage = 20;

// Methods
// ---------------------------------------------------------------------------

Obstacle::Obstacle(int type) : obstacleType{type} {}

// ---------------------------------------------------------------------------

bool Obstacle::collide(Player& player) {
    if(obstacleType == noCollider) {
        return false;
    } else if(obstacleType == collideNoDamage) {
        return true;
    } else if (obstacleType == collideDamage) {
        player.takeDamage(hitDamage);
        std::cout << "Ouch!" << std::endl;
        return true;
    }
    return false;
}
