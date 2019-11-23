
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "enemy.hpp"

// Internal libraries
// ----------------------

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"

using namespace bardadv::characters;

// Methods
// ---------------------------------------------------------------------------

Enemy::Enemy(int posX, int posY, int sizeX, int sizeY, int hp, Bardo* p, int pontos, int classification)
 : Character(posX, posY, sizeX, sizeY, hp, classification), player{p}, points{pontos} {
    // noop
}

// ---------------------------------------------------------------------------

Enemy::~Enemy() {
    // noop
}

// ---------------------------------------------------------------------------

int Enemy:: getPoints()const{
    return points;
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

// ---------------------------------------------------------------------------

json Enemy::store() {
    json j;

    j["id"] = id;
    j["playerId"] = player->getId();
    j["classification"] = classification;
    j["hp"] = hitPoints;
    j["posX"] = position.x;
    j["posY"] = position.y;

    return j;
}
