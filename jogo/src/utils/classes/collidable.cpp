// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "collidable.hpp"

// Internal libraries
// ---------------------

using namespace bardadv::collision;

// Attribute initialization
// ---------------------------------------------------------------------------

// Methods
// ---------------------------------------------------------------------------

sf::FloatRect Collidable::getBoundingBox() const {
    return sf::FloatRect(0, 0, 0, 0);
}

// ---------------------------------------------------------------------------

void Collidable::takeDamage(float dmg) {
    // noop
}
