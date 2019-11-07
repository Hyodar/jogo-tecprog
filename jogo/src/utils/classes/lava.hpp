
#ifndef LAVA_HPP_
#define LAVA_HPP_

#include <SFML/Graphics.hpp>

#include <constants.hpp>

#include "obstacle.hpp"
#include "collidable.hpp"
#include "tile_manager.hpp"
#include "game_map.hpp"
#include "game.hpp"

class Lava : public Obstacle {

private:
    sf::RectangleShape* shape;
    static float hitDmg;
    static sf::Vector2f lavaSize;
    static int obstacleNum;

public:
    Lava(int posX, int posY);
    ~Lava();

    bool collide(Collidable& c);
    sf::FloatRect getBoundingBox() const;
    void draw(sf::RenderWindow& window);
    void updatePosition(float deltaTime) { draw(Game::getInstance()->getMainWindow()); }

};

#endif // LAVA_HPP_
