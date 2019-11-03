
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "character.hpp"

// Internal libraries
#include "game_map.hpp"
#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

const int Character::jumpSpeed{1670};
const int Character::walkSpeed{500};

// Methods
// ---------------------------------------------------------------------------

Character::Character (int x, int y, int sizeX, int sizeY, double maxHP)
    : Entity(x, y, sizeX, sizeY), speed(0, 0), hitPoints{100},
      maxHitPoints(maxHP), onGround{false}, invulnerable{0}, 
      healthBar(sf::Vector2f(64, healthBarHeight)) {

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
    if(!onGround) speed.y += gravAcc * deltaTime;

    checkKeys();

    position.x += speed.x * deltaTime;
    checkCollisionX();
    position.y += speed.y * deltaTime;
    onGround = false;
    checkCollisionY();

    isInvulnerable();
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
    } else sprite.setColor(sf::Color::Black);
}

// ---------------------------------------------------------------------------

void Character::takeDamage(float dmg) {
    if(!invulnerable) {
        hitPoints -= dmg;
        invulnerable = INVULNERABILITY_TICKS;
    }
}

// ---------------------------------------------------------------------------

void Character::updatePosition() {
    // noop
}

// ---------------------------------------------------------------------------

void Character::render(sf::RenderWindow& window) {
    updatePosition();    

    healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    healthBar.setSize(sf::Vector2f((hitPoints > 0)? (hitPoints/maxHitPoints) * size.x : 0, healthBarHeight));

    window.draw(sprite);
    window.draw(healthBar);
}

// ---------------------------------------------------------------------------

// TODO
// só tá adaptado pra colliders diferentes no Y de cima pra baixo

void Character::checkCollisionX() {
    for(int i = position.y/TILE_SIZE; i < (position.y + size.y)/TILE_SIZE; i++) {
        for(int j = position.x/TILE_SIZE; j < (position.x + size.x)/TILE_SIZE; j++) {
            Tile* tile = GameMap::getInstance()->getTile(i, j);
            if(tile->collide(*this)) {
                if(speed.x > 0) position.x = tile->getBoundingBox().left - size.x;
                else if(speed.x < 0) position.x = tile->getBoundingBox().left + tile->getBoundingBox().width;
                speed.x = 0;
                return;
            }
        }
    }
}

// ---------------------------------------------------------------------------

void Character::checkCollisionY() {
    for(int i = position.y/TILE_SIZE; i < (position.y + size.y)/TILE_SIZE; i++) {
        for(int j = position.x/TILE_SIZE; j < (position.x + size.x)/TILE_SIZE; j++) {
            Tile* tile = GameMap::getInstance()->getTile(i, j);
            if(tile->collide(*this)) {
                if(speed.y > 0) {
                    position.y = tile->getBoundingBox().top - size.y;
                    onGround = true;
                }
                else if(speed.y < 0) position.y = tile->getBoundingBox().top + tile->getBoundingBox().height;
                speed.y = 0;
                return;
            }
        }
    }
}