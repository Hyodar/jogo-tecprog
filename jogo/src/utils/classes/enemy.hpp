
#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "character.hpp"

class Bardo;

class Enemy : public Character {

protected:
    int enemyNum;
    Bardo* player;

public:
    Enemy(int posX, int posY, int sizeX, int sizeY, int hp, Bardo* p);
    virtual ~Enemy();

};

#endif // ENEMY_HPP_
