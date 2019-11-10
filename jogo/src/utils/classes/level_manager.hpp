
#ifndef LEVEL_MANAGER_HPP_
#define LEVEL_MANAGER_HPP_

#include <vector>

#include "entity_manager.hpp"
#include "obstacle.hpp"
#include "level.hpp"
#include "enemy.hpp"

class LevelManager {

public:
    ~LevelManager();
    static LevelManager* getInstance();

    void addObstacle(Obstacle* e) { entityManager.addObstacle(e); }
    void addEnemy(Enemy* e) { entityManager.addEnemy(e); }

    void nextLevel();
    void changeLevel(int levelNum);
    void cleanLevel();
    
    Level* getLevel() { return levels[currentLevel]; }
    int getCurrentLevel() { return currentLevel; }

    //std::vector<Obstacle*> getObstacles() { return entityManager.getObstacles(); }
    //std::vector<Enemy*> getEnemies() { return entityManager.getEnemies(); }

    void init() { levels[currentLevel]->init(); }
    void process(float deltaTime) { entityManager.process(deltaTime); }

    EntityManager& getEntityManager() { return entityManager; }

private:
    LevelManager();
    static LevelManager* instance;

    Level* levels[2];
    int currentLevel;

    EntityManager entityManager;

};

#endif // LEVEL_MANAGER_HPP_
