
#ifndef OBSTACLE_TILE_HPP_
#define OBSTACLE_TILE_HPP_

#include "tile.hpp"
#include "player.hpp"

class ObstacleTile : public Tile {

private:
    float collisionDamage;

public:
    ObstacleTile(int tileNum, int row, int col, float collDmg);
    ~ObstacleTile() {}

    bool collide(Player& player) const;

};

#endif // OBSTACLE_TILE_HPP_