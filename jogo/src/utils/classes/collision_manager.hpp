
#include "entity.hpp"

class CollisionManager {

public:
    static void processCollision(Entity* e, Entity* e2) {
        e->collide(*e2);
        e2->collide(*e);
    }

};