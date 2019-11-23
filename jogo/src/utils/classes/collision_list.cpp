// Libraries
// ---------------------------------------------------------------------------

#include <vector>
#include <iostream>

// Class header
// ---------------------

#include "collision_list.hpp"

// Internal libraries
// ---------------------

#include "enemy.hpp"
#include "obstacle.hpp"
#include "projectile.hpp"
#include "bardo.hpp"
#include "fiel_escudeiro.hpp"
#include "game_map.hpp"
#include "tile.hpp"

#include "level_manager.hpp"
#include "score_manager.hpp"

using namespace bardadv::core;
using namespace bardadv::characters;
using namespace bardadv::obstacles;
using namespace bardadv::map;
using namespace bardadv::projectiles;
using namespace bardadv::collision;
using namespace bardadv::lists;

// Attribute initialization
// ---------------------------------------------------------------------------

// Methods
// ---------------------------------------------------------------------------

CollisionList::CollisionList() : bardo{nullptr}, fielEscudeiro{nullptr} {
    // noop
}

// ---------------------------------------------------------------------------

CollisionList::~CollisionList() {
    deallocate();
}

// ---------------------------------------------------------------------------

void CollisionList::add(Enemy* e) {
    enemies.push_back(e);
}

// ---------------------------------------------------------------------------

void CollisionList::add(Obstacle* e) {
    obstacles.insert({ obstacles.size(), e });
}

// ---------------------------------------------------------------------------

void CollisionList::add(Projectile* e) {
    projectiles.push_back(e);
}

// ---------------------------------------------------------------------------

void CollisionList::add(Bardo* e) {
    bardo = e;
}

// ---------------------------------------------------------------------------

void CollisionList::add(FielEscudeiro* e) {
    fielEscudeiro = e;
}

// ---------------------------------------------------------------------------

void CollisionList::remove(Enemy* e) {
    for(auto it = enemies.begin(); it != enemies.end(); it++) {
        if((*it) == e) {
            enemies.erase(it);
            return;
        }
    }
}

// ---------------------------------------------------------------------------

void CollisionList::remove(Obstacle* e) {
    for(auto it = obstacles.begin(); it != obstacles.end(); it++) {
        if(it->second == e) {
            obstacles.erase(it);
            return;
        }
    }
}

// ---------------------------------------------------------------------------

void CollisionList::remove(Projectile* e) {
    for(auto it = projectiles.begin(); it != projectiles.end(); it++) {
        if((*it) == e) {
            projectiles.erase(it);
            return;
        }
    }
}

// ---------------------------------------------------------------------------

void CollisionList::deallocate() {
    for(Enemy* e : enemies) {
        delete e;
    }
    enemies.clear();

    for(auto& [key, o] : obstacles) {
        (void) key;

        delete o;
    }
    obstacles.clear();

    for(Projectile* p : projectiles) {
        delete p;
    }
    projectiles.clear();
}

// ---------------------------------------------------------------------------

void CollisionList::testCollisionX() {
    testBardoX();
    if(fielEscudeiro) testFielEscudeiroX();
    testEnemiesX();
    testProjectiles();
}

// ---------------------------------------------------------------------------

void CollisionList::testCollisionY() {
    testBardoY();
    if(fielEscudeiro) testFielEscudeiroY();
    testEnemiesY();

    testProjectiles();
    testHitPoints();
}

// ---------------------------------------------------------------------------

void CollisionList::testBardoX() {
    GameMap* g = GameMap::getInstance();

    for(int i = bardo->getPosY()/TILE_SIZE; i < (bardo->getPosY() + bardo->getSizeY())/TILE_SIZE; i++) {
        for(int j = bardo->getPosX()/TILE_SIZE; j < (bardo->getPosX() + bardo->getSizeX())/TILE_SIZE; j++) {
            if(!g->isPositionValid(i, j)) continue;
            Tile* t = g->getTile(i, j);
            if(t->getBoundingBox().intersects(bardo->getBoundingBox())) {
                static_cast<Character*>(bardo)->collideX(t);
            }
        }
    }

    for(Enemy* e : enemies) {
        if(e->getBoundingBox().intersects(bardo->getAttackBoundingBox())) {
            bardo->collideX(e);
            e->collideX(bardo);
        }
    }

    for(auto& [key, o] : obstacles) {
        (void) key;

        if(collisionDetecter.isColliding(bardo, o)) {
            static_cast<Character*>(bardo)->collideX(o);
            o->collideX(bardo);
        }
    }

    for(Projectile* e : projectiles) {
        if(collisionDetecter.isColliding(bardo, e)) {
            //bardo->collideX(e);
            e->collideX(bardo);
        }
    }
}

// ---------------------------------------------------------------------------

void CollisionList::testBardoY() {
    GameMap* g = GameMap::getInstance();

    for(int i = bardo->getPosY()/TILE_SIZE; i < (bardo->getPosY() + bardo->getSizeY())/TILE_SIZE; i++) {
        for(int j = bardo->getPosX()/TILE_SIZE; j < (bardo->getPosX() + bardo->getSizeX())/TILE_SIZE; j++) {
            if(!g->isPositionValid(i, j)) continue;
            Tile* t = g->getTile(i, j);
            if(t->getBoundingBox().intersects(bardo->getBoundingBox())) {
                static_cast<Character*>(bardo)->collideY(t);
            }
        }
    }

    for(Enemy* e : enemies) {
        if(collisionDetecter.isColliding(bardo, e)) {
            //bardo->collideY(e);
            e->collideY(bardo);
        }
    }
    for(auto& [key, o] : obstacles) {
        (void) key;

        if(collisionDetecter.isColliding(bardo, o)) {
            static_cast<Character*>(bardo)->collideY(o);
            o->collideY(bardo);
        }
    }
    for(Projectile* e : projectiles) {
        if(collisionDetecter.isColliding(bardo, e)) {
            //bardo->collideY(e);
            e->collideY(bardo);
        }
    }
}

// ---------------------------------------------------------------------------

void CollisionList::testFielEscudeiroX() {
    GameMap* g = GameMap::getInstance();

    for(int i = fielEscudeiro->getPosY()/TILE_SIZE; i < (fielEscudeiro->getPosY() + fielEscudeiro->getSizeY())/TILE_SIZE; i++) {
        for(int j = fielEscudeiro->getPosX()/TILE_SIZE; j < (fielEscudeiro->getPosX() + fielEscudeiro->getSizeX())/TILE_SIZE; j++) {
            if(!g->isPositionValid(i, j)) continue;
            Tile* t = g->getTile(i, j);
            if(t->getBoundingBox().intersects(fielEscudeiro->getBoundingBox())) {
                static_cast<Character*>(fielEscudeiro)->collideX(t);
            }
        }
    }

    for(Enemy* e : enemies) {
        if(collisionDetecter.isColliding(fielEscudeiro, e)) {
            //fielEscudeiro->collideX(e);
            e->collideX(fielEscudeiro);
        }
    }
    for(auto& [key, o] : obstacles) {
        (void) key;

        if(collisionDetecter.isColliding(fielEscudeiro, o)) {
            static_cast<Character*>(fielEscudeiro)->collideX(o);
            o->collideX(fielEscudeiro);
        }
    }
    for(Projectile* e : projectiles) {
        if(collisionDetecter.isColliding(fielEscudeiro, e)) {
            //fielEscudeiro->collideX(e);
            e->collideX(fielEscudeiro);
        }
    }
}

// ---------------------------------------------------------------------------

void CollisionList::testFielEscudeiroY() {
    GameMap* g = GameMap::getInstance();

    for(int i = fielEscudeiro->getPosY()/TILE_SIZE; i < (fielEscudeiro->getPosY() + fielEscudeiro->getSizeY())/TILE_SIZE; i++) {
        for(int j = fielEscudeiro->getPosX()/TILE_SIZE; j < (fielEscudeiro->getPosX() + fielEscudeiro->getSizeX())/TILE_SIZE; j++) {
            if(!g->isPositionValid(i, j)) continue;
            Tile* t = g->getTile(i, j);
            if(t->getBoundingBox().intersects(fielEscudeiro->getBoundingBox())) {
                static_cast<Character*>(fielEscudeiro)->collideY(t);
            }
        }
    }

    for(Enemy* e : enemies) {
        if(collisionDetecter.isColliding(fielEscudeiro, e)) {
            //fielEscudeiro->collideY(e);
            e->collideY(fielEscudeiro);
        }
    }
    for(auto& [key, o] : obstacles) {
        (void) key;

        if(collisionDetecter.isColliding(fielEscudeiro, o)) {
            static_cast<Character*>(fielEscudeiro)->collideY(o);
            o->collideY(fielEscudeiro);
        }
    }
    for(Projectile* e : projectiles) {
        if(collisionDetecter.isColliding(fielEscudeiro, e)) {
            //fielEscudeiro->collideY(e);
            e->collideY(fielEscudeiro);
        }
    }
}

// ---------------------------------------------------------------------------

void CollisionList::testEnemiesX() {
    GameMap* g = GameMap::getInstance();

    for(Enemy* e : enemies) {
        for(int i = e->getPosY()/TILE_SIZE; i < (e->getPosY() + e->getSizeY())/TILE_SIZE; i++) {
            for(int j = e->getPosX()/TILE_SIZE; j < (e->getPosX() + e->getSizeX())/TILE_SIZE; j++) {
                if(!g->isPositionValid(i, j)) continue;
                Tile* t = g->getTile(i, j);
                if(t->getBoundingBox().intersects(e->getBoundingBox())) {
                    static_cast<Character*>(e)->collideX(t);
                }
            }
        }

        for(auto& [key, o] : obstacles) {
            (void) key;

            if(collisionDetecter.isColliding(e, o)) {
                static_cast<Character*>(e)->collideX(o);
                o->collideX(e);
            }
        }
        // inimigos n colidem com projeteis
    }
}

// ---------------------------------------------------------------------------

void CollisionList::testEnemiesY() {
    GameMap* g = GameMap::getInstance();

    for(Enemy* e : enemies) {
        for(int i = e->getPosY()/TILE_SIZE; i < (e->getPosY() + e->getSizeY())/TILE_SIZE; i++) {
            for(int j = e->getPosX()/TILE_SIZE; j < (e->getPosX() + e->getSizeX())/TILE_SIZE; j++) {
                if(!g->isPositionValid(i, j)) continue;

                Tile* t = g->getTile(i, j);
                if(t->getBoundingBox().intersects(e->getBoundingBox())) {
                    static_cast<Character*>(e)->collideY(t);
                }
            }
        }

        for(auto& [key, o] : obstacles) {
            (void) key;

            if(collisionDetecter.isColliding(e, o)) {
                static_cast<Character*>(e)->collideY(o);
                o->collideY(e);
            }
        }
    }
}

// ---------------------------------------------------------------------------

void CollisionList::testProjectiles() {
    std::vector<Projectile*> toErase;

    for(auto it = projectiles.begin(); it != projectiles.end(); it++) {
        const int maxX = GameMap::getInstance()->getSizeX() * TILE_SIZE;
        const int maxY = GameMap::getInstance()->getSizeY() * TILE_SIZE;

        if((*it)->getPosX() > maxX || (*it)->getPosX() < 0 || (*it)->getPosY() > maxY || (*it)->getPosY() < 0 || (*it)->getTraveledDist() > 2000) {
            toErase.push_back(*it);
        }
    }

    for(Projectile* p : toErase) {
        LevelManager::getInstance()->removeProjectile(p);
    }
}

// ---------------------------------------------------------------------------

void CollisionList::testHitPoints() {
    std::vector<Enemy*> toErase;

    for(Enemy* e : enemies) {
        if(!e->isAlive()) {
            ScoreManager::getInstance()->increasePoints(e->getPoints());
            toErase.push_back(e);
        }
    }

    for(Enemy* e : toErase) {
        LevelManager::getInstance()->removeEnemy(e);
    }
}
