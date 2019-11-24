// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "dragon.hpp"

// Standard libraries
// ---------------------

#include <cstdlib>
#include <cmath>
#include <iostream>

// Internal libraries
// ---------------------

#include "bardo.hpp"
#include "fireball.hpp"
#include "game.hpp"
#include "level_manager.hpp"
#include "graphics_manager.hpp"
#include <game_config.hpp>

using namespace bardadv::characters;
using namespace bardadv::projectiles;
using namespace bardadv::core;

// Methods
// ---------------------------------------------------------------------------

Dragon::Dragon(int x, int y, Bardo* pp)
   : Enemy(x, y, 320, 260, 1000, pp, Points::DRAGON_REWARD, CharacterClassification::DRAGON),
     attackCounter{-rand() % 101}, attackInterval{rand() % 501} {

    sprite.setTexture(*(GraphicsManager::getInstance()->getDragonTexture()));
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Blue);
}

// ---------------------------------------------------------------------------

Dragon::Dragon(int id, float hp, int x, int y, Bardo* pp)
   : Enemy(x, y, 320, 260, 1000, pp, Points::DRAGON_REWARD, CharacterClassification::DRAGON),
     attackCounter{-rand() % 101}, attackInterval{rand() % 501} {

    sprite.setTexture(*(GraphicsManager::getInstance()->getDragonTexture()));
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Blue);

    this->id = id;
    this->hitPoints = hp;
}

// ---------------------------------------------------------------------------

Dragon::~Dragon(){
    //noop
}

// ---------------------------------------------------------------------------

void Dragon::checkPlayerPos(){

    const float playerpos = player->getPosX();
    const float dist = (playerpos - position.x - size.x/2);

    if(abs(dist) < 600) {
        if(dist > 0) {
            speed.x = walkSpeed/2;
        }
        else {
            speed.x = -walkSpeed/2;
        }

        if(abs(dist) > 20) {
            walkingRight = (speed.x <= 0);
        }
    }
    else speed.x = 0;
 }

// ---------------------------------------------------------------------------

void Dragon::update(const float deltaTime) {

}

// ---------------------------------------------------------------------------

void Dragon::updatePositionX(float deltaTime) {
    checkPlayerPos();

    position.x += speed.x * deltaTime;

    if(attackCounter == attackInterval) {
        attackCounter = 0;
        attackInterval = rand() % 401;
        launchFireball();
    } else attackCounter++;
}

// ---------------------------------------------------------------------------

void Dragon::updatePositionY(float deltaTime) {
    if(!onGround) speed.y += GRAV_ACC * deltaTime;

    position.y += speed.y * deltaTime;
    onGround = false;

    sprite.setPosition(sf::Vector2f(position.x, position.y));
    isInvulnerable();
}

// ---------------------------------------------------------------------------

void Dragon::launchFireball() {
    const float fireballSpeed = 500.0f;

    float playerDistX;
    if(walkingRight) {
        playerDistX = player->getPosX() - position.x;
    }
    else {
        playerDistX = player->getPosX() - (position.x + size.x);
    }

    const float playerDistY = player->getPosY() - position.y;
    const float playerDist = sqrt(playerDistX*playerDistX + playerDistY*playerDistY);

    const float fireballSpeedX = fireballSpeed * (playerDistX / playerDist);
    const float fireballSpeedY = fireballSpeed * (playerDistY / playerDist);

    auto fb = new Fireball((walkingRight)? position.x : position.x + size.x, position.y, fireballSpeedX, fireballSpeedY);
    LevelManager::getInstance()->addProjectile(fb);
}
