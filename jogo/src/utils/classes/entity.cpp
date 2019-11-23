
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "entity.hpp"

// Internal libraries
// ---------------------

using namespace bardadv::core;
using namespace bardadv::collision;
using namespace bardadv::persistence;

// Attribute initialization
// ---------------------------------------------------------------------------

int Entity::entityCount = 0;

// Methods
// ---------------------------------------------------------------------------

Entity::Entity (int x, int y, int sizeX, int sizeY, int _classification) : Ent(x, y),
 size(sizeX, sizeY), classification{_classification} {
    id = entityCount;
    ++entityCount;
}

// ---------------------------------------------------------------------------

Entity::~Entity() {

}

// ---------------------------------------------------------------------------

int Entity::getSizeX() const {
    return size.x;
}

// ---------------------------------------------------------------------------

int Entity::getSizeY() const {
    return size.y;
}

// ---------------------------------------------------------------------------

int Entity::getId() const {
    return id;
}

// ---------------------------------------------------------------------------

void Entity::setId(int _id) {
    id = _id;
}

// ---------------------------------------------------------------------------

int Entity::getClassification() const {
    return classification;
}

// ---------------------------------------------------------------------------

sf::FloatRect Entity::getBoundingBox() const {
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
