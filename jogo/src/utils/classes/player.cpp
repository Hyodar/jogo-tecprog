
#include "player.hpp"

void Player::move(sf::Keyboard::Key keycode) {
    switch(keycode) {
        case sf::Keyboard::Key::Left:
            position.x -= speed.x;
        case sf::Keyboard::Key::Up:
            position.y -= speed.y;
        case sf::Keyboard::Key::Right:
            position.x += speed.x;
        case sf::Keyboard::Key::Down:
            position.y += speed.y;
    }
}