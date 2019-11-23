
#ifndef LAVA_HPP_
#define LAVA_HPP_

#include <SFML/Graphics.hpp>

#include <constants.hpp>

#include "obstacle.hpp"

namespace bardadv::characters {
class Bardo;
}

namespace bardadv::obstacles {

class Lava : public bardadv::obstacles::Obstacle {

private:
    sf::RectangleShape* shape;
    static float hitDmg;

public:
    Lava(int posX, int posY);
    ~Lava();

    void collideX(Bardo* b);
    void collideY(Bardo* b);
    sf::FloatRect getBoundingBox() const;
    void draw(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    float getCollisionDmg();

};

}

#endif // LAVA_HPP_
