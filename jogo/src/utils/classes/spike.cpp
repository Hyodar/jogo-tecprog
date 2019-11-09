
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "spike.hpp"

// Standard libraries
// ---------------------------------------------------------------------------

// Internal libraries
// ---------------------------------------------------------------------------

// Attribute initialization
float Spike::hitDmg = 20;
sf::Vector2f Spike::spikeSize(TILE_SIZE, TILE_SIZE);
int Spike::obstacleNum = 0;

// Methods
// ---------------------------------------------------------------------------
Spike::Spike(int posX, int posY) :
    Obstacle(posX, posY, Spike::spikeSize.x, Spike::spikeSize.y) {
    shape = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    shape->setTexture(TileManager::getInstance()->getTileSetTexture());
    shape->setTextureRect(sf::IntRect(5*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
}

// ---------------------------------------------------------------------------

Spike::~Spike() {
    delete shape;
}

// ---------------------------------------------------------------------------

bool Spike::collide(Collidable& c) {
    if(c.getBoundingBox().intersects(getBoundingBox())) {
        c.takeDamage(hitDmg);
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------------

sf::FloatRect Spike::getBoundingBox() const {
    return sf::FloatRect(position.x, position.y, size.x, size.y);
}

// ---------------------------------------------------------------------------

void Spike::draw(sf::RenderWindow& window) {
    shape->setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
    window.draw(*shape);
    //if(position.x < playerPos.x + windowW/2 && position.y > playerPos.x - windowW/2) {
}

// ---------------------------------------------------------------------------

std::vector<float> Spike::store() {
    std::vector<float> resp;
    
    resp.push_back(ObstacleClassification::SpikeObstacle);
    resp.push_back(position.x);
    resp.push_back(position.y);
    
    return resp;
}
