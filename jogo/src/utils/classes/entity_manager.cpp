
#include "entity_manager.hpp"

#include "collision_manager.hpp"
#include "character.hpp"
#include "game.hpp"

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"

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

    bardo->updatePosition(deltaTime);
    if(hasEscudeiro) {
        fielEscudeiro->updatePosition(deltaTime);
    }
    
    for(Obstacle* e : obstacles) {
        e->updatePosition(deltaTime);
    }

    for(Character* e : characters) {
        e->updatePosition(deltaTime);
    }

}

bool EntityManager::checkCharacterYCollision(Character* c) {
    for(uint i = 0; i < obstacles.size(); i++) {
        Obstacle& e = *(obstacles[i]);
        if(!e.getBoundingBox().intersects(c->getBoundingBox())) continue;

        e.collide(*c);

        if(c->getSpeedY() > 0) {
            c->setPosY(e.getBoundingBox().top - c->getSizeY());
            c->setOnGround(true);
        }
        else if(c->getSpeedY() < 0) c->setPosY(e.getBoundingBox().top + e.getBoundingBox().height);
        c->setSpeedY(0);
        
        return true;
    }
    return false;
}

bool EntityManager::checkCharacterXCollision(Character* c) {
    for(uint i = 0; i < obstacles.size(); i++) {
        Obstacle& e = *(obstacles[i]);
        if(!e.getBoundingBox().intersects(c->getBoundingBox())) continue;

        e.collide(*c);

        if(c->getSpeedX() > 0) {
            c->setPosX(e.getBoundingBox().left - c->getSizeX());
        }
        else if(c->getSpeedX() < 0) c->setPosX(e.getBoundingBox().left + e.getBoundingBox().width);
        c->setSpeedX(0);

        return true;
    }
    return false;
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