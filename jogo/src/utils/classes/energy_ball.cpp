#include "energy_ball.hpp"

#include "bardo.hpp"

#include <SFML/Graphics.hpp>

#include <constants.hpp>

EnergyBall::EnergyBall(int posX, int posY, float speedX, float speedY, Bardo* pp)
 : Projectile(posX, posY, 3 * TILE_SIZE / 2, 3 * TILE_SIZE / 2, speedX, speedY) {
    shape->setTextureRect(sf::IntRect(TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    shape->setScale(0.9, 0.9);

    player = pp;

    collisionDmg = 20;
}

EnergyBall::~EnergyBall() {
    delete shape;
}

void EnergyBall::updatePositionX(const float deltaTime){

    float playerpos = player->getPosX();
    const float dist = abs(playerpos - position.x);

    if(abs((position.x +speed.x*deltaTime) - playerpos) > dist) speed.x = speed.x * (-1/2);

    position.x += speed.x * deltaTime;

}

void EnergyBall::updatePositionY(const float deltaTime){
    float playerpos = player->getPosY();
    const float dist = abs(playerpos - position.y);

    if(abs((position.y +speed.y*deltaTime) -playerpos) > dist) speed.y = speed.y * (-2);

    position.y += speed.y * deltaTime;
}
