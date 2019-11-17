
#ifndef BARDO_HPP_
#define BARDO_HPP_

#include <string>

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
    sf::FloatRect getBoundingBox() const;

    void collideX(Enemy* e);

    bool isAttacking();

    json store();

};

#endif // BARDO_HPP_
