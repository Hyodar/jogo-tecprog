
#ifndef COLLIDABLE_HPP_
#define COLLIDABLE_HPP_

#include <SFML/Graphics.hpp>

namespace bardadv::collision {

class Collidable {

public:
    Collidable();
    virtual ~Collidable();

    virtual sf::FloatRect getBoundingBox() const;
    
};

}

#endif // COLLIDABLE_HPP_
