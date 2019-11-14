
#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "character.hpp"

class Bardo;
class FielEscudeiro;

class Enemy : public Character {

protected:
    int enemyNum;
    Bardo* player;

public:
    Enemy(int posX, int posY, int sizeX, int sizeY, int hp, Bardo* p);
    virtual ~Enemy();

    virtual void collideX(Bardo* b);
    virtual void collideY(Bardo* b);

    virtual void collideX(FielEscudeiro* f);
    virtual void collideY(FielEscudeiro* f);

};

#endif // ENEMY_HPP_
