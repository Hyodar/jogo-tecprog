
#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <SFML/Graphics.hpp>

#include "collidable.hpp"
#include "database_model.hpp"
#include "ent.hpp"

namespace bardadv::core {

class Entity : public bardadv::collision::Collidable,
               public bardadv::core::Ent,
               public bardadv::persistence::DatabaseModel {

protected:
    sf::Vector2i size;
    int classification;
    
    static int entityCount;
    int id;

public:
    Entity(int x=0, int y=0, int sizeX=0, int sizeY=0, int _classification=-1);
    virtual ~Entity();

    int getSizeX() const;
    int getSizeY() const;

    int getId() const;
    void setId(int _id);

    int getClassification() const;
    virtual json store();

    sf::FloatRect getBoundingBox() const;
    virtual void updatePositionX(float deltaTime);
    virtual void updatePositionY(float deltaTime);
    virtual void render(sf::RenderWindow& window);

    virtual void takeDamage(float dmg) = 0;
};

}

#endif // ENTITY_HPP_
