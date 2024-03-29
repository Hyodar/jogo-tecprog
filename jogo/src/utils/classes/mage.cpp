// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "mage.hpp"

// Standard libraries
// ---------------------

#include <cstdlib>
#include <cmath>
#include <iostream>

// Internal libraries
// ---------------------

#include "bardo.hpp"
#include "energy_ball.hpp"
#include "game.hpp"
#include "level_manager.hpp"
#include "graphics_manager.hpp"
#include <game_config.hpp>

using namespace bardadv::core;
using namespace bardadv::characters;
using namespace bardadv::projectiles;

// Methods
// ---------------------------------------------------------------------------

Mage::Mage(int x, int y, Bardo* pp)
 : Enemy(x, y, 68, 120, 100, pp, Points::MAGE_REWARD, CharacterClassification::MAGE),
   attackCounter{-rand() % 101},
   attackInterval{1700} {

    sprite.setTexture(*(GraphicsManager::getInstance()->getMageTexture()));
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Green);
}

// ---------------------------------------------------------------------------


Mage::Mage(int id, float hp, int x, int y, Bardo* pp)
 : Enemy(x, y, 68, 120, 100, pp, Points::MAGE_REWARD, CharacterClassification::MAGE),
   attackCounter{-rand() % 101},
   attackInterval{1700} {

    sprite.setTexture(*(GraphicsManager::getInstance()->getMageTexture()));
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Green);

    this->id = id;
    this->hitPoints = hp;
}

// ---------------------------------------------------------------------------

Mage::~Mage(){
    //noop
}

// ---------------------------------------------------------------------------

 void Mage::checkPlayerPos(){

    float playerpos = player->getPosX();
    const float dist = playerpos - position.x;

    if(abs(dist) < 600) {
        if(dist > 0) {
            speed.x = -walkSpeed/2;
        }
        else {
            speed.x = walkSpeed/2;
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

void Mage::update(const float deltaTime) {

}

// ---------------------------------------------------------------------------

void Mage::updatePositionX(float deltaTime) {
    checkPlayerPos();

    const float playerDistX = player->getPosX() - position.x;
    const float playerDistY = player->getPosY() - position.y;
    const float playerDist = sqrt(playerDistX*playerDistX + playerDistY*playerDistY);

    position.x += speed.x * deltaTime;

    if(attackCounter == attackInterval) {
        attackCounter = 0;
        if(playerDist < 600) launchEnergyBall();
    } else attackCounter++;
}

// ---------------------------------------------------------------------------

void Mage::updatePositionY(float deltaTime) {
    if(!onGround) speed.y += GRAV_ACC * deltaTime;

    position.y += speed.y * deltaTime;
    onGround = false;

    sprite.setPosition(sf::Vector2f(position.x, position.y));
    isInvulnerable();
}

// ---------------------------------------------------------------------------

void Mage::launchEnergyBall() {
    const float fireballSpeed = 500.0f;

    const float playerDistX = player->getPosX() - position.x;
    const float playerDistY = player->getPosY() - position.y;
    const float playerDist = sqrt(playerDistX*playerDistX + playerDistY*playerDistY);

    const float fireballSpeedX = fireballSpeed * (playerDistX / playerDist);
    const float fireballSpeedY = fireballSpeed * (playerDistY / playerDist);

    auto fb = new EnergyBall((walkingRight)? position.x : position.x + size.x, position.y, fireballSpeedX, fireballSpeedY);
    LevelManager::getInstance()->addProjectile(fb);
}
