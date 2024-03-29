
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "character.hpp"

// Internal libraries
// ---------------------

#include "game_map.hpp"

#include "obstacle.hpp"
#include "tile.hpp"

using namespace bardadv::map;
using namespace bardadv::obstacles;
using namespace bardadv::characters;

// Attribute initialization
// ---------------------------------------------------------------------------

const int Character::jumpSpeed{1470};
const int Character::walkSpeed{500};

// Methods
// ---------------------------------------------------------------------------

Character::Character (int x, int y, int sizeX, int sizeY, double maxHP, int classification, int _invulnerabilityTicks)
    : Entity(x, y, sizeX, sizeY, classification), healthBar(sf::Vector2f(64, HEALTH_BAR_HEIGHT)),
      speed(0, 0), hitPoints{maxHP}, maxHitPoints(maxHP), onGround{false},
      invulnerable{0}, invulnerabilityTicks{_invulnerabilityTicks}, walkingRight{true} {

    // noop
}

// ---------------------------------------------------------------------------

Character::~Character() {
    // noop
}

// ---------------------------------------------------------------------------

void Character::jump(const float factor) {
    if(onGround) {
        speed.y -= jumpSpeed * factor;
        onGround = false;
    }
}

// ---------------------------------------------------------------------------

void Character::update(const float deltaTime) {
    // noop
}

// ---------------------------------------------------------------------------

void Character::isInvulnerable() {
    if(invulnerable) {
        invulnerable--;
        sprite.setColor(sf::Color(255, 255, 255, 128));
    } else sprite.setColor(sf::Color(255, 255, 255, 255));
}

// ---------------------------------------------------------------------------

void Character::takeDamage(float dmg) {
    if(invulnerable <= 0) {
        hitPoints -= dmg;
        invulnerable = invulnerabilityTicks;
    }
}

// ---------------------------------------------------------------------------

const bool Character::isAlive() const {
    return hitPoints > 0;
}

// ---------------------------------------------------------------------------

void Character::setOnGround(bool b) {
    onGround = b;
}

// ---------------------------------------------------------------------------

float Character::getSpeedX() const {
    return speed.x;
}

// ---------------------------------------------------------------------------

float Character::getSpeedY() const {
    return speed.y;
}

// ---------------------------------------------------------------------------

void Character::setSpeedX(float s) {
    speed.x = s;
}

// ---------------------------------------------------------------------------

void Character::setSpeedY(float s) {
    speed.y = s;
}

// ---------------------------------------------------------------------------

float Character::getHP() const {
    return hitPoints;
}

// ---------------------------------------------------------------------------

void Character::setHP(float hp) {
    hitPoints = hp;
}

// ---------------------------------------------------------------------------

void Character::updatePositionX(float deltaTime) {

    position.x += speed.x * deltaTime;
}

// ---------------------------------------------------------------------------

void Character::updatePositionY(float deltaTime) {
    if(!onGround) speed.y += GRAV_ACC * deltaTime;

    position.y += speed.y * deltaTime;
    onGround = false;

    isInvulnerable();
}

// ---------------------------------------------------------------------------

void Character::render(sf::RenderWindow& window) {

    sprite.setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);

    const auto scale = sprite.getScale().x;

    if(walkingRight) {
        sprite.setTextureRect(sf::IntRect(0, 0, size.x/scale, size.y/scale));
        healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    }
    else {
        sprite.setTextureRect(sf::IntRect(size.x/scale, 0, -size.x/scale, size.y/scale));
        healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    }

    //healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    healthBar.setSize(sf::Vector2f((hitPoints > 0)? (hitPoints/maxHitPoints) * size.x : 0, HEALTH_BAR_HEIGHT));

    window.draw(sprite);
    window.draw(healthBar);
}

// ---------------------------------------------------------------------------

void Character::collideY(Tile* t) {
    if(getSpeedY() > 0) {
        setPosY(t->getBoundingBox().top - getSizeY());
        setOnGround(true);
    }
    else if(getSpeedY() < 0) setPosY(t->getBoundingBox().top + t->getBoundingBox().height);
    setSpeedY(0);
}

// ---------------------------------------------------------------------------

void Character::collideX(Tile* t) {
    if(getSpeedX() > 0) {
        setPosX(t->getBoundingBox().left - getSizeX());
    }
    else if(getSpeedX() < 0) setPosX(t->getBoundingBox().left + t->getBoundingBox().width);
    setSpeedX(0);
}

// ---------------------------------------------------------------------------

void Character::collideY(Obstacle* o) {
    if(getSpeedY() > 0) {
        setPosY(o->getBoundingBox().top - getSizeY());
        setOnGround(true);
    }
    else if(getSpeedY() < 0) setPosY(o->getBoundingBox().top + o->getBoundingBox().height);
    setSpeedY(0);
}

// ---------------------------------------------------------------------------

void Character::collideX(Obstacle* o) {
    if(getSpeedX() > 0) {
        setPosX(o->getBoundingBox().left - getSizeX());
    }
    else if(getSpeedX() < 0) setPosX(o->getBoundingBox().left + o->getBoundingBox().width);
    setSpeedX(0);
}

// ---------------------------------------------------------------------------

json Character::store() {
    json j;

    j["id"] = id;
    j["classification"] = classification;
    j["hp"] = hitPoints;
    j["posX"] = position.x;
    j["posY"] = position.y;

    return j;
}
