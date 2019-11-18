#ifndef FIREBALL_HPP_
#define FIREBALL_HPP_

#include "projectile.hpp"

class Fireball : public Projectile {

public:
    Fireball(int posX, int posY, float speedX, float speedY);
    ~Fireball();

    void collideX(Bardo* b);
    void collideY(Bardo* b);

};

#endif // FIREBALL_HPP
