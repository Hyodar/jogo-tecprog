// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "skeleton.hpp"

// Standard libraries
// ---------------------

#include <cstdlib>
#include <iostream>

// Internal libraries
// ---------------------

#include "bardo.hpp"
#include "game.hpp"
#include "graphics_manager.hpp"
#include <constants.hpp>

// Methods
// ---------------------------------------------------------------------------

Skeleton::Skeleton(int x, int y, Bardo* pp)
   : Enemy(x, y, 86, 128, 100, pp), jumpCounter{-rand() % 101},
     jumpInterval{rand() % 501} {

    sprite.setTexture(*(GraphicsManager::getInstance()->getSkeletonTexture()));
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Blue);
}

// ---------------------------------------------------------------------------

Skeleton::~Skeleton(){
    //noop
}

// ---------------------------------------------------------------------------

 void Skeleton::checkPlayerPos(){

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

void Skeleton::update(const float deltaTime) {
    
}

// ---------------------------------------------------------------------------

void Skeleton::updatePositionX(float deltaTime) {
    checkPlayerPos();

    position.x += speed.x * deltaTime;
    
    if(jumpCounter == jumpInterval) {
        jumpCounter = 0;
        jumpInterval = rand() % 401;
        jump();
    } else jumpCounter++;
}

// ---------------------------------------------------------------------------

void Skeleton::updatePositionY(float deltaTime) {
    if(!onGround) speed.y += gravAcc * deltaTime;

    position.y += speed.y * deltaTime;
    onGround = false;

    sprite.setPosition(sf::Vector2f(position.x, position.y));
    isInvulnerable();
}
