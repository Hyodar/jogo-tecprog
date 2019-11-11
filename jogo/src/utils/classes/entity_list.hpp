#ifndef ENTITYLIST_HPP_
#define ENTITYLIST_HPP_

#include"elemento.hpp"
#include"entity.hpp"

class EntityList{

private:
    Elemento<Entity>* start;
    Elemento<Entity>* current;

public:
    EntityList();
    ~EntityList();

    void setCurrent(Elemento<Entity>* pc);
    void setStart(Elemento<Entity>* ps);
    Elemento<Entity>* getCurrent()const;
    Elemento<Entity>* getStart()const;

    void insert(Entity* elem);
    void deleteAll();
    void travel();
};

#endif // ENTITYLIST_HPP_
