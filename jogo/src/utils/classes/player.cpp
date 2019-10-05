
#include "player.hpp"
#include "game_map.hpp"
#include <iostream>
#include <constants.hpp>

sf::Texture Player::texture;
const int Player::jumpSpeed = 2000;
const int Player::walkSpeed = 500;

Player::Player(int x, int y) : speed(600, 0), position(x, y), size(64, 64), onGround{false} {
    texture.loadFromFile("resources/player.png");

    sprite.setTexture(texture);
    sprite.setScale(2, 2);
}

void Player::update(const float deltaTime) {

    /*
    if(position.y + size.y -windowH > -20) {
        position.y = windowH - size.y;
    } else if(position.y + size.y < windowH){
        // FIXME - speed.y += gravAcc;
    }
    */
    if(!onGround) speed.y += gravAcc * deltaTime;
    
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

    position.x += speed.x * deltaTime;
    checkCollisionX();
    position.y += speed.y * deltaTime;
    onGround = false;
    checkCollisionY();

}

void Player::render(sf::RenderWindow& window) {
    if(GameMap::IsAtEnd()) {
        sprite.setPosition(sf::Vector2f(windowW + position.x - GameMap::getMapLength(), position.y));
    }
    else if(GameMap::IsAtStart()) {
        sprite.setPosition(position);
    }
    else {
        sprite.setPosition(sf::Vector2f(windowW/2, position.y));
    }

    window.draw(sprite);
}

void Player::jump() {
    if(onGround) {
        speed.y -= jumpSpeed;
        onGround = false;
    }
}

void Player::checkCollisionX() {
    for(int i = position.y/COLLISION_TILE_SIZE; i < (position.y + size.y)/COLLISION_TILE_SIZE; i++) {
        for(int j = position.x/COLLISION_TILE_SIZE; j < (position.x + size.x)/COLLISION_TILE_SIZE; j++) {
            if(GameMap::getCollisionTile(i, j).collide()) {       
                if(speed.x > 0) position.x = j * COLLISION_TILE_SIZE - size.x; 
                else if(speed.x < 0) position.x = j * COLLISION_TILE_SIZE + COLLISION_TILE_SIZE;
                speed.x = 0;
                return;
            }
        }
    }
}
                    
void Player::checkCollisionY() {
    for(int i = position.y/COLLISION_TILE_SIZE; i < (position.y + size.y)/COLLISION_TILE_SIZE; i++) {
        for(int j = position.x/COLLISION_TILE_SIZE; j < (position.x + size.x)/COLLISION_TILE_SIZE; j++) {
            if(GameMap::getCollisionTile(i, j).collide()) {       
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