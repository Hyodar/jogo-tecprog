// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "projectile.hpp"

// Internal libraries
// ---------------------

#include "game_map.hpp"
#include "graphics_manager.hpp"

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"

#include <constants.hpp>

using namespace bardadv::core;
using namespace bardadv::map;
using namespace bardadv::projectiles;
using namespace bardadv::characters;

// Attribute initialization
// ---------------------------------------------------------------------------

// Methods
// ---------------------------------------------------------------------------

Projectile::Projectile(int posX, int posY, int sizeX, int sizeY, float speedX, float speedY, int classification)
 : Entity(posX, posY, sizeX, sizeY, classification), speed(speedX, speedY), shape(sf::Vector2f(sizeX, sizeY)) {
    shape.setTexture(GraphicsManager::getInstance()->getProjectileTexture());
    traveledDist = 0;
}

// ---------------------------------------------------------------------------

Projectile::~Projectile() {
    /* noop */
}

// ---------------------------------------------------------------------------

float Projectile::getTraveledDist() const {
    return traveledDist;
}

// ---------------------------------------------------------------------------

void Projectile::updatePositionX(const float deltaTime) {

    traveledDist += speed.x * deltaTime;

    position.x += speed.x * deltaTime;
}

// ---------------------------------------------------------------------------

void Projectile::updatePositionY(const float deltaTime) {
    position.y += speed.y * deltaTime;
}

// ---------------------------------------------------------------------------

void Projectile::collideX(Bardo* b) {
     b->takeDamage(getCollisionDmg());
}

// ---------------------------------------------------------------------------

void Projectile::collideY(Bardo* b) {
     b->takeDamage(getCollisionDmg());
}

// ---------------------------------------------------------------------------

void Projectile::collideX(FielEscudeiro* f) {
     f->takeDamage(getCollisionDmg());
}

// ---------------------------------------------------------------------------

void Projectile::collideY(FielEscudeiro* f) {
     f->takeDamage(getCollisionDmg());
}

// ---------------------------------------------------------------------------

void Projectile::render(sf::RenderWindow& window) {
    shape.setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
    window.draw(shape);
}

// ---------------------------------------------------------------------------

float Projectile::getCollisionDmg() {
    return collisionDmg;
}

// ---------------------------------------------------------------------------

void Projectile::takeDamage(float dmg) {
    // noop
}

// ---------------------------------------------------------------------------

json Projectile::store() {
    json j;

    j["id"] = id;
    j["classification"] = classification;
    j["posX"] = position.x;
    j["posY"] = position.y;
    j["speedX"] = speed.x;
    j["speedY"] = speed.y;

    return j;
}
