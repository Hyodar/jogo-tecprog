
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "enemy.hpp"

// Internal libraries
// ----------------------

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"

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

// ---------------------------------------------------------------------------

void Enemy::takeDamage(float dmg) {
    if(!invulnerable) {
        hitPoints -= dmg;
        invulnerable = 300;
    }
}

// ---------------------------------------------------------------------------

void Enemy::collideX(Bardo* b) {
    b->takeDamage(20);
    b->jump(0.5);
}

// ---------------------------------------------------------------------------

void Enemy::collideY(Bardo* b) {
    b->takeDamage(20);
    b->jump(0.5);
}

// ---------------------------------------------------------------------------

void Enemy::collideX(FielEscudeiro* f) {
    f->takeDamage(10);
    f->jump(0.5);
}

// ---------------------------------------------------------------------------

void Enemy::collideY(FielEscudeiro* f) {
    f->takeDamage(10);
    f->jump(0.5);
}