
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "entity.hpp"

// Methods
// ---------------------------------------------------------------------------

Entity::Entity (int x, int y, int sizeX, int sizeY, int _classification) : Ent(x, y),
 size(sizeX, sizeY), classification{_classification} {

}

// ---------------------------------------------------------------------------

Entity::~Entity() {

}

// ---------------------------------------------------------------------------

int Entity::getSizeX() const{
    return size.x;
}

// ---------------------------------------------------------------------------

int Entity::getSizeY() const{
    return size.y;
}

// ---------------------------------------------------------------------------

int Entity::getClassification() const{
    return classification;
}

// ---------------------------------------------------------------------------

sf::FloatRect Entity::getBoundingBox() const{
    return sf::FloatRect(position.x, position.y, size.x, size.y);
}

// ---------------------------------------------------------------------------

void Entity::updatePositionX(float deltaTime) {
    // noop
}

// ---------------------------------------------------------------------------

void Entity::updatePositionY(float deltaTime) {
    //noop
}

// ---------------------------------------------------------------------------

void Entity::render(sf::RenderWindow& window) {
    // noop
}

// ---------------------------------------------------------------------------

json Entity::store() {
    json j;

    j["classification"] = classification;
    j["posX"] = position.x;
    j["posY"] = position.y;

    return j;
}
