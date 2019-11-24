// Libraries
// ---------------------------------------------------------------------------

#include <SFML/Graphics.hpp>

// Class header
// ---------------------

#include "fireball.hpp"

// Internal libraries
// ---------------------

#include "bardo.hpp"
#include <game_config.hpp>

using namespace bardadv::characters;
using namespace bardadv::projectiles;

// Attribute initialization
// ---------------------------------------------------------------------------

// Methods
// ---------------------------------------------------------------------------

Fireball::Fireball(int posX, int posY, float speedX, float speedY)
 : Projectile(posX, posY, 3 * TILE_SIZE / 2, 3 * TILE_SIZE / 2, speedX, speedY, ProjectileClassification::FIREBALL) {
    shape.setTextureRect(sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
    shape.setScale(1.5, 1.5);

    collisionDmg = 20;
}

// ---------------------------------------------------------------------------

Fireball::~Fireball() {

}

// ---------------------------------------------------------------------------

void Fireball::collideX(Bardo* b) {
    b->takeDamage(getCollisionDmg());
    b->burn();
}

// ---------------------------------------------------------------------------

void Fireball::collideY(Bardo* b) {
    b->takeDamage(getCollisionDmg());
    b->burn();
}
