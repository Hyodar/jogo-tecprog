
#include "entity_manager.hpp"

#include "character.hpp"
#include "game.hpp"
#include "game_map.hpp"
#include "bardo.hpp"
#include "fiel_escudeiro.hpp"
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

    for(Character* e : characters) {
        delete e;
    }

    characters.clear();
}

void EntityManager::process(float deltaTime) {

    moveBardo(deltaTime);
    if(hasEscudeiro) moveEscudeiro(deltaTime);
    moveObstacles(deltaTime);
    moveEnemies(deltaTime);
}

void EntityManager::moveBardo(const float deltaTime) {
    bardo->updatePositionX(deltaTime);

    CollisionResolver::collideX(bardo, GameMap::getInstance());
    for(uint i = 0; i < obstacles.size(); i++) CollisionResolver::collideX(bardo, obstacles[i]);
    for(uint i = 0; i < characters.size(); i++) CollisionResolver::collideX(bardo, characters[i]);

    bardo->updatePositionY(deltaTime);

    CollisionResolver::collideY(bardo, GameMap::getInstance());
    for(uint i = 0; i < obstacles.size(); i++) CollisionResolver::collideY(bardo, obstacles[i]);
    for(uint i = 0; i < characters.size(); i++) CollisionResolver::collideY(bardo, characters[i]);
}

void EntityManager::moveEscudeiro(const float deltaTime) {
    fielEscudeiro->updatePositionX(deltaTime);

    CollisionResolver::collideX(fielEscudeiro, GameMap::getInstance());
    for(uint i = 0; i < obstacles.size(); i++) CollisionResolver::collideX(fielEscudeiro, obstacles[i]);
    for(uint i = 0; i < characters.size(); i++) CollisionResolver::collideX(fielEscudeiro, characters[i]);

    fielEscudeiro->updatePositionY(deltaTime);

    CollisionResolver::collideY(fielEscudeiro, GameMap::getInstance());
    for(uint i = 0; i < obstacles.size(); i++) CollisionResolver::collideY(fielEscudeiro, obstacles[i]);
    for(uint i = 0; i < characters.size(); i++) CollisionResolver::collideY(fielEscudeiro, characters[i]);
}

void EntityManager::moveEnemies(const float deltaTime) {
    for(uint i = 0; i < characters.size(); i++) {
        characters[i]->updatePositionX(deltaTime);
        CollisionResolver::collideX(characters[i], GameMap::getInstance());
        characters[i]->updatePositionY(deltaTime);
        CollisionResolver::collideY(characters[i], GameMap::getInstance());
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

void EntityManager::addCharacter(Character* c) {
    characters.push_back(c);
}