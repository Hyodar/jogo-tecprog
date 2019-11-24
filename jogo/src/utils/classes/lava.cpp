// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "lava.hpp"

// Class header
// ---------------------

#include "graphics_manager.hpp"
#include "game_map.hpp"
#include "bardo.hpp"

#include <game_config.hpp>

using namespace bardadv::core;
using namespace bardadv::map;
using namespace bardadv::obstacles;
using namespace bardadv::characters;

// Attribute initialization
// ---------------------------------------------------------------------------

float Lava::hitDmg = 20;

// Methods
// ---------------------------------------------------------------------------

Lava::Lava(int posX, int posY) : Obstacle(posX, posY, 64, 64, ObstacleClassification::LAVA) {
    shape = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    shape->setTexture(GraphicsManager::getInstance()->getTileSheetTexture());
    shape->setTextureRect(sf::IntRect(6*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
}

// ---------------------------------------------------------------------------

Lava::~Lava(){
    delete shape;
}

// ---------------------------------------------------------------------------

void Lava::collideX(Bardo* b){
    b->takeDamage(getCollisionDmg());
    b->jump(0.5);
    b->burn();
}

// ---------------------------------------------------------------------------

void Lava::collideY(Bardo* b){
    b->takeDamage(getCollisionDmg());
    b->jump(0.5);
    b->burn();
}

// ---------------------------------------------------------------------------

sf::FloatRect Lava::getBoundingBox() const {
    return sf::FloatRect(position.x, position.y + 10, size.x, size.y - 10);
}

// ---------------------------------------------------------------------------

void Lava::draw(sf::RenderWindow& window) {
    shape->setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
    window.draw(*shape);
    //if(position.x < playerPos.x + WINDOW_W/2 && position.y > playerPos.x - WINDOW_W/2) {
}

// ---------------------------------------------------------------------------

void Lava::render(sf::RenderWindow& window) {
     draw(window);
 }

 // ---------------------------------------------------------------------------

float Lava::getCollisionDmg() {
     return hitDmg;
 }
