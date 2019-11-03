
#ifndef COLLIDABLE_HPP_
#define COLLIDABLE_HPP_

#include <SFML/Graphics.hpp>

class Collidable {

    public:
        virtual bool collide(Collidable& c) {
            return c.getBoundingBox().intersects(this->getBoundingBox());
        }
        virtual sf::FloatRect getBoundingBox() const {
            return sf::FloatRect(0, 0, 0, 0);
        }
        virtual void takeDamage(float dmg) {
            // noop
        }
};

#endif // COLLIDABLE_HPP_