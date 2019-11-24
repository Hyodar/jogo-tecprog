
// Libraries
// ---------------------------------------------------------------------------

// Standard libraries
// --------------------------

#include <cmath>

// Class header
// --------------------------

#include "flying_monster.hpp"

// Internal libraries
// --------------------------

#include "graphics_manager.hpp"
#include "game.hpp"
#include "bardo.hpp"

#include <game_config.hpp>

using namespace bardadv::core;
using namespace bardadv::characters;

// Methods
// ---------------------------------------------------------------------------

FlyingMonster::FlyingMonster(int x, int y, Bardo* pp)
 : Enemy(x, y, 90, 90, 80, pp, Points::FLYING_MONSTER_REWARD, CharacterClassification::FLYING_MONSTER),
   startingPos(x, y) {
    sprite.setTexture(*(GraphicsManager::getInstance()->getFlyingMonsterTexture()));
    sprite.setScale(2.5, 2.5);

    healthBar.setFillColor(sf::Color::Yellow);

    absoluteTime = 0;
}

// ---------------------------------------------------------------------------

FlyingMonster::FlyingMonster(int id, float hp, float abstime, int x, int y, Bardo* pp)
 : Enemy(x, y, 90, 90, 80, pp, Points::FLYING_MONSTER_REWARD, CharacterClassification::FLYING_MONSTER),
   startingPos(x, y) {
    sprite.setTexture(*(GraphicsManager::getInstance()->getFlyingMonsterTexture()));
    sprite.setScale(2.5, 2.5);

    healthBar.setFillColor(sf::Color::Yellow);

    this->id = id;
    this->hitPoints = hp;
    this->absoluteTime = abstime;
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

    position.x = startingPos.x + 200 * cos( 2.5 * absoluteTime);
}

// ---------------------------------------------------------------------------

void FlyingMonster::updatePositionY(const float deltaTime) {
    position.y = startingPos.y + 200 * cos( 2.5 * absoluteTime + (3.14/2));
    isInvulnerable();
}

// ---------------------------------------------------------------------------

void FlyingMonster::setAbsoluteTime(float absTime) {
    absoluteTime = absTime;
}

// ---------------------------------------------------------------------------

json FlyingMonster::store() {
    json j;

    j["id"] = id;
    j["playerId"] = player->getId();
    j["classification"] = classification;
    j["hp"] = hitPoints;
    j["startingPosX"] = startingPos.x;
    j["startingPosY"] = startingPos.y;
    j["timeCounter"] = absoluteTime;

    return j;
}
