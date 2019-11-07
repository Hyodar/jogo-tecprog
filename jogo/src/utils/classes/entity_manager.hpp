
#ifndef ENTITY_MANAGER_HPP_
#define ENTITY_MANAGER_HPP_

#include <SFML/Graphics.hpp>

#include <vector>
#include "entity.hpp"

// #include "attack.hpp"

class Character;

class EntityManager {

private:

    // List entities;
    std::vector<Entity*> obstacles;
    std::vector<Character*> characters;

public:

    EntityManager();
    ~EntityManager();

    void addObstacle(Entity* entity);
    void addCharacter(Character* c);
    void clean();
    void process(float deltaTime); // processa movimento e colisao

    //void checkAttack(sf::FloatRect box); // checa se aquela box se intercepta com alguem
    void checkAttack(sf::FloatRect hitBox, float dmg); // Attack -> box, dano
    void checkCharacterXCollision(Character* c);
    void checkCharacterYCollision(Character* c);

    std::vector<Entity*> getObstacles() { return obstacles; }
    std::vector<Character*> getCharacters() { return characters; }

};

#endif // ENTITY_MANAGER_HPP_
