
#ifndef COLLISION_LIST_HPP_
#define COLLISION_LIST_HPP_

#include <vector>
#include <map>
#include <deque>

#include <constants.hpp>

#include "collision_detecter.hpp"
//#include "level_manager.hpp"

class LevelManager;
class Enemy;
class Obstacle;
class Projectile;
class Bardo;
class FielEscudeiro;
class GameMap;
class Tile;

class CollisionList {

private:
    // containers STL para preencher requisitos,
    // como sugerido pelo professor
    std::vector<Enemy*> enemies;
    std::map<int, Obstacle*> obstacles;
    std::deque<Projectile*> projectiles;

    Bardo* bardo;
    FielEscudeiro* fielEscudeiro;

    CollisionDetecter collisionDetecter;

public:
    CollisionList();
    ~CollisionList();

    void add(Enemy* e);
    void add(Obstacle* e);
    void add(Projectile* e);
    void add(Bardo* e);
    void add(FielEscudeiro* e);

    void remove(Enemy* e);
    void remove(Obstacle* e);
    void remove(Projectile* e);

    void deallocate();

    void testCollisionX();
    void testCollisionY();

    void testBardoX();
    void testBardoY();
    void testFielEscudeiroX();
    void testFielEscudeiroY();
    void testEnemiesX();
    void testEnemiesY();
    void testProjectiles();
    void testHitPoints();
};

#endif // COLLISION_LIST_HPP_
