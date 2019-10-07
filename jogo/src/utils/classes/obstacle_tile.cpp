
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "obstacle_tile.hpp"

// Methods
// ---------------------------------------------------------------------------

ObstacleTile::ObstacleTile(int tileNum, int row, int col, float collDmg) 
: Tile(tileNum, row, col), collisionDamage{collDmg} {
    // noop
}

// ---------------------------------------------------------------------------

bool ObstacleTile::collide(Player& player) const {
    if(player.getBoundingBox().intersects(collider)) {
        player.takeDamage(collisionDamage);
        return true;
    }
    return false;
}
