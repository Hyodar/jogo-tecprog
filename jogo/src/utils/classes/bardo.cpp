
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
#include "graphics_manager.hpp"
#include "enemy.hpp"
#include <constants.hpp>

// Methods
// ---------------------------------------------------------------------------

Bardo::Bardo(int x, int y, int sizeX, int sizeY, double maxHP) 
   : Character(x, y, 64, 64, 100), attackCounter{0}, attackInterval{300} {

    sprite.setTexture(*(GraphicsManager::getInstance()->getBardoTexture()));
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

    if(attackCounter) attackCounter--;
    else if(attackInterval) attackInterval--;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        resetAttackCounter();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        jump();
    }

}

// ---------------------------------------------------------------------------

void Bardo::updateStartPosition() {
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

void Bardo::render(sf::RenderWindow& window) {

    if(attackCounter) attackCounter--;

    updateStartPosition();

    sprite.setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);

    if(walkingRight) {
        if(attackCounter) sprite.setTextureRect(sf::IntRect(32, 0, 47, 32));
        else sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
        healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    }
    else {
        if(attackCounter) sprite.setTextureRect(sf::IntRect(79, 0, -49, 32));
        else sprite.setTextureRect(sf::IntRect(32, 0, -32, 32));
        healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    }

    //healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    healthBar.setSize(sf::Vector2f((hitPoints > 0)? (hitPoints/maxHitPoints) * size.x : 0, healthBarHeight));

    window.draw(sprite);
    window.draw(healthBar);
}

// ---------------------------------------------------------------------------

sf::FloatRect Bardo::getBoundingBox() {
    if(attackCounter) {
        if(walkingRight) return sf::FloatRect(position.x, position.y, size.x + 30, size.y);
        return sf::FloatRect(position.x - 30, position.y, size.x, size.y);
    }
    return sf::FloatRect(position.x, position.y, size.x, size.y);
}

// ---------------------------------------------------------------------------

void Bardo::resetAttackCounter() {
    if(!attackInterval && !attackCounter) {
        attackCounter = 200;
        attackInterval = 300;
    }
}

// ---------------------------------------------------------------------------

void Bardo::collideX(Enemy* e) {
    if(attackCounter) {
        e->takeDamage(50);
        e->jump(0.5);
    }
}