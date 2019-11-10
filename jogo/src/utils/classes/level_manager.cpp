
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

    if(levelNum < 0 || levelNum > 2) return;

    cleanLevel();
    currentLevel = levelNum;
    levels[currentLevel]->init();
    GameMap::getInstance()->loadMap();
}

// ---------------------------------------------------------------------------

void LevelManager::cleanLevel() {
    entityManager.clean();
}
