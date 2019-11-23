#ifndef FIREBALL_HPP_
#define FIREBALL_HPP_

#include "projectile.hpp"

namespace bardadv::characters {
class Bardo;
}

namespace bardadv::projectiles {

using bardadv::characters::Bardo;

class Fireball : public bardadv::projectiles::Projectile {

public:
    Fireball(int posX, int posY, float speedX, float speedY);
    ~Fireball();

    void collideX(Bardo* b);
    void collideY(Bardo* b);

};

}

#endif // FIREBALL_HPP
