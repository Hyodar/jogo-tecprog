
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "character.hpp"

// Internal libraries
#include "game_map.hpp"
#include <constants.hpp>

#include "collision_resolver.hpp"

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

void Character::jump() {
    if(onGround) {
        speed.y -= jumpSpeed;
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

// ---------------------------------------------------------------------------

bool Character::collide(Collidable& e) {
    // DEPRECATED!!!!!!!!!!!!!
    if(!e.getBoundingBox().intersects(getBoundingBox())) return false;

    if(speed.y > 0) {
        position.y = e.getBoundingBox().top - size.y;
        onGround = true;
    }
    else if(speed.y < 0) position.y = e.getBoundingBox().top + e.getBoundingBox().height;
    speed.y = 0;

    if(speed.x > 0) {
        position.x = e.getBoundingBox().left - size.x;
    }
    else if(speed.x < 0) position.x = e.getBoundingBox().left + e.getBoundingBox().width;
    speed.x = 0;

    return true;
}
