
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "entity_manager.hpp"

// Internal libraries
// ---------------------

#include "entity.hpp"
#include "obstacle.hpp"
#include "bardo.hpp"
#include "fiel_escudeiro.hpp"
#include "enemy.hpp"
#include "projectile.hpp"

#include "game.hpp"

using namespace bardadv::core;
using namespace bardadv::obstacles;
using namespace bardadv::characters;
using namespace bardadv::projectiles;

// Methods
// ---------------------------------------------------------------------------

EntityManager::EntityManager() {

}

// ---------------------------------------------------------------------------

EntityManager::~EntityManager() {
    clean();
}

// ---------------------------------------------------------------------------

void EntityManager::clean() {
    entityList.clean();
    collisionList.deallocate();
}

// ---------------------------------------------------------------------------

void EntityManager::process(float deltaTime) {
    entityList.moveX(deltaTime);
    collisionList.testCollisionX();
    entityList.moveY(deltaTime);
    collisionList.testCollisionY();

    render(Game::getInstance()->getMainWindow());
}

// ---------------------------------------------------------------------------

void EntityManager::render(sf::RenderWindow& window) {
    entityList.render(window);
}

// ---------------------------------------------------------------------------

void EntityManager::addObstacle(Obstacle* e) {
    entityList.add(static_cast<Entity*>(e));
    collisionList.add(e);
}

// ---------------------------------------------------------------------------

void EntityManager::addEnemy(Enemy* e) {
    entityList.add(static_cast<Entity*>(e));
    collisionList.add(e);
}

// ---------------------------------------------------------------------------

void EntityManager::removeEnemy(Enemy* e) {
    entityList.remove(static_cast<Entity*>(e));
    collisionList.remove(e);
    delete e;
}

// ---------------------------------------------------------------------------

void EntityManager::addProjectile(Projectile* e) {
    entityList.add(static_cast<Entity*>(e));
    collisionList.add(e);
}

// ---------------------------------------------------------------------------

void EntityManager::removeProjectile(Projectile* e) {
    entityList.remove(static_cast<Entity*>(e));
    collisionList.remove(e);
    delete e;
}

// ---------------------------------------------------------------------------

void EntityManager::removeFielEscudeiro(FielEscudeiro* f) {
    entityList.setHasEscudeiro(false);
    entityList.remove(static_cast<Entity*>(f));
    collisionList.add(static_cast<FielEscudeiro*>(nullptr));
}


// ---------------------------------------------------------------------------

void EntityManager::setBardo(Bardo* b) {
    entityList.add(static_cast<Entity*>(b));
    collisionList.add(b);
}

// ---------------------------------------------------------------------------

void EntityManager::setFielEscudeiro(FielEscudeiro* f) {
    entityList.setHasEscudeiro(true);
    entityList.add(static_cast<Entity*>(f));
    collisionList.add(f);
}

// ---------------------------------------------------------------------------

Entity* EntityManager::getEntityById(int id) {
    return entityList.getEntityById(id);
}

// ---------------------------------------------------------------------------

json EntityManager::store() {
    return entityList.store();
}
