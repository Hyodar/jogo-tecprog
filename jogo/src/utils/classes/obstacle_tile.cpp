
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "obstacle_tile.hpp"

#include <iostream>

// Methods
// ---------------------------------------------------------------------------

ObstacleTile::ObstacleTile(int tileNum, int row, int col, float collDmg)
: Tile(tileNum, row, col), collisionDamage{collDmg} {
    // noop
}

// ---------------------------------------------------------------------------

bool ObstacleTile::collide(Collidable& c) {
    srand(time(NULL));
    int dmg = rand()%31+5;
    if(c.getBoundingBox().intersects(collider)) {
        c.takeDamage(dmg);
        return true;
    }
    return false;
}
