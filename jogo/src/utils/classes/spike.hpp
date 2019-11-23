
#ifndef SPIKE_HPP_
#define SPIKE_HPP_

#include <SFML/Graphics.hpp>

#include <constants.hpp>

#include "obstacle.hpp"

namespace bardadv::obstacles {

class Spike : public Obstacle {

private:
    sf::RectangleShape* shape;
    static float hitDmg;

public:
    Spike(int posX, int posY);
    ~Spike();

    sf::FloatRect getBoundingBox() const;
    void draw(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

    float getCollisionDmg() { return hitDmg; }

};

}

#endif // SPIKE_HPP_
