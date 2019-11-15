
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
#include "game_map.hpp"

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
    /*
    bardo->render(window);
    if(hasEscudeiro) fielEscudeiro->render(window);
    //for(auto it = obstacles.begin(); it != obstacles.end(); it++) (*it)->render(window);
    for(auto it = enemies.begin(); it != enemies.end(); it++) (*it)->render(window);
    for(auto it = projectiles.begin(); it != projectiles.end(); it++) (*it)->render(window);
    */
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

json EntityManager::store() {
    return entityList.store();
}