
#ifndef FIEL_ESCUDEIRO_HPP_
#define FIEL_ESCUDEIRO_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "character.hpp"

class FielEscudeiro : public Character {

protected:
    static sf::Texture texture;

public:
    FielEscudeiro(int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0);
    void checkKeys();

};

#endif // FIEL_ESCUDEIRO_HPP_
