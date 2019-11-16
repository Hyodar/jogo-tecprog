// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "lava.hpp"

// Class header
// ---------------------

#include "graphics_manager.hpp"
#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

float Lava::hitDmg = 20;
sf::Vector2f Lava::lavaSize(TILE_SIZE, TILE_SIZE);
int Lava::obstacleNum = 1;

// Methods
// ---------------------------------------------------------------------------

Lava::Lava(int posX, int posY) : Obstacle(posX, posY, Lava::lavaSize.x, Lava::lavaSize.y, ObstacleClassification::LAVA) {
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
}

// ---------------------------------------------------------------------------

void Lava::collideY(Bardo* b){
    b->takeDamage(getCollisionDmg());
    b->jump(0.5);
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
