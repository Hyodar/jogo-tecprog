
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
    srand(time(NULL));
    int dmg=rand()%31+5;
    if(player.getBoundingBox().intersects(collider)) {
        player.takeDamage(dmg);
        return true;
    }
    return false;
}
