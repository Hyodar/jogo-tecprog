// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "obstacle.hpp"

// Internal libraries
// ---------------------

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"

using namespace bardadv::obstacles;
using namespace bardadv::characters;

// Attribute initialization
// ---------------------------------------------------------------------------

// Methods
// ---------------------------------------------------------------------------

Obstacle::Obstacle(int posX, int posY, int sizeX, int sizeY, int classification) :
    Entity(posX, posY, sizeX, sizeY, classification) {
    // noop
}

// ---------------------------------------------------------------------------

Obstacle::~Obstacle(){
    //noop
}

// ---------------------------------------------------------------------------

void Obstacle::takeDamage(float dmg) {
    // noop
}

// ---------------------------------------------------------------------------

void Obstacle::updatePosition(float deltaTime) {
    // noop
}

// ---------------------------------------------------------------------------

float Obstacle::getCollisionDmg() {
    return 0;
 }

 // ---------------------------------------------------------------------------

void Obstacle::collideX(Enemy* e) {
    // noop
}

// ---------------------------------------------------------------------------

void Obstacle::collideY(Enemy* e) {
    // noop
}

// ---------------------------------------------------------------------------

void Obstacle::collideX(Bardo* b) {
    b->takeDamage(getCollisionDmg());
 }

 // ---------------------------------------------------------------------------

void Obstacle::collideY(Bardo* b) {
    b->takeDamage(getCollisionDmg());
 }

 // ---------------------------------------------------------------------------

void Obstacle::collideX(FielEscudeiro* f) {
    f->takeDamage(getCollisionDmg());
 }

 // ---------------------------------------------------------------------------

void Obstacle::collideY(FielEscudeiro* f) {
    f->takeDamage(getCollisionDmg());
 }

 // ---------------------------------------------------------------------------

json Obstacle::store() {
    json j;

    j["id"] = id;
    j["classification"] = classification;
    j["posX"] = position.x;
    j["posY"] = position.y;

    return j;
}
