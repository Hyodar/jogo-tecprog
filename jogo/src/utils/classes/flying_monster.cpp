// Libraries
#include <cmath>
// ---------------------------------------------------------------------------

// Class header
#include "flying_monster.hpp"
#include "graphics_manager.hpp"
#include "game.hpp"

// Internal libraries
#include <constants.hpp>

// Methods
// ---------------------------------------------------------------------------

FlyingMonster::FlyingMonster(int x, int y, Bardo* pp)
 : Enemy(x, y, 84, 128, 80, pp, Points::FLYING_MONSTER_REWARD, CharacterClassification::FLYING_MONSTER),
   startingPos(x, y) {
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

    position.x = startingPos.x + 200 * cos( 5 * absoluteTime);
}

// ---------------------------------------------------------------------------

void FlyingMonster::updatePositionY(const float deltaTime) {
    position.y = startingPos.y + 200 * cos( 5 * absoluteTime + (3.14/2));
    isInvulnerable();
}

// ---------------------------------------------------------------------------

void FlyingMonster::setAbsoluteTime(float absTime) {
    absoluteTime = absTime;
}

// ---------------------------------------------------------------------------

json FlyingMonster::store() {
    json j;

    j["classification"] = classification;
    j["hp"] = hitPoints;
    j["startingPosX"] = startingPos.x;
    j["startingPosY"] = startingPos.y;
    j["timeCounter"] = absoluteTime;

    return j;
}
