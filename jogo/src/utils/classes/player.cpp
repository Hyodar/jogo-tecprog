
#include "player.hpp"
#include <constants.hpp>

#include <iostream>

sf::Texture Player::texture;

Player::Player(int x, int y) : speed(600, 0), position(x, y), size(32, 32) {
    texture.loadFromFile("resources/player.png");

    sprite.setTexture(texture);
}

void Player::update(const float deltaTime) {

    if(position.y + size.y -windowH > -20) {
        position.y = windowH - size.y;
    } else if(position.y + size.y < windowH){
        // ta no ar
        speed.y += gravAcc;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        speed.x = -100;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        speed.x = 100;
    } else {
        speed.x = 0;
    }
    
    //position += speed * deltaTime;
    position += speed * deltaTime;

    std::cout << position.x << ", " << position.y << std::endl;
}

void Player::render(sf::RenderWindow& window) {
    sprite.setPosition(position);
    window.draw(sprite);
}

void Player::jump() {
    if(!speed.y) {
        speed.y -= 1000;
    }
}

