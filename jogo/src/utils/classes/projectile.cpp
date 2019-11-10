
#include "projectile.hpp"

#include "game_map.hpp"
#include "graphics_manager.hpp"
#include <constants.hpp>

Projectile::Projectile(int posX, int posY, int sizeX, int sizeY, float speedX, float speedY) 
 : Entity(posX, posY, sizeX, sizeY), speed(speedX, speedY) {
    shape = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
    shape->setTexture(GraphicsManager::getInstance()->getProjectileTexture());
}

Projectile::~Projectile() {
    delete shape;
}

void Projectile::updatePositionX(const float deltaTime) {
    position.x += speed.x * deltaTime;
}

void Projectile::updatePositionY(const float deltaTime) {
    position.y += speed.y * deltaTime;
}

void Projectile::render(sf::RenderWindow& window) {
    shape->setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
    window.draw(*shape);
}
