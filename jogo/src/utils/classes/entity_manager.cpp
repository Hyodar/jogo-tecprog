
#include "entity_manager.hpp"

#include "game.hpp"
#include "game_map.hpp"
#include "collision_resolver.hpp"

EntityManager::EntityManager() : bardo{nullptr}, fielEscudeiro{nullptr}, hasEscudeiro{false} {
    // noop
}

EntityManager::~EntityManager() {
    clean();
}

void EntityManager::clean() {
    obstacles.deallocate();
    enemies.deallocate();
}

void EntityManager::process(float deltaTime) {

    moveBardo(deltaTime);
    if(hasEscudeiro) moveEscudeiro(deltaTime);
    moveObstacles(deltaTime);
    moveEnemies(deltaTime);

    render(Game::getInstance()->getMainWindow());
}

void EntityManager::render(sf::RenderWindow& window) {
    bardo->render(window);
    if(hasEscudeiro) fielEscudeiro->render(window);
    //for(auto it = obstacles.begin(); it != obstacles.end(); it++) (*it)->render(window);
    for(auto it = enemies.begin(); it != enemies.end(); it++) (*it)->render(window);
}

void EntityManager::moveBardo(const float deltaTime) {
    bardo->updatePositionX(deltaTime);

    CollisionResolver::collideX(bardo, GameMap::getInstance());
    for(auto it = obstacles.begin(); it != obstacles.end(); it++) CollisionResolver::collideX(bardo, *it);
    for(auto it = enemies.begin(); it != enemies.end(); it++) CollisionResolver::collideX(bardo, *it);

    bardo->updatePositionY(deltaTime);

    CollisionResolver::collideY(bardo, GameMap::getInstance());
    for(auto it = obstacles.begin(); it != obstacles.end(); it++) CollisionResolver::collideY(bardo, *it);
    for(auto it = enemies.begin(); it != enemies.end(); it++) CollisionResolver::collideY(bardo, *it);
}

void EntityManager::moveEscudeiro(const float deltaTime) {
    fielEscudeiro->updatePositionX(deltaTime);

    CollisionResolver::collideX(fielEscudeiro, GameMap::getInstance());
    for(auto it = obstacles.begin(); it != obstacles.end(); it++) CollisionResolver::collideX(fielEscudeiro, *it);
    for(auto it = enemies.begin(); it != enemies.end(); it++) CollisionResolver::collideX(fielEscudeiro, *it);

    fielEscudeiro->updatePositionY(deltaTime);

    CollisionResolver::collideY(fielEscudeiro, GameMap::getInstance());
    for(auto it = obstacles.begin(); it != obstacles.end(); it++) CollisionResolver::collideY(fielEscudeiro, *it);
    for(auto it = enemies.begin(); it != enemies.end(); it++) CollisionResolver::collideY(fielEscudeiro, *it);
}

// Tentei adicionar colisão inimigo-inimigo, mas n ficou mt legal

void EntityManager::moveEnemies(const float deltaTime) {
    for(auto it = enemies.begin(); it != enemies.end(); it++) {
        (*it)->updatePositionX(deltaTime);
        CollisionResolver::collideX(*it, GameMap::getInstance());
        for(auto it2 = obstacles.begin(); it2 != obstacles.end(); it2++) CollisionResolver::collideX(*it, *it2);
        // for(uint j = i + 1; j < enemies.size(); j++) CollisionResolver::collideX(*it, enemies[j]);
        
        (*it)->updatePositionY(deltaTime);
        CollisionResolver::collideY(*it, GameMap::getInstance());
        for(auto it2 = obstacles.begin(); it2 != obstacles.end(); it2++) CollisionResolver::collideY(*it, *it2);
        // for(uint j = i + 1; j < enemies.size(); j++) CollisionResolver::collideY(*it, enemies[j]);
    }
}

void EntityManager::moveObstacles(const float deltaTime) {
    for(auto it = obstacles.begin(); it != obstacles.end(); it++) {
        (*it)->updatePosition(deltaTime);
    }
}

void EntityManager::checkAttack(sf::FloatRect hitBox, float dmg) {
    // TODO
}

void EntityManager::addObstacle(Obstacle* e) {
    obstacles.push_back(e);
}

void EntityManager::addEnemy(Enemy* c) {
    enemies.push_back(c);
}