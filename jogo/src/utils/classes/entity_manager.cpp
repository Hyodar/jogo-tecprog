
#include "entity_manager.hpp"

#include "collision_manager.hpp"
#include "character.hpp"
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

void EntityManager::process(float deltaTime) {

    // FIXME
    // TROCAR PRA OBSTACLES E ENEMIES SEPARADO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    for(uint i = 0; i < entities.size(); i++) {
        entities[i]->updatePosition(deltaTime);
        // aqui talvez seria certo testar 1 a 1 todas as combinações,
        // pra pegar a colisao se cada um se movimentar, mas n sei
        // se vale a pena pq isso vai ser executado bem rápido
        for(uint j = i + 1; j < entities.size(); j++) {
            CollisionManager::processCollision(entities[i], entities[j]);
        }
    }

    Game::getInstance()->getPlayer().updatePosition(deltaTime);

}

#include <iostream>

void EntityManager::checkCharacterYCollision(Character* c) {
    for(uint i = 0; i < entities.size(); i++) {
        const Entity& e = *(entities[i]);
        if(!e.getBoundingBox().intersects(c->getBoundingBox())) continue;

        if(c->getSpeedY() > 0) {
            c->setPosY(e.getBoundingBox().top - c->getSizeY());
            c->setOnGround(true);
        }
        else if(c->getSpeedY() < 0) c->setPosY(e.getBoundingBox().top + e.getBoundingBox().height);
        c->setSpeedY(0);
    }
}

void EntityManager::checkCharacterXCollision(Character* c) {
    for(uint i = 0; i < entities.size(); i++) {
        const Entity& e = *(entities[i]);
        if(!e.getBoundingBox().intersects(c->getBoundingBox())) continue;

        if(c->getSpeedX() > 0) {
            c->setPosX(e.getBoundingBox().left - c->getSizeX());
        }
        else if(c->getSpeedX() < 0) c->setPosX(e.getBoundingBox().left + e.getBoundingBox().width);
        c->setSpeedX(0);
    }
}

void EntityManager::checkAttack(sf::FloatRect hitBox, float dmg) {
    // noop
}

void EntityManager::addEntity(Entity* e) {
    entities.push_back(e);
}