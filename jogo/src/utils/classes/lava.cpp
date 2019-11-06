// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "lava.hpp"

// Standard libraries
// ---------------------------------------------------------------------------

// Internal libraries
// ---------------------------------------------------------------------------

// Attribute initialization
float Lava::hitDmg = 20;
sf::Vector2f Lava::lavaSize(TILE_SIZE, TILE_SIZE);

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

bool Lava::collide(Collidable& c) {
    if(c.getBoundingBox().intersects(getBoundingBox())) {
        c.takeDamage(hitDmg);
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------------

sf::FloatRect Lava::getBoundingBox() const {
    return sf::FloatRect(position.x, position.y, size.x, size.y);
}

// ---------------------------------------------------------------------------

void Lava::draw(sf::RenderWindow& window) {
    shape->setPosition(position.x - GameMap::getInstance()->getStart()*TILE_SIZE, position.y);
    window.draw(*shape);
    //if(position.x < playerPos.x + windowW/2 && position.y > playerPos.x - windowW/2) {
}
