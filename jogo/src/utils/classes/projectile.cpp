
#include "projectile.hpp"

#include "game_map.hpp"
#include "graphics_manager.hpp"
#include <constants.hpp>

Projectile::Projectile(int posX, int posY, int sizeX, int sizeY, float speedX, float speedY)
 : Entity(posX, posY, sizeX, sizeY), speed(speedX, speedY), shape(sf::Vector2f(sizeX, sizeY)) {
    shape.setTexture(GraphicsManager::getInstance()->getProjectileTexture());
    traveledDist = 0;
}

Projectile::~Projectile() {
    /* noop */
}

float Projectile::getTraveledDist() const {
    return traveledDist;
}

void Projectile::updatePositionX(const float deltaTime) {

    traveledDist += speed.x * deltaTime;

    position.x += speed.x * deltaTime;
}

void Projectile::updatePositionY(const float deltaTime) {
    position.y += speed.y * deltaTime;
}

void Projectile::render(sf::RenderWindow& window) {
    shape.setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
    window.draw(shape);
}

float Projectile::getCollisionDmg() {
    return collisionDmg;
}

void Projectile::takeDamage(float dmg) {
    // noop
}
