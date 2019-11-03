
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "character.hpp"

class Bardo: public Character {

protected:
    static sf::Texture texture;

public:
    Bardo(int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0);
    void updatePosition();
    void checkKeys();

};

#endif // PLAYER_HPP_
