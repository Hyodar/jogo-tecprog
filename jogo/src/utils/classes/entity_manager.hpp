
#ifndef ENTITY_MANAGER_HPP_
#define ENTITY_MANAGER_HPP_

#include <SFML/Graphics.hpp>

#include "list.hpp"

class Entity;
class Enemy;
class Bardo;
class FielEscudeiro;
class Obstacle;

class EntityManager {

private:

    Bardo* bardo;
    FielEscudeiro* fielEscudeiro;

    bool hasEscudeiro;

    // List entities;
    List<Obstacle*> obstacles;
    List<Enemy*> enemies;

public:

    EntityManager();
    ~EntityManager();

    void addObstacle(Obstacle* o);
    void addEnemy(Enemy* c);
    void clean();
    void process(float deltaTime); // processa movimento e colisao
    void render(sf::RenderWindow& window);

    //void checkAttack(sf::FloatRect box); // checa se aquela box se intercepta com alguem
    void checkAttack(sf::FloatRect hitBox, float dmg); // Attack -> box, dano
    
    void moveBardo(const float deltaTime);
    void moveEscudeiro(const float deltaTime);
    void moveEnemies(const float deltaTime);
    void moveObstacles(const float deltaTime);

    //std::vector<Obstacle*> getObstacles() { return obstacles; }
    //std::vector<Enemy*> getEnemies() { return enemies; }

    void setBardo(Bardo* b) { bardo = b; }
    void setFielEscudeiro(FielEscudeiro* f) { fielEscudeiro = f; }
    void setHasEscudeiro(bool b) { hasEscudeiro = b; }

};

#endif // ENTITY_MANAGER_HPP_
