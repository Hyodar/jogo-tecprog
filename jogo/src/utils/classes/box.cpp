
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "box.hpp"

// Standard libraries
// ---------------------------------------------------------------------------

// Internal libraries
// ---------------------------------------------------------------------------

// Attribute initialization
sf::Vector2f Box::boxSize(64, 64);

// Methods
// ---------------------------------------------------------------------------
Box::Box(int posX, int posY) : Obstacle(posX, posY, Box::boxSize.x, Box::boxSize.y),
                          durability{100} {
    shape = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    shape->setTexture(TileManager::getInstance()->getTileSetTexture());
    shape->setTextureRect(sf::IntRect(5*TILE_SIZE, 0, 2*TILE_SIZE, 2*TILE_SIZE));
}

// ---------------------------------------------------------------------------

Box::~Box() {
    delete shape;
}

// ---------------------------------------------------------------------------

bool Box::collide(Collidable& c) {
    return c.getBoundingBox().intersects(getBoundingBox());
}

// ---------------------------------------------------------------------------

void Box::takeDamage(float dmg) {
    durability -= dmg;
}

// ---------------------------------------------------------------------------

sf::FloatRect Box::getBoundingBox() const {
    return sf::FloatRect(position.x, position.y, size.x, size.y);
}

// ---------------------------------------------------------------------------

void Box::draw(sf::RenderWindow& window) {
    shape->setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
    window.draw(*shape);
    //if(position.x < playerPos.x + windowW/2 && position.y > playerPos.x - windowW/2) {
}
