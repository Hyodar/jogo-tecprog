
#ifndef ENTITY_LIST_HPP_
#define ENTITY_LIST_HPP_

#include <SFML/Graphics.hpp>

#include "list.hpp"
#include "database_model.hpp"

namespace bardadv::core {
class Entity;
}

namespace bardadv::lists {

using bardadv::core::Entity;

class EntityList : public bardadv::persistence::DatabaseModel {

private:
    bardadv::lists::List<Entity*> list;
    bool hasEscudeiro;

public:
    EntityList();
    ~EntityList();

    void setHasEscudeiro(bool b);

    void add(Entity* e);
    void remove(Entity* e);

    void moveX(const float deltaTime);
    void moveY(const float deltaTime);

    Entity* getEntityById(int id);

    void render(sf::RenderWindow& window);
    void clean();

    json store();
};

}

#endif // ENTITY_LIST_HPP_
