
#ifndef ENTITY_LIST_HPP_
#define ENTITY_LIST_HPP_

#include <SFML/Graphics.hpp>

#include "list.hpp"
#include "entity.hpp"
#include "game.hpp"
#include "database_model.hpp"

class EntityList : public DatabaseModel {

private:
    List<Entity*> list;
    bool hasEscudeiro;

public:
    EntityList() : hasEscudeiro{false} {}
    ~EntityList() {}

    void setHasEscudeiro(bool b);

    void add(Entity* e);
    void remove(Entity* e);
    
    void moveX(const float deltaTime);
    void moveY(const float deltaTime);

    void render(sf::RenderWindow& window);
    void clean();

    json store();
};

#endif // ENTITY_LIST_HPP_
