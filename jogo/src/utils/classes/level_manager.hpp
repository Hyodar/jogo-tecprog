
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

    void addObstacle(Obstacle* e);
    void addEnemy(Enemy* e);
    void removeEnemy(Enemy* e);
    void addProjectile(Projectile* e);
    void removeProjectile(Projectile* e);

    void removeFielEscudeiro(FielEscudeiro* f);

    void nextLevel();
    void changeLevel(int levelNum);
    void recoverLevel(int levelNum);
    void cleanLevel();

    Level* getLevel() const;
    int getCurrentLevel() const;

    void init();
    void process(float deltaTime);

    EntityManager& getEntityManager();

private:
    LevelManager();
    static LevelManager* instance;

    Level* levels[2];
    int currentLevel;

    EntityManager entityManager;

};

#endif // LEVEL_MANAGER_HPP_
