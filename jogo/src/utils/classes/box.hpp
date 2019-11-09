
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

    float durability;

public:
    Box(int posX, int posY);
    ~Box();

    bool collide(Collidable& c);
    void takeDamage(float dmg);
    sf::FloatRect getBoundingBox() const;
    void draw(sf::RenderWindow& window);
    void updatePosition(float deltaTime) { draw(Game::getInstance()->getMainWindow()); }

    std::vector<float> store();

};

#endif // BOX_HPP_
