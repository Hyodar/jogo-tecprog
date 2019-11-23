
#ifndef COLLISION_DETECTER_HPP_
#define COLLISION_DETECTER_HPP_

namespace bardadv::collision {

class Collidable;

class CollisionDetecter {

public:
    CollisionDetecter();
    ~CollisionDetecter();

    const bool isColliding(Collidable* e1, Collidable* e2) const;

};

}

#endif // COLLISION_DETECTER_HPP_
