
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "entity.hpp"

// Methods
// ---------------------------------------------------------------------------
Entity::Entity (int x, int y, int sizeX, int sizeY) : size(sizeX, sizeY), position(x, y) { }

Entity::~Entity() { }
