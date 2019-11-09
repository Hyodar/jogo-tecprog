
#ifndef ENTITY_MANAGER_HPP_
#define ENTITY_MANAGER_HPP_

#include <SFML/Graphics.hpp>

#include <vector>
#include "entity.hpp"
#include "obstacle.hpp"

class Bardo;
class FielEscudeiro;
class Character;

class EntityManager {

private:

    Bardo* bardo;
    FielEscudeiro* fielEscudeiro;

    bool hasEscudeiro;

    // List entities;
    std::vector<Obstacle*> obstacles;
    std::vector<Character*> characters;

public:

    EntityManager();
    ~EntityManager();

    void addObstacle(Obstacle* o);
    void addCharacter(Character* c);
    void clean();
    void process(float deltaTime); // processa movimento e colisao

    //void checkAttack(sf::FloatRect box); // checa se aquela box se intercepta com alguem
    void checkAttack(sf::FloatRect hitBox, float dmg); // Attack -> box, dano
    
    void moveBardo(const float deltaTime);
    void moveEscudeiro(const float deltaTime);
    void moveEnemies(const float deltaTime);
    void moveObstacles(const float deltaTime);

    std::vector<Obstacle*> getObstacles() { return obstacles; }
    std::vector<Character*> getCharacters() { return characters; }

    void setBardo(Bardo* b) { bardo = b; }
    void setFielEscudeiro(FielEscudeiro* f) { fielEscudeiro = f; }
    void setHasEscudeiro(bool b) { hasEscudeiro = b; }

};

#endif // ENTITY_MANAGER_HPP_
