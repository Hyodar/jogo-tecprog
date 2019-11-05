
#ifndef SPIKE_HPP_
#define SPIKE_HPP_

#include <SFML/Graphics.hpp>

#include <constants.hpp>

#include "obstacle.hpp"
#include "collidable.hpp"
#include "tile_manager.hpp"
#include "game_map.hpp"
#include "game.hpp"

class Spike : public Obstacle {

private:
    sf::RectangleShape* shape;
    static float hitDmg;
    static sf::Vector2f spikeSize;

public:
    Spike(int posX, int posY);
    ~Spike();

    bool collide(Collidable& c);
    sf::FloatRect getBoundingBox() const;
    void draw(sf::RenderWindow& window);
};

#endif // SPIKE_HPP_
