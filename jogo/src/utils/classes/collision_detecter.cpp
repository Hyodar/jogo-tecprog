// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "collision_detecter.hpp"

// Internal libraries
// ---------------------

#include "collidable.hpp"


// Attribute initialization
// ---------------------------------------------------------------------------

using namespace bardadv::collision;

// Methods
// ---------------------------------------------------------------------------

CollisionDetecter::CollisionDetecter() {
    // noop
}

// ---------------------------------------------------------------------------

CollisionDetecter::~CollisionDetecter() {
    // noop
}

// ---------------------------------------------------------------------------

const bool CollisionDetecter::isColliding(Collidable* e1, Collidable* e2) const {
    return e1->getBoundingBox().intersects(e2->getBoundingBox());
}
