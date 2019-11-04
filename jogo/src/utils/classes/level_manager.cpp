
#include "level_manager.hpp"

#include "taberna.hpp"

LevelManager::instance = nullptr;

LevelManager::LevelManager() : currentLevel{-1} {
    levels[0] = static_cast<Level*>(new Taberna);
    /*
    levels[1] = new Level2;
    levels[2] = new Level3;
    */
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
    // TODO - recarregar mapa
    currentLevel = levelNum;
    levels[currentLevel]->init();
}
