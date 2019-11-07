
#include "level_manager.hpp"

#include <iostream>

#include "taberna.hpp"
#include "salao.hpp"
#include "game_map.hpp"

LevelManager* LevelManager::instance = nullptr;

LevelManager::LevelManager() : currentLevel{-1} {
    levels[0] = static_cast<Level*>(new Taberna);
    levels[1] = static_cast<Level*>(new Salao);
}

LevelManager::~LevelManager() {
    // noop
}

LevelManager* LevelManager::getInstance() {
    if(!instance) instance = new LevelManager;
    return instance;
}

void LevelManager::nextLevel() {
    currentLevel++;
    changeLevel(currentLevel);
}

void LevelManager::changeLevel(int levelNum) {
    std::cout << "Changing to level " << levelNum << "..." << std::endl;

    if(levelNum < 0 || levelNum > 2) return;

    cleanLevel();
    currentLevel = levelNum;
    levels[currentLevel]->init();
    GameMap::getInstance()->loadMap();
}

void LevelManager::cleanLevel() {
    entityManager.clean();
}
