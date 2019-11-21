
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "fiel_escudeiro.hpp"

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"
#include "game_map.hpp"
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        invulnerable = 300;
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

// ---------------------------------------------------------------------------

void FielEscudeiro::isInvulnerable() {
    if(invulnerable) {
        invulnerable--;
        sprite.setColor(sf::Color(255, 255, 255, 255));
    }
}

// ---------------------------------------------------------------------------

void FielEscudeiro::render(sf::RenderWindow& window) {

    sprite.setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);

    if(walkingRight) {
        if (invulnerable) sprite.setTextureRect(sf::IntRect(32, 0, 40, 32));
        else sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
        healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    }
    else {
        if (invulnerable) sprite.setTextureRect(sf::IntRect(72, 0, -40, 32));
        else sprite.setTextureRect(sf::IntRect(32, 0, -32, 32));
        healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    }

    //healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    healthBar.setSize(sf::Vector2f((hitPoints > 0)? (hitPoints/maxHitPoints) * size.x : 0, HEALTH_BAR_HEIGHT));

    window.draw(sprite);
    window.draw(healthBar);
}
