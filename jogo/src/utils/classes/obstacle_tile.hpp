
#ifndef OBSTACLE_TILE_HPP_
#define OBSTACLE_TILE_HPP_

#include "tile.hpp"
#include "collidable.hpp"
#include "bardo.hpp"

class ObstacleTile : public Tile {

private:
    float collisionDamage;

public:
    ObstacleTile(int tileNum, int row, int col, float collDmg);
    ~ObstacleTile() {}

    bool collide(Collidable& c);

};

#endif // OBSTACLE_TILE_HPP_