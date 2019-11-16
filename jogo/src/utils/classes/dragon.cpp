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
#include <constants.hpp>

// Methods
// ---------------------------------------------------------------------------

Dragon::Dragon(int x, int y, Bardo* pp)
   : Enemy(x, y, 256, 256, 1000, pp, Points::DRAGON_REWARD, CharacterClassification::DRAGON),
     attackCounter{-rand() % 101}, attackInterval{rand() % 501} {

    sprite.setTexture(*(GraphicsManager::getInstance()->getSkeletonTexture()));
    sprite.setScale(4, 4);

    healthBar.setFillColor(sf::Color::Blue);
}

// ---------------------------------------------------------------------------

Dragon::~Dragon(){
    //noop
}

// ---------------------------------------------------------------------------

void Dragon::checkPlayerPos(){

    float playerpos = player->getPosX();
    const float dist = playerpos - position.x;

    if(abs(dist) < 600) {
        if(dist > 0) {
            speed.x = walkSpeed/2;
        }
        else {
            speed.x = -walkSpeed/2;
        }

        // pra prevenir q os esqueletos fiquem girando sem parar
        // quando tao perto do player

        if(abs(dist) > 20) {
            walkingRight = (speed.x >= 0);
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

    const float playerDistX = player->getPosX() - position.x;
    const float playerDistY = player->getPosY() - position.y;
    const float playerDist = sqrt(playerDistX*playerDistX + playerDistY*playerDistY);

    const float fireballSpeedX = fireballSpeed * (playerDistX / playerDist);
    const float fireballSpeedY = fireballSpeed * (playerDistY / playerDist);

    auto fb = new Fireball((walkingRight)? position.x + size.x : position.x, position.y, fireballSpeedX, fireballSpeedY);
    LevelManager::getInstance()->addProjectile(fb);
}
