
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "enemy.hpp"

// Methods
// ---------------------------------------------------------------------------

Enemy::Enemy(int posX, int posY, int sizeX, int sizeY, int hp, Bardo* p)
 : Character(posX, posY, sizeX, sizeY, hp), player{p} {
    // noop
}

// ---------------------------------------------------------------------------

Enemy::~Enemy() {
    // noop
}