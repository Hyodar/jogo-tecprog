
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "box.hpp"

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"
#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

sf::Vector2f Box::boxSize(2*TILE_SIZE, 2*TILE_SIZE);
int Box::obstacleNum = 2;

// Methods
// ---------------------------------------------------------------------------

Box::Box(int posX, int posY) : Obstacle(posX, posY, Box::boxSize.x, Box::boxSize.y, ObstacleClassification::BOX) {
    shape = new sf::RectangleShape(sf::Vector2f(2*TILE_SIZE, 2*TILE_SIZE));
    shape->setTexture(GraphicsManager::getInstance()->getTileSheetTexture());
    shape->setTextureRect(sf::IntRect(7*TILE_SIZE, 0, 2*TILE_SIZE, 2*TILE_SIZE));
}

// ---------------------------------------------------------------------------

Box::~Box() {
    delete shape;
}

// ---------------------------------------------------------------------------

void Box::takeDamage(float dmg) {
    // noop
}

// ---------------------------------------------------------------------------

sf::FloatRect Box::getBoundingBox() const {
    return sf::FloatRect(position.x, position.y, size.x, size.y);
}

// ---------------------------------------------------------------------------

void Box::render(sf::RenderWindow& window) {
    shape->setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
    window.draw(*shape);
    //if(position.x < playerPos.x + WINDOW_W/2 && position.y > playerPos.x - WINDOW_W/2) {
}
