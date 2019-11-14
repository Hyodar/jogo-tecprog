#include "energy_ball.hpp"

#include "level_manager.hpp"

#include <SFML/Graphics.hpp>

#include <constants.hpp>

EnergyBall::EnergyBall(int posX, int posY, float speedX, float speedY, bool child)
 : Projectile(posX, posY, 3 * TILE_SIZE / 2, 3 * TILE_SIZE / 2, speedX, speedY) {
    shape.setTextureRect(sf::IntRect(TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    shape.setScale(0.9, 0.9);

    traveledDist = 0;
    alreadySplited = false;
    this->child = child;

    collisionDmg = 20;
}

EnergyBall::~EnergyBall() {
    /* noop */
}

void EnergyBall::updatePositionX(const float deltaTime){

    traveledDist += speed.x * deltaTime;

    position.x += speed.x * deltaTime;

    if(traveledDist > 100 && !alreadySplited && !child) {
        split();
    }
}

void EnergyBall::updatePositionY(const float deltaTime){

    position.y += speed.y * deltaTime;
}

void EnergyBall::split(){

    auto pb = new EnergyBall(position.x, position.y, 1.2*speed.x, 1.2*speed.y, true);
    LevelManager::getInstance()->addProjectile(pb);

    pb = new EnergyBall(position.x, position.y, 1.2*speed.x, -1.2*(speed.y), true);
    LevelManager::getInstance()->addProjectile(pb);

    alreadySplited = true;
}
