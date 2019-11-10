// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "lava.hpp"

// Attribute initialization
// ---------------------------------------------------------------------------

float Lava::hitDmg = 20;
sf::Vector2f Lava::lavaSize(TILE_SIZE, TILE_SIZE);
int Lava::obstacleNum = 1;

// Methods
// ---------------------------------------------------------------------------

Lava::Lava(int posX, int posY):
    Obstacle(posX, posY, Lava::lavaSize.x, Lava::lavaSize.y) {
    shape = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    shape->setTexture(TileManager::getInstance()->getTileSetTexture());
    shape->setTextureRect(sf::IntRect(6*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
}

// ---------------------------------------------------------------------------

Lava::~Lava(){
    delete shape;
}

// ---------------------------------------------------------------------------

sf::FloatRect Lava::getBoundingBox() const {
    return sf::FloatRect(position.x, position.y + 10, size.x, size.y - 10);
}

// ---------------------------------------------------------------------------

void Lava::draw(sf::RenderWindow& window) {
    shape->setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
    window.draw(*shape);
    //if(position.x < playerPos.x + windowW/2 && position.y > playerPos.x - windowW/2) {
}

// ---------------------------------------------------------------------------

std::vector<float> Lava::store() {
    std::vector<float> resp;
    
    resp.push_back(ObstacleClassification::LavaObstacle);
    resp.push_back(position.x);
    resp.push_back(position.y);
    
    return resp;
}
