
#ifndef BOX_HPP_
#define BOX_HPP_

#include <SFML/Graphics.hpp>

#include <game_config.hpp>

#include "obstacle.hpp"

namespace bardadv::characters {
class Bardo;
}

namespace bardadv::obstacles {

using bardadv::characters::Bardo;

class Box : public Obstacle {

private:
    sf::RectangleShape* shape;

public:
    Box(int posX, int posY);
    ~Box();

    void collideX(Bardo* b);
    void collideY(Bardo* b);
    void takeDamage(float dmg);
    sf::FloatRect getBoundingBox() const;
    void render(sf::RenderWindow& window);

    float getCollisionDmg() { return 0; }

};

}

#endif // BOX_HPP_
