
#include "obstacle.hpp"

Obstacle::Obstacle(int type) : obstacleType{type} {}

bool Obstacle::collide() {
    // TODO - mandar jogador por parametro e colocar collider com dano
    if(obstacleType == noCollider) {
        return false;
    } else if(obstacleType == collideNoDamage) {
        return true;
    }
}