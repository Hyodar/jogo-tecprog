
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "bardo.hpp"

// Standard libraries
#include <chrono>
#include <functional>
#include <future>
#include <iostream>

// Internal libraries
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
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        speed.x = walkSpeed;
    }
    else {
        speed.x = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        jump();
    }

}

// ---------------------------------------------------------------------------

void Bardo::updatePosition() {
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



/* DEPRECATED

void Bardo::checkCollisionX() {
    for(int i = position.y/COLLISION_TILE_SIZE; i < (position.y + size.y)/COLLISION_TILE_SIZE; i++) {
        for(int j = position.x/COLLISION_TILE_SIZE; j < (position.x + size.x)/COLLISION_TILE_SIZE; j++) {
            if(GameMap::getInstance()->getCollisionTile(i, j).collide(*this)) {
                if(speed.x > 0) position.x = j * COLLISION_TILE_SIZE - size.x;
                else if(speed.x < 0) position.x = j * COLLISION_TILE_SIZE + COLLISION_TILE_SIZE;
                speed.x = 0;
                return;
            }
        }
    }
}

void Bardo::checkCollisionY() {
    for(int i = position.y/COLLISION_TILE_SIZE; i < (position.y + size.y)/COLLISION_TILE_SIZE; i++) {
        for(int j = position.x/COLLISION_TILE_SIZE; j < (position.x + size.x)/COLLISION_TILE_SIZE; j++) {
            if(GameMap::getInstance()->getCollisionTile(i, j).collide(*this)) {
                if(speed.y > 0) {
                    position.y = i * COLLISION_TILE_SIZE - size.y;
                    onGround = true;
                }
                else if(speed.y < 0) position.y = i * COLLISION_TILE_SIZE + COLLISION_TILE_SIZE;
                speed.y = 0;
                return;
            }
        }
    }
}
*/