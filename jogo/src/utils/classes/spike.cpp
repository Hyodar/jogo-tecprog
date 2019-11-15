
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "spike.hpp"

// Internal libraries
// ---------------------

#include "collidable.hpp"
#include "graphics_manager.hpp"
#include "game_map.hpp"
#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

float Spike::hitDmg = 20;
sf::Vector2f Spike::spikeSize(TILE_SIZE, TILE_SIZE);
int Spike::obstacleNum = 0;

// Methods
// ---------------------------------------------------------------------------

Spike::Spike(int posX, int posY) :
    Obstacle(posX, posY, Spike::spikeSize.x, Spike::spikeSize.y, ObstacleClassification::SPIKE) {
    shape = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    shape->setTexture(GraphicsManager::getInstance()->getTileSheetTexture());
    shape->setTextureRect(sf::IntRect(5*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
}

// ---------------------------------------------------------------------------

Spike::~Spike() {
    delete shape;
}

// ---------------------------------------------------------------------------

sf::FloatRect Spike::getBoundingBox() const {
    return sf::FloatRect(position.x, position.y, size.x, size.y);
}

// ---------------------------------------------------------------------------

void Spike::draw(sf::RenderWindow& window) {
    shape->setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
    window.draw(*shape);
}