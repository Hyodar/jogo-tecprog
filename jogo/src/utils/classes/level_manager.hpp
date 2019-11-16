
#ifndef LEVEL_MANAGER_HPP_
#define LEVEL_MANAGER_HPP_

#include <vector>

#include "entity_manager.hpp"
#include "level.hpp"
#include "game.hpp"
#include <constants.hpp>

class Obstacle;
class Enemy;
class Projectile;

class LevelManager {

public:
    ~LevelManager();
    static LevelManager* getInstance();

    void addObstacle(Obstacle* e) { entityManager.addObstacle(e); }
    void addEnemy(Enemy* e) { entityManager.addEnemy(e); }
    void removeEnemy(Enemy* e);
    void addProjectile(Projectile* e) { entityManager.addProjectile(e); }
    void removeProjectile(Projectile* e) { entityManager.removeProjectile(e); }
    
    void removeFielEscudeiro(FielEscudeiro* f) { entityManager.removeFielEscudeiro(f); }

    void nextLevel();
    void changeLevel(int levelNum);
    void recoverLevel(int levelNum);
    void cleanLevel();
    
    Level* getLevel() { return levels[currentLevel]; }
    int getCurrentLevel() { return currentLevel; }

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
