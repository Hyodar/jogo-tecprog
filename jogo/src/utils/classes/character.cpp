
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

#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

const int Character::jumpSpeed{1670};
const int Character::walkSpeed{500};

// Methods
// ---------------------------------------------------------------------------

Character::Character (int x, int y, int sizeX, int sizeY, double maxHP)
    : Entity(x, y, sizeX, sizeY), healthBar(sf::Vector2f(64, healthBarHeight)),
      speed(0, 0), hitPoints{100}, maxHitPoints(maxHP), onGround{false},
      invulnerable{0}, walkingRight{true} {

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

void Character::checkKeys() {
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
    if(!invulnerable) {
        hitPoints -= dmg;
        invulnerable = INVULNERABILITY_TICKS;
    }
}

// ---------------------------------------------------------------------------

void Character::updatePositionX(float deltaTime) {
    checkKeys();

    position.x += speed.x * deltaTime;
}

// ---------------------------------------------------------------------------

void Character::updatePositionY(float deltaTime) {
    if(!onGround) speed.y += gravAcc * deltaTime;

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
    healthBar.setSize(sf::Vector2f((hitPoints > 0)? (hitPoints/maxHitPoints) * size.x : 0, healthBarHeight));

    window.draw(sprite);
    window.draw(healthBar);
}

void Character::collideY(Tile* t) {
    if(getSpeedY() > 0) {
        setPosY(t->getBoundingBox().top - getSizeY());
        setOnGround(true);
    }
    else if(getSpeedY() < 0) setPosY(t->getBoundingBox().top + t->getBoundingBox().height);
    setSpeedY(0);
}

void Character::collideX(Tile* t) {
    if(getSpeedX() > 0) {
        setPosX(t->getBoundingBox().left - getSizeX());
    }
    else if(getSpeedX() < 0) setPosX(t->getBoundingBox().left + t->getBoundingBox().width);
    setSpeedX(0);
}

void Character::collideY(Obstacle* o) {
    if(getSpeedY() > 0) {
        setPosY(o->getBoundingBox().top - getSizeY());
        setOnGround(true);
    }
    else if(getSpeedY() < 0) setPosY(o->getBoundingBox().top + o->getBoundingBox().height);
    setSpeedY(0);
}

void Character::collideX(Obstacle* o) {
    if(getSpeedX() > 0) {
        setPosX(o->getBoundingBox().left - getSizeX());
    }
    else if(getSpeedX() < 0) setPosX(o->getBoundingBox().left + o->getBoundingBox().width);
    setSpeedX(0);
}