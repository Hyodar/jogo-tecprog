
#ifndef FIEL_ESCUDEIRO_HPP_
#define FIEL_ESCUDEIRO_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "character.hpp"

namespace bardadv::characters {

class FielEscudeiro : public bardadv::characters::Character {

public:
    FielEscudeiro(int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0);
    void checkKeys();

    void updatePositionX(const float deltaTime);
    void updatePositionY(const float deltaTime);

    void isInvulnerable();
    void render(sf::RenderWindow& window);
};

}

#endif // FIEL_ESCUDEIRO_HPP_
