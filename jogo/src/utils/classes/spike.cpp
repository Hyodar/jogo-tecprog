
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "spike.hpp"

// Internal libraries
// ---------------------

#include "game.hpp"
#include "graphics_manager.hpp"
#include "game_map.hpp"
#include <constants.hpp>

using namespace bardadv::core;
using namespace bardadv::map;
using namespace bardadv::obstacles;

// Attribute initialization
// ---------------------------------------------------------------------------

float Spike::hitDmg = 20;

// Methods
// ---------------------------------------------------------------------------

Spike::Spike(int posX, int posY) :
    Obstacle(posX, posY, 64, 64, ObstacleClassification::SPIKE) {
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

// ---------------------------------------------------------------------------

void Spike::render(sf::RenderWindow& window) {
    draw(window);
}
