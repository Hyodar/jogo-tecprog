// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "entity_list.hpp"

// Internal libraries
// ---------------------

#include "entity.hpp"
#include "game.hpp"

using namespace bardadv::core;
using namespace bardadv::lists;

// Attribute initialization
// ---------------------------------------------------------------------------

// Methods
// ---------------------------------------------------------------------------
EntityList::EntityList() : hasEscudeiro{false} {

}

// ---------------------------------------------------------------------------

EntityList::~EntityList() {
    //noop
}

// ---------------------------------------------------------------------------

void EntityList::setHasEscudeiro(bool b) {
    hasEscudeiro = b;
}

// ---------------------------------------------------------------------------

void EntityList::add(Entity* e) {
    list.push_back(e);
}

// ---------------------------------------------------------------------------

void EntityList::remove(Entity* e) {
    for(auto it = list.begin(); it != list.end(); it++) {
        if((*it) == e) {
            list.erase(it);
            return;
        }
    }
}

// ---------------------------------------------------------------------------

void EntityList::moveX(const float deltaTime) {
    for(auto it = list.begin(); it != list.end(); it++) {
        (*it)->updatePositionX(deltaTime);
    }
}

// ---------------------------------------------------------------------------

void EntityList::moveY(const float deltaTime) {
    for(auto it = list.begin(); it != list.end(); it++) {
        (*it)->updatePositionY(deltaTime);
    }
}

// ---------------------------------------------------------------------------

void EntityList::render(sf::RenderWindow& window) {
    for(auto it = list.begin(); it != list.end(); it++) {
        (*it)->render(window);
    }
}

// ---------------------------------------------------------------------------

void EntityList::clean() {
    list.deallocate();
    list.push_back(&(Game::getInstance()->getPlayer()));
    if(hasEscudeiro) list.push_back(&(Game::getInstance()->getFielEscudeiro()));
}

// ---------------------------------------------------------------------------


Entity* EntityList::getEntityById(int id) {
    for(auto it = list.begin(); it != list.end(); it++) {
        if((*it)->getId() == id) return (*it);
    }
    return nullptr;
}

// ---------------------------------------------------------------------------

json EntityList::store() {
    json j;

    for(auto it = list.begin(); it != list.end(); it++) {
        j.push_back((*it)->store());
    }

    return j;
}
