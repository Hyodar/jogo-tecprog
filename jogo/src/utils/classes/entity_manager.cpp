
#include "entity_manager.hpp"

#include "collision_manager.hpp"
#include "game.hpp"

EntityManager::EntityManager() {
    // noop
}

EntityManager::~EntityManager() {
    clean();
}

void EntityManager::clean() {
    for(Entity* e : entities) {
        delete e;
    }

    entities.clear();
}

void EntityManager::process() {
    for(uint i = 0; i < entities.size(); i++) {
        entities[i]->updatePosition();
        // aqui talvez seria certo testar 1 a 1 todas as combinações,
        // pra pegar a colisao se cada um se movimentar, mas n sei
        // se vale a pena pq isso vai ser executado bem rápido
        for(uint j = i + 1; j < entities.size(); j++) {
            CollisionManager::processCollision(entities[i], entities[j]);
        }
    }

    for(uint i = 0; i < entities.size(); i++) {
            CollisionManager::processCollision(static_cast<Entity*>(&(Game::getInstance()->getPlayer())), entities[i]);
        }
}

void EntityManager::checkAttack(sf::FloatRect hitBox, float dmg) {
    // noop
}

void EntityManager::addEntity(Entity* e) {
    entities.push_back(e);
}