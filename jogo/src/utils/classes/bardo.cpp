
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "bardo.hpp"

// Standard libraries
// ---------------------

#include <iostream>
#include <chrono>

// Internal libraries
// ---------------------

#include "game.hpp"
#include "game_map.hpp"
#include "graphics_manager.hpp"
#include "enemy.hpp"
#include <game_config.hpp>

using namespace bardadv::core;
using namespace bardadv::map;
using namespace bardadv::characters;

// Attribute initialization
// ---------------------------------------------------------------------------

std::mutex* Bardo::invulnerabilityMutex = new std::mutex();

// Methods
// ---------------------------------------------------------------------------

Bardo::Bardo(int x, int y, int sizeX, int sizeY, double maxHP)
 : Character(x, y, 64, 64, 1000, CharacterClassification::BARDO, 40),
   attackCounter{0}, attackInterval{300}, onFireCounter{200},
   invulnerabilityThread{nullptr}, onFireThread{nullptr} {

    sprite.setTexture(*(GraphicsManager::getInstance()->getBardoTexture()));
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Red);
}

// ---------------------------------------------------------------------------

Bardo::~Bardo() {
    hitPoints = 0;

    if(invulnerabilityThread) {
        invulnerabilityThread->join();
        onFireThread->join();

        delete invulnerabilityThread;
        delete onFireThread;
    }
}

// ---------------------------------------------------------------------------

void Bardo::checkKeys() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        speed.x = -walkSpeed;
        walkingRight = false;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        speed.x = walkSpeed;
        walkingRight = true;
    }
    else {
        speed.x = 0;
    }

    if(attackCounter) attackCounter--;
    else if(attackInterval) attackInterval--;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        resetAttackCounter();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        jump();
    }

}

// ---------------------------------------------------------------------------

void Bardo::updateStartPosition() {
    if(GameMap::getInstance()->IsAtEnd()) {
        sprite.setPosition(sf::Vector2f(WINDOW_W + position.x - GameMap::getInstance()->getMapLength(), position.y));
    }
    else if(GameMap::getInstance()->IsAtStart()) {
        sprite.setPosition(position);
    }
    else {
        sprite.setPosition(sf::Vector2f(WINDOW_W/2, position.y));
    }
}

// ---------------------------------------------------------------------------

void Bardo::render(sf::RenderWindow& window) {

    if(attackCounter) attackCounter--;

    updateStartPosition();

    sprite.setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);

    if(walkingRight) {
        if(attackCounter) sprite.setTextureRect(sf::IntRect(32, 0, 47, 32));
        else sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
        healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    }
    else {
        if(attackCounter) sprite.setTextureRect(sf::IntRect(79, 0, -49, 32));
        else sprite.setTextureRect(sf::IntRect(32, 0, -32, 32));
        healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    }

    if(invulnerable) {
        sprite.setColor(sf::Color(255, 255, 255, 128));
    }
    else {
        sprite.setColor(sf::Color(255, 255, 255, 255));
    }

    //healthBar.setPosition(sprite.getPosition() + sf::Vector2f(0, -40));
    healthBar.setSize(sf::Vector2f((hitPoints > 0)? (hitPoints/maxHitPoints) * size.x : 0, HEALTH_BAR_HEIGHT));

    window.draw(sprite);
    window.draw(healthBar);
}

// ---------------------------------------------------------------------------

sf::FloatRect Bardo::getBoundingBox() const{
    return sf::FloatRect(position.x, position.y, size.x, size.y);
}

// ---------------------------------------------------------------------------

sf::FloatRect Bardo::getAttackBoundingBox() const{
    if(attackCounter) {
        if(walkingRight) return sf::FloatRect(position.x, position.y, size.x + 30, size.y);
        return sf::FloatRect(position.x - 30, position.y, size.x, size.y);
    }
    return sf::FloatRect(position.x, position.y, size.x, size.y);
}

// ---------------------------------------------------------------------------

void Bardo::resetAttackCounter() {
    if(!attackInterval && !attackCounter) {
        attackCounter = 200;
        attackInterval = 300;
    }
}

// ---------------------------------------------------------------------------

void Bardo::collideX(Enemy* e) {
    if(attackCounter) {
        if(walkingRight && e->getPosX() > position.x) {
            e->takeDamage(100);
            e->jump(0.5);
            e->setSpeedX(0);
        }
        else if(!walkingRight && e->getPosX() < position.x) {
            e->takeDamage(100);
            e->jump(0.5);
            e->setSpeedX(0);
        }
    }
}
// ---------------------------------------------------------------------------

void Bardo::updatePositionX(float deltaTime) {
    checkKeys();

    position.x += speed.x * deltaTime;
}

// ---------------------------------------------------------------------------

void Bardo::updatePositionY(float deltaTime) {
    if(!onGround) speed.y += GRAV_ACC * deltaTime;

    position.y += speed.y * deltaTime;
    onGround = false;

    if(onFireCounter > 0) onFireCounter -= 1;
}

// ---------------------------------------------------------------------------

void Bardo::checkInvulnerability() {
    while(isAlive()) {
        if(Game::getInstance()->getGameState() == Game::GameState::PLAYING) {
            invulnerabilityMutex->lock();
            if(invulnerable > 0) {
                invulnerable -= 1;
            }
            invulnerabilityMutex->unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// ---------------------------------------------------------------------------

void Bardo::checkOnFire() {
    while(isAlive()) {
        if(Game::getInstance()->getGameState() == Game::GameState::PLAYING) {
            if(onFireCounter > 0) {
                invulnerabilityMutex->lock();
                if(invulnerable > 0) {
                    invulnerable -= 1;
                }
                invulnerabilityMutex->unlock();
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// ---------------------------------------------------------------------------

void Bardo::burn() {
    onFireCounter = 200;
}

// ---------------------------------------------------------------------------

bool Bardo::isAttacking() {
    return attackCounter;
}

// ---------------------------------------------------------------------------

json Bardo::store() {
    json j;

    j["id"] = id;
    j["classification"] = classification;
    j["hp"] = hitPoints;
    j["posX"] = position.x;
    j["posY"] = position.y;

    return j;
}

// ---------------------------------------------------------------------------

void Bardo::initThreads() {
    invulnerabilityThread = new std::thread([this] { this->checkInvulnerability(); });
    onFireThread = new std::thread([this] { this->checkOnFire(); });
}
