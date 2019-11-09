// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "skeleton.hpp"
#include "game.hpp"

// Standard libraries
#include <iostream>

// Internal libraries
#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

sf::Texture Skeleton::texture;

// Methods
// ---------------------------------------------------------------------------

Skeleton::Skeleton(int x, int y, Bardo* pp)
   : Character(x, y, 84, 128, 100) {

    texture.loadFromFile("resources/skeleton.png");

    sprite.setTexture(texture);
    sprite.setScale(2, 2);

    healthBar.setFillColor(sf::Color::Blue);

    player = pp;
}

// ---------------------------------------------------------------------------

Skeleton::~Skeleton(){
    //noop
}

// ---------------------------------------------------------------------------

 void Skeleton::checkPlayerPos(){

     float playerpos = player->getPosX();

     if(abs(playerpos-position.x) < 600){
         if(playerpos-position.x > 0) speed.x = walkSpeed/2;
         else speed.x = -walkSpeed/2;
     }
     else
        speed.x = 0;
 }

// ---------------------------------------------------------------------------

void Skeleton::update(const float deltaTime) {
    
}

// ---------------------------------------------------------------------------

void Skeleton::updatePosition(float deltaTime) {
    if(!onGround) speed.y += gravAcc * deltaTime;

    checkPlayerPos();

    position.x += speed.x * deltaTime;
    if(checkMapCollisionX() || LevelManager::getInstance()->getEntityManager().checkCharacterXCollision(this)) {
        jump();
    } 
    position.y += speed.y * deltaTime;
    onGround = false;
    LevelManager::getInstance()->getEntityManager().checkCharacterYCollision(this);
    checkMapCollisionY();

    sprite.setPosition(sf::Vector2f(position.x, position.y));
    render(Game::getInstance()->getMainWindow());
}

// ---------------------------------------------------------------------------
