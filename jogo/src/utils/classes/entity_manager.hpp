
#ifndef ENTITY_MANAGER_HPP_
#define ENTITY_MANAGER_HPP_

#include <SFML/Graphics.hpp>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "list.hpp"

#include "entity_list.hpp"
#include "collision_list.hpp"

class Entity;
class Enemy;
class Bardo;
class FielEscudeiro;
class Obstacle;
class Projectile;

class EntityManager {

private:
    EntityList entityList;
    CollisionList collisionList;    

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

    //void checkAttack(sf::FloatRect box); // checa se aquela box se intercepta com alguem
    //std::vector<Obstacle*> getObstacles() { return obstacles; }
    //std::vector<Enemy*> getEnemies() { return enemies; }

    void setBardo(Bardo* b) { 
        entityList.add(static_cast<Entity*>(b));
        collisionList.add(b);
    }
    void setFielEscudeiro(FielEscudeiro* f) {
        entityList.setHasEscudeiro(true);
        entityList.add(static_cast<Entity*>(f));
        collisionList.add(f);
    }

    json store();

};

#endif // ENTITY_MANAGER_HPP_
