
#include "fireball.hpp"

#include <SFML/Graphics.hpp>

#include <constants.hpp>

Fireball::Fireball(int posX, int posY, float speedX, float speedY)
 : Projectile(posX, posY, 3 * TILE_SIZE / 2, 3 * TILE_SIZE / 2, speedX, speedY, ProjectileClassification::FIREBALL) {
    shape.setTextureRect(sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
    shape.setScale(1.5, 1.5);
    
    collisionDmg = 20;
}

Fireball::~Fireball() {

}