// Libraries
#include <math.h>
// ---------------------------------------------------------------------------

// Class header
#include "flying_monster.hpp"
#include "graphics_manager.hpp"
#include "game.hpp"

// Standard libraries
#include <iostream>

// Internal libraries
#include <constants.hpp>

// Methods
// ---------------------------------------------------------------------------

FlyingMonster::FlyingMonster(int x, int y, Bardo* pp)
   : Enemy(x, y, 84, 128, 80, pp), startingPos(x, y) {
    sprite.setTexture(*(GraphicsManager::getInstance()->getSkeletonTexture()));
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Yellow);

    absoluteTime = 0;
}

// ---------------------------------------------------------------------------

FlyingMonster::~FlyingMonster(){
    //noop
}

// ---------------------------------------------------------------------------

void FlyingMonster::update(const float deltaTime) {

}

// ---------------------------------------------------------------------------

void FlyingMonster::updatePositionX(const float deltaTime) {
    absoluteTime += deltaTime;
    std::cout << absoluteTime << std::endl;
    position.x = startingPos.x + 200 * cos( 5 * absoluteTime);
}

// ---------------------------------------------------------------------------

void FlyingMonster::updatePositionY(const float deltaTime) {
    position.y = startingPos.y + 200 * cos( 5 * absoluteTime + (3.14/2));
}
