
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "entity_list.hpp"

// Methods
// ---------------------------------------------------------------------------

EntityList::EntityList(){
    start = nullptr;
    current = nullptr;
    start->setNext(nullptr);
    current->setNext(nullptr);
    start->setPrev(nullptr);
    current->setPrev(nullptr);
}

// ---------------------------------------------------------------------------

EntityList::~EntityList(){
    deleteAll();
}

// ---------------------------------------------------------------------------

void EntityList::setCurrent(Elemento<Entity>* pc){
    current =pc;
}

// ---------------------------------------------------------------------------

void EntityList::setStart(Elemento<Entity>* ps){
    start  = ps;
}

// ---------------------------------------------------------------------------

Elemento<Entity>* EntityList::getCurrent()const{
    return current;
}

// ---------------------------------------------------------------------------

Elemento<Entity>* EntityList::getStart()const{
    return start;
}

// ---------------------------------------------------------------------------

void EntityList::insert(Entity* elem){

    Elemento<Entity>* paux;
    paux = new Elemento<Entity>();
    paux->setInfo(elem);

    if(!start){
        start = paux;
        current = paux;
    }
    else{
        current->setNext(paux);
        paux->setNext(nullptr);
        paux->setPrev(current);
        current=paux;
    }
}

// ---------------------------------------------------------------------------

void EntityList::deleteAll(){

    Elemento<Entity>* paux;

    paux=start;

    while(paux!=nullptr){
        paux = start;
        start = start->getNext();
        delete paux;
    }
}

// ---------------------------------------------------------------------------

void EntityList::travel(){

    //TODO

}
