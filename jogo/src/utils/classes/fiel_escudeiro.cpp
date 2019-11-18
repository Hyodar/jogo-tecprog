
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "fiel_escudeiro.hpp"

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"
#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

sf::Texture FielEscudeiro::texture;

// Methods
// ---------------------------------------------------------------------------

FielEscudeiro::FielEscudeiro(int x, int y, int sizeX, int sizeY, double maxHP) 
   : Character(x, y, 64, 64, 100, CharacterClassification::FIEL_ESCUDEIRO) {

    sprite.setTexture(*(GraphicsManager::getInstance()->getFielEscudeiroTexture()));
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

// ---------------------------------------------------------------------------

void FielEscudeiro::updatePositionX(float deltaTime) {
    checkKeys();

    position.x += speed.x * deltaTime;
}

// ---------------------------------------------------------------------------

void FielEscudeiro::updatePositionY(float deltaTime) {
    if(!onGround) speed.y += GRAV_ACC * deltaTime;

    position.y += speed.y * deltaTime;
    onGround = false;

    isInvulnerable();
}
