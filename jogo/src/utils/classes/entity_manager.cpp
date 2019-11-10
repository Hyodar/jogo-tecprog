
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
    for(Obstacle* e : obstacles) {
        delete e;
    }

    obstacles.clear();

    for(Enemy* e : enemies) {
        delete e;
    }

    enemies.clear();
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
    //for(uint i = 0; i < obstacles.size(); i++) obstacles[i]->render(window);
    for(uint i = 0; i < enemies.size(); i++) enemies[i]->render(window);
}

void EntityManager::moveBardo(const float deltaTime) {
    bardo->updatePositionX(deltaTime);

    CollisionResolver::collideX(bardo, GameMap::getInstance());
    for(uint i = 0; i < obstacles.size(); i++) CollisionResolver::collideX(bardo, obstacles[i]);
    for(uint i = 0; i < enemies.size(); i++) CollisionResolver::collideX(bardo, enemies[i]);

    bardo->updatePositionY(deltaTime);

    CollisionResolver::collideY(bardo, GameMap::getInstance());
    for(uint i = 0; i < obstacles.size(); i++) CollisionResolver::collideY(bardo, obstacles[i]);
    for(uint i = 0; i < enemies.size(); i++) CollisionResolver::collideY(bardo, enemies[i]);
}

void EntityManager::moveEscudeiro(const float deltaTime) {
    fielEscudeiro->updatePositionX(deltaTime);

    CollisionResolver::collideX(fielEscudeiro, GameMap::getInstance());
    for(uint i = 0; i < obstacles.size(); i++) CollisionResolver::collideX(fielEscudeiro, obstacles[i]);
    for(uint i = 0; i < enemies.size(); i++) CollisionResolver::collideX(fielEscudeiro, enemies[i]);

    fielEscudeiro->updatePositionY(deltaTime);

    CollisionResolver::collideY(fielEscudeiro, GameMap::getInstance());
    for(uint i = 0; i < obstacles.size(); i++) CollisionResolver::collideY(fielEscudeiro, obstacles[i]);
    for(uint i = 0; i < enemies.size(); i++) CollisionResolver::collideY(fielEscudeiro, enemies[i]);
}

// Tentei adicionar colisão inimigo-inimigo, mas n ficou mt legal

void EntityManager::moveEnemies(const float deltaTime) {
    for(uint i = 0; i < enemies.size(); i++) {
        enemies[i]->updatePositionX(deltaTime);
        CollisionResolver::collideX(enemies[i], GameMap::getInstance());
        for(uint j = 0; j < obstacles.size(); j++) CollisionResolver::collideX(enemies[i], obstacles[j]);
        // for(uint j = i + 1; j < enemies.size(); j++) CollisionResolver::collideX(enemies[i], enemies[j]);
        
        enemies[i]->updatePositionY(deltaTime);
        CollisionResolver::collideY(enemies[i], GameMap::getInstance());
        for(uint j = 0; j < obstacles.size(); j++) CollisionResolver::collideY(enemies[i], obstacles[j]);
        // for(uint j = i + 1; j < enemies.size(); j++) CollisionResolver::collideY(enemies[i], enemies[j]);
    }
}

void EntityManager::moveObstacles(const float deltaTime) {
    for(uint i = 0; i < obstacles.size(); i++) {
        obstacles[i]->updatePosition(deltaTime);
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