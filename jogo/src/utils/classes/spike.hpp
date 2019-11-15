
#ifndef SPIKE_HPP_
#define SPIKE_HPP_

#include <SFML/Graphics.hpp>

#include <constants.hpp>

#include "obstacle.hpp"
#include "game.hpp"

class Spike : public Obstacle {

private:
    sf::RectangleShape* shape;
    static float hitDmg;
    static sf::Vector2f spikeSize;
    static int obstacleNum;

public:
    Spike(int posX, int posY);
    ~Spike();

    sf::FloatRect getBoundingBox() const;
    void draw(sf::RenderWindow& window);
    void render(sf::RenderWindow& window) { draw(window); }
    void updatePosition(float deltaTime) { /* DELETE SOON */ }

    float getCollisionDmg() { return hitDmg; }
    
};

#endif // SPIKE_HPP_
