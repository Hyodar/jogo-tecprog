
#include "player.hpp"
#include "game_map.hpp"
#include <iostream>
#include <constants.hpp>

sf::Texture Player::texture;
const int Player::jumpSpeed = 2000;

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
        speed.x = -500;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        speed.x = 500;
    }
    else {
        speed.x = 0;
    }

    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        jump();
    }
    /*
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        speed.y = 500;
    }
    else {
        speed.y = 0;
    }
    */
    
    //position += speed * deltaTime;
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
    for(int i = position.y/TILE_SIZE; i < (position.y + size.y)/TILE_SIZE; i++) {
        for(int j = position.x/TILE_SIZE; j < (position.x + size.x)/TILE_SIZE; j++) {
            if(GameMap::getTile(i, j).collide()) {       
                if(speed.x > 0) position.x = j * TILE_SIZE - size.x; 
                else if(speed.x < 0) position.x = j * TILE_SIZE + TILE_SIZE;
                speed.x = 0;
            }
        }
    }
}
                    
void Player::checkCollisionY() {
    for(int i = position.y/TILE_SIZE; i < (position.y + size.y)/TILE_SIZE; i++) {
        for(int j = position.x/TILE_SIZE; j < (position.x + size.x)/TILE_SIZE; j++) {
            if(GameMap::getTile(i, j).collide()) {       
                if(speed.y > 0) { 
                    position.y = i * TILE_SIZE - size.y;
                    onGround = true;
                }
                else if(speed.y < 0) position.y = i * TILE_SIZE + TILE_SIZE;
                speed.y = 0;
            }
        }
    }
}