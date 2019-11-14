
#include "collision_detecter.hpp"

#include "collidable.hpp"

CollisionDetecter::CollisionDetecter() {
    // noop
}

CollisionDetecter::~CollisionDetecter() {
    // noop
}

const bool CollisionDetecter::isColliding(Collidable* e1, Collidable* e2) const {
    return e1->getBoundingBox().intersects(e2->getBoundingBox());
}