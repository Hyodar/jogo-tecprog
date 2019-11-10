
#ifndef BARDO_HPP_
#define BARDO_HPP_

#include <SFML/Graphics.hpp>

#include "character.hpp"

class Bardo : public Character {

public:
    Bardo(int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0);
    void updateStartPosition(float deltaTime);
    void checkKeys();

};

#endif // BARDO_HPP_
