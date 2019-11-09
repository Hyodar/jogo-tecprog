
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "box.hpp"

// Standard libraries
// ---------------------------------------------------------------------------

// Internal libraries
// ---------------------------------------------------------------------------

// Attribute initialization
sf::Vector2f Box::boxSize(2*TILE_SIZE, 2*TILE_SIZE);
int Box::obstacleNum = 2;

// Methods
// ---------------------------------------------------------------------------
Box::Box(int posX, int posY) : Obstacle(posX, posY, Box::boxSize.x, Box::boxSize.y),
                          durability{100} {
    shape = new sf::RectangleShape(sf::Vector2f(2*TILE_SIZE, 2*TILE_SIZE));
    shape->setTexture(TileManager::getInstance()->getTileSetTexture());
    shape->setTextureRect(sf::IntRect(7*TILE_SIZE, 0, 2*TILE_SIZE, 2*TILE_SIZE));
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

// ---------------------------------------------------------------------------

std::vector<float> Box::store() {
    std::vector<float> resp;
    
    resp.push_back(ObstacleClassification::BoxObstacle);
    resp.push_back(position.x);
    resp.push_back(position.y);
    
    return resp;
}


