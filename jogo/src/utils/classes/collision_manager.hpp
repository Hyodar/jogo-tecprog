
#include "entity.hpp"

class CollisionManager {

public:
    static void processCollision(Entity* e, Entity* e2) {
        if(!e->getBoundingBox().intersects(e2->getBoundingBox())) return;

        e->collide(*e2);
        e2->collide(*e);
    }

};