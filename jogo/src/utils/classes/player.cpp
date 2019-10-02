
#include "player.hpp"

#include <iostream>

Player::Player(int x, int y) : speed(6, 0), position(x, y) {
    sf::Texture texture;
    texture.loadFromFile("resources/player.png");

    sprite.setTexture(texture);
}

void Player::move(sf::Keyboard::Key keycode) {
    switch(keycode) {
        case sf::Keyboard::Key::Left:
            position.x -= speed.x;
            break;
        case sf::Keyboard::Key::Up:
            speed.y = 6; // FIXME - provisorio para testes
            position.y -= speed.y;
            break;
        case sf::Keyboard::Key::Right:
            position.x += speed.x;
            break;
        case sf::Keyboard::Key::Down:
            speed.y = 6; // FIXME - provisorio para testes
            position.y += speed.y;
            break;
    }
    std::cout << position.x << ", " << position.y << std::endl;
}

void Player::render(sf::RenderWindow& window) {
    sprite.setPosition(position);
    window.draw(sprite);
}

