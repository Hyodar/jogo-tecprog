
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "box.hpp"

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"
#include "game_map.hpp"
#include "game.hpp"

#include <constants.hpp>

using namespace bardadv::core;
using namespace bardadv::map;
using namespace bardadv::obstacles;

// Methods
// ---------------------------------------------------------------------------

Box::Box(int posX, int posY) : Obstacle(posX, posY, 128, 128, ObstacleClassification::BOX) {
    shape = new sf::RectangleShape(sf::Vector2f(2*TILE_SIZE, 2*TILE_SIZE));
    shape->setTexture(GraphicsManager::getInstance()->getTileSheetTexture());
    shape->setTextureRect(sf::IntRect(7*TILE_SIZE, 0, 2*TILE_SIZE, 2*TILE_SIZE));
}

// ---------------------------------------------------------------------------

Box::~Box() {
    delete shape;
}

// ---------------------------------------------------------------------------

void Box::collideX(Bardo* b){
    //noop
};

// ---------------------------------------------------------------------------

void Box::collideY(Bardo* b){
    //noop 
};

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
