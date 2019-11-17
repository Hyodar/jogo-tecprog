
#ifndef BOX_HPP_
#define BOX_HPP_

#include <SFML/Graphics.hpp>

#include <constants.hpp>

#include "obstacle.hpp"
#include "collidable.hpp"
#include "tile_manager.hpp"
#include "game_map.hpp"
#include "game.hpp"

class Box : public Obstacle {

private:
    sf::RectangleShape* shape;
    static sf::Vector2f boxSize;
    static int obstacleNum;

public:
    Box(int posX, int posY);
    ~Box();

    void collideX(Bardo* b);
    void collideY(Bardo* b);
    void takeDamage(float dmg);
    sf::FloatRect getBoundingBox() const;
    void render(sf::RenderWindow& window);
    //void updatePosition(float deltaTime);

    float getCollisionDmg() { return 0; }

};

#endif // BOX_HPP_
