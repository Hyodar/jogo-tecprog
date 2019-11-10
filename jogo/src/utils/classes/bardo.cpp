
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "bardo.hpp"

// Standard libraries
// ---------------------

#include <iostream>

// Internal libraries
// ---------------------

#include "game_map.hpp"
#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

sf::Texture Bardo::texture;

// Methods
// ---------------------------------------------------------------------------

Bardo::Bardo(int x, int y, int sizeX, int sizeY, double maxHP) 
   : Character(x, y, 64, 64, 100) {

    texture.loadFromFile("resources/bardo.png");

    sprite.setTexture(texture);
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Red);
}

// ---------------------------------------------------------------------------

void Bardo::checkKeys() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        speed.x = -walkSpeed;
        walkingRight = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        speed.x = walkSpeed;
        walkingRight = true;
    }
    else {
        speed.x = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        jump();
    }

}

// ---------------------------------------------------------------------------

void Bardo::updateStartPosition(float deltaTime) {
    if(GameMap::getInstance()->IsAtEnd()) {
        sprite.setPosition(sf::Vector2f(windowW + position.x - GameMap::getInstance()->getMapLength(), position.y));
    }
    else if(GameMap::getInstance()->IsAtStart()) {
        sprite.setPosition(position);
    }
    else {
        sprite.setPosition(sf::Vector2f(windowW/2, position.y));
    }
}

// ---------------------------------------------------------------------------
