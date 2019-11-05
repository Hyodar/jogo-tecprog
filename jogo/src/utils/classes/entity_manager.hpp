
#include <SFML/Graphics.hpp>

#include "attack.hpp"

class EntityManager {

public:
    // List entities;
    void clean();
    void process(); // processa movimento e colisao

     void checkAttack(sf::FloatRect box); // checa se aquela box se intercepta com alguem
    //void checkAttack(Attack attack); // Attack -> box, dano

};
