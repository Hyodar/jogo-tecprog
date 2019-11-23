
#ifndef COLLIDABLE_HPP_
#define COLLIDABLE_HPP_

#include <SFML/Graphics.hpp>

namespace bardadv::collision {

class Collidable {

    public:
        virtual sf::FloatRect getBoundingBox() const;
        
        virtual void takeDamage(float dmg);
};

}

#endif // COLLIDABLE_HPP_
