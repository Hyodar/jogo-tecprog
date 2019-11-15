
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "entity.hpp"

// Methods
// ---------------------------------------------------------------------------

Entity::Entity (int x, int y, int sizeX, int sizeY, int _classification) : Ent(x, y), size(sizeX, sizeY), classification{_classification} {}

// ---------------------------------------------------------------------------

Entity::~Entity() {}

// ---------------------------------------------------------------------------

json Entity::store() {
    json j;

    j["classification"] = classification;
    j["posX"] = position.x;
    j["posY"] = position.y;

    return j;
}
