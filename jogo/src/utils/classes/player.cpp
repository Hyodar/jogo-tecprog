
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "player.hpp"

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

sf::Texture Player::texture;
const int Player::jumpSpeed{2000};
const int Player::walkSpeed{500};

// Methods
// ---------------------------------------------------------------------------

Player::Player(int x, int y) :
    size(64, 64),  position(x, y), speed(0, 0),
    hitPoints{100}, maxHitPoints{100}, invulnerable{0},
    healthBar(sf::Vector2f(64, healthBarHeight)),
    onGround{false}
{
    texture.loadFromFile("resources/player.png");

    sprite.setTexture(texture);
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Red);
}

// ---------------------------------------------------------------------------

void Player::update(const float deltaTime) {

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

    isInvulnerable();
}

// ---------------------------------------------------------------------------

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

    healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    healthBar.setSize(sf::Vector2f((hitPoints > 0)? (hitPoints/maxHitPoints) * size.x : 0, healthBarHeight));

    window.draw(sprite);
    window.draw(healthBar);
}

// ---------------------------------------------------------------------------

void Player::jump() {
    if(onGround) {
        speed.y -= jumpSpeed;
        onGround = false;
    }
}

// ---------------------------------------------------------------------------

// TODO
// só tá adaptado pra colliders diferentes no Y de cima pra baixo

void Player::checkCollisionX() {
    for(int i = position.y/TILE_SIZE; i < (position.y + size.y)/TILE_SIZE; i++) {
        for(int j = position.x/TILE_SIZE; j < (position.x + size.x)/TILE_SIZE; j++) {
            Tile* tile = GameMap::getTile(i, j);
            if(tile->collide(*this)) {
                if(speed.x > 0) position.x = tile->getTileCollider().left - size.x;
                else if(speed.x < 0) position.x = tile->getTileCollider().left + tile->getTileCollider().width;
                speed.x = 0;
                return;
            }
        }
    }
}

// ---------------------------------------------------------------------------

void Player::checkCollisionY() {
    for(int i = position.y/TILE_SIZE; i < (position.y + size.y)/TILE_SIZE; i++) {
        for(int j = position.x/TILE_SIZE; j < (position.x + size.x)/TILE_SIZE; j++) {
            Tile* tile = GameMap::getTile(i, j);
            if(tile->collide(*this)) {
                if(speed.y > 0) {
                    position.y = tile->getTileCollider().top - size.y;
                    onGround = true;
                }
                else if(speed.y < 0) position.y = tile->getTileCollider().top + tile->getTileCollider().height;
                speed.y = 0;
                return;
            }
        }
    }
}

// ---------------------------------------------------------------------------

void Player::takeDamage(float dmg) {
    if(!invulnerable) {
        hitPoints -= dmg;
        invulnerable = INVULNERABILITY_TICKS;
    }
}

// ---------------------------------------------------------------------------

void Player::isInvulnerable() {
    if(invulnerable) {
        invulnerable--;
        sprite.setColor(sf::Color(255, 255, 255, 128));
    } else sprite.setColor(sf::Color::White);
}

/* DEPRECATED

void Player::checkCollisionX() {
    for(int i = position.y/COLLISION_TILE_SIZE; i < (position.y + size.y)/COLLISION_TILE_SIZE; i++) {
        for(int j = position.x/COLLISION_TILE_SIZE; j < (position.x + size.x)/COLLISION_TILE_SIZE; j++) {
            if(GameMap::getCollisionTile(i, j).collide(*this)) {
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
            if(GameMap::getCollisionTile(i, j).collide(*this)) {
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
