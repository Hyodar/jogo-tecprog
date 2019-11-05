
#ifndef LEVEL_MANAGER_HPP_
#define LEVEL_MANAGER_HPP_

#include "entity_manager.hpp"
#include "level.hpp"

class LevelManager {

public:
    ~LevelManager();
    static LevelManager* getInstance();

private:
    LevelManager();
    static LevelManager* instance;

    Level* levels[3];
    int currentLevel;

    EntityManager entityManager;
    void nextLevel();
    void changeLevel(int levelNum);
    void cleanLevel();

};

#endif // LEVEL_MANAGER_HPP_
