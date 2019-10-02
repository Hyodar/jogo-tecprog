
#include "player.hpp"

#include <iostream>

Player::Player(int x, int y) : speed(6, 0), position(x, y) {
    sf::Texture texture;
    texture.loadFromFile("resources/player.png");

    sprite.setTexture(texture);
}

void Player::update(const float deltaTime) {
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position.x -= speed.x * deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(!speed.y) speed.y -= 10;
        //position.x -= speed.y * deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position.x += speed.x * deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(speed.y) speed.y += 2.5;
        //position.y += speed.y * deltaTime;
    }
    std::cout << position.x << ", " << position.y << std::endl;
}

void Player::render(sf::RenderWindow& window) {
    sprite.setPosition(position);
    window.draw(sprite);
}

