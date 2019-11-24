
#ifndef COLLISION_LIST_HPP_
#define COLLISION_LIST_HPP_

#include <vector>
#include <map>
#include <deque>

#include <game_config.hpp>

#include "collision_detecter.hpp"

namespace bardadv::core {
class LevelManager;
}

namespace bardadv::obstacles {
class Obstacle;
}

namespace bardadv::characters {
class Enemy;
class Bardo;
class FielEscudeiro;
}

namespace bardadv::projectiles {
class Projectile;
}

namespace bardadv::map {
class GameMap;
class Tile;
}

namespace bardadv::lists {

using bardadv::obstacles::Obstacle;
using bardadv::characters::Enemy;
using bardadv::characters::Bardo;
using bardadv::characters::FielEscudeiro;
using bardadv::projectiles::Projectile;
using bardadv::map::GameMap;
using bardadv::map::Tile;

class CollisionList {

private:
    // containers STL para preencher requisitos,
    // como sugerido pelo professor
    std::vector<Enemy*> enemies;
    std::map<int, Obstacle*> obstacles;
    std::deque<Projectile*> projectiles;

    Bardo* bardo;
    FielEscudeiro* fielEscudeiro;

    bardadv::collision::CollisionDetecter collisionDetecter;

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

}

#endif // COLLISION_LIST_HPP_
