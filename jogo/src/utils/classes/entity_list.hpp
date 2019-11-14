
#ifndef ENTITY_LIST_HPP_
#define ENTITY_LIST_HPP_

#include "list.hpp"
#include "entity.hpp"
#include "game.hpp"
#include <SFML/Graphics.hpp>

class EntityList {

private:
    List<Entity*> list;
    bool hasEscudeiro;

public:
    EntityList() {}
    ~EntityList() {}

    void setHasEscudeiro(bool b);

    void add(Entity* e);
    void remove(Entity* e);
    
    void moveX(const float deltaTime);
    void moveY(const float deltaTime);

    void render(sf::RenderWindow& window);
    void clean();
};

#endif // ENTITY_LIST_HPP_
