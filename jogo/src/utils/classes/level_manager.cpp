
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "level_manager.hpp"

// Standard libraries
// ---------------------

#include <iostream>

// Internal libraries
// ---------------------

#include "taberna.hpp"
#include "salao.hpp"
#include "game_map.hpp"
#include "enemy.hpp"

using namespace bardadv::core;
using namespace bardadv::levels;
using namespace bardadv::map;
using namespace bardadv::characters;

// Attribute initialization
// ---------------------------------------------------------------------------

LevelManager* LevelManager::instance = nullptr;

// Methods
// ---------------------------------------------------------------------------

LevelManager::LevelManager() : currentLevel{-1} {
    levels[0] = static_cast<Level*>(new Taberna);
    levels[1] = static_cast<Level*>(new Salao);
}

// ---------------------------------------------------------------------------

LevelManager::~LevelManager() {
    // noop
}

// ---------------------------------------------------------------------------

LevelManager* LevelManager::getInstance() {
    if(!instance) instance = new LevelManager;
    return instance;
}

// ---------------------------------------------------------------------------

void LevelManager::nextLevel() {
    currentLevel++;
    changeLevel(currentLevel);
}

// ---------------------------------------------------------------------------

void LevelManager::changeLevel(int levelNum) {
    std::cout << "Changing to level " << levelNum << "..." << std::endl;

    if(levelNum < 0 || levelNum > 1) return;

    cleanLevel();
    currentLevel = levelNum;
    levels[currentLevel]->init();
    GameMap::getInstance()->loadMap();

    std::cout << "Loaded level." << std::endl;
}

// ---------------------------------------------------------------------------

void LevelManager::recoverLevel(int levelNum, json data) {
    std::cout << "Recovering level " << levelNum << "..." << std::endl;
    if(levelNum < 0 || levelNum > 1) return;

    currentLevel = levelNum;

    GameMap::getInstance()->loadMap();
    levels[currentLevel]->recoverLevel(data);

    std::cout << "Loaded level." << std::endl;
}

// ---------------------------------------------------------------------------

void LevelManager::cleanLevel() {
    entityManager.clean();
}

// ---------------------------------------------------------------------------

void LevelManager::removeEnemy(Enemy* e) {
    if(e->getPoints() == (int) Points::DRAGON_REWARD) {
        Game::getInstance()->winGame();
    }
    entityManager.removeEnemy(e);
}

// ---------------------------------------------------------------------------

void LevelManager::addObstacle(Obstacle* e) {
     entityManager.addObstacle(e);
 }

 // ---------------------------------------------------------------------------

void LevelManager::addEnemy(Enemy* e) {
     entityManager.addEnemy(e);
 }

 // ---------------------------------------------------------------------------

void LevelManager::addProjectile(Projectile* e) {
     entityManager.addProjectile(e);
 }

 // ---------------------------------------------------------------------------

void LevelManager::removeProjectile(Projectile* e) {
     entityManager.removeProjectile(e);
 }

 // ---------------------------------------------------------------------------

void LevelManager::removeFielEscudeiro(FielEscudeiro* f) {
     entityManager.removeFielEscudeiro(f);
 }

 // ---------------------------------------------------------------------------

Level* LevelManager::getLevel() const{
     return levels[currentLevel];
 }

 // ---------------------------------------------------------------------------

int LevelManager::getCurrentLevel() const{
     return currentLevel;
 }

 // ---------------------------------------------------------------------------

void LevelManager::init() {
     levels[currentLevel]->init();
 }

 // ---------------------------------------------------------------------------

void LevelManager::process(float deltaTime) {
     entityManager.process(deltaTime);
 }

 // ---------------------------------------------------------------------------

EntityManager& LevelManager::getEntityManager() {
     return entityManager;
 }
