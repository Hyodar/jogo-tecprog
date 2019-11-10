
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "fiel_escudeiro.hpp"

// Internal libraries
// ---------------------

#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

sf::Texture FielEscudeiro::texture;

// Methods
// ---------------------------------------------------------------------------

FielEscudeiro::FielEscudeiro(int x, int y, int sizeX, int sizeY, double maxHP) 
   : Character(x, y, 64, 64, 100) {

    texture.loadFromFile("resources/fiel_escudeiro.png");

    sprite.setTexture(texture);
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Red);
}

// ---------------------------------------------------------------------------

void FielEscudeiro::checkKeys() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        speed.x = -walkSpeed;
        walkingRight = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        speed.x = walkSpeed;
        walkingRight = true;
    }
    else {
        speed.x = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        jump();
    }

}
