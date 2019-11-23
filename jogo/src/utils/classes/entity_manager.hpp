
#ifndef ENTITY_MANAGER_HPP_
#define ENTITY_MANAGER_HPP_

#include <SFML/Graphics.hpp>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "entity_list.hpp"
#include "collision_list.hpp"

namespace bardadv::core {
class Entity;
}

namespace bardadv::characters {
class Enemy;
class Bardo;
class FielEscudeiro;
}

namespace bardadv::obstacles {
class Obstacle;
}

namespace bardadv::projectiles {
class Projectile;
}

namespace bardadv::core {

using bardadv::core::Entity;
using bardadv::characters::Enemy;
using bardadv::characters::Bardo;
using bardadv::characters::FielEscudeiro;
using bardadv::obstacles::Obstacle;
using bardadv::projectiles::Projectile;

class EntityManager {

private:
    bardadv::lists::EntityList entityList;
    bardadv::lists::CollisionList collisionList;

public:
    EntityManager();
    ~EntityManager();

    void addObstacle(Obstacle* e);
    void addEnemy(Enemy* e);
    void removeEnemy(Enemy* e);
    void addProjectile(Projectile* e);
    void removeProjectile(Projectile* e);
    void removeFielEscudeiro(FielEscudeiro* f);

    void clean();
    void process(float deltaTime); // processa movimento e colisao
    void render(sf::RenderWindow& window);

    Entity* getEntityById(int id);

    void setBardo(Bardo* b);
    void setFielEscudeiro(FielEscudeiro* f);

    json store();

};

}

#endif // ENTITY_MANAGER_HPP_
