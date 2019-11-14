
#ifndef BARDO_HPP_
#define BARDO_HPP_

#include <SFML/Graphics.hpp>

#include "character.hpp"

class Enemy;

class Bardo : public Character {

private:
    int attackCounter;
    int attackInterval;

    void resetAttackCounter();

public:
    Bardo(int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0);
    void updateStartPosition();
    void checkKeys();
    void render(sf::RenderWindow& window);
    sf::FloatRect getBoundingBox();

    void collideX(Enemy* e);
    void collideY(Enemy* e);

};

#endif // BARDO_HPP_
