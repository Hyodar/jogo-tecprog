
#ifndef LEVEL_MANAGER_HPP_
#define LEVEL_MANAGER_HPP_

#include "entity_manager.hpp"
#include "entity.hpp"
#include "level.hpp"

class LevelManager {

public:
    ~LevelManager();
    static LevelManager* getInstance();

    void addObstacle(Entity* e) { entityManager.addObstacle(e); }

    void nextLevel();
    void changeLevel(int levelNum);
    void cleanLevel();
    Level* getLevel() { return levels[currentLevel]; };

    void init() { levels[currentLevel]->init(); }
    void process(float deltaTime) { entityManager.process(deltaTime); }

    EntityManager& getEntityManager() { return entityManager; }

private:
    LevelManager();
    static LevelManager* instance;

    Level* levels[3];
    int currentLevel;

    EntityManager entityManager;

};

#endif // LEVEL_MANAGER_HPP_
