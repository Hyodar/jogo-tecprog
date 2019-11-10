
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "collision_resolver.hpp"

// Internal libraries
// ---------------------

#include "tile.hpp"
#include "bardo.hpp"
#include "fiel_escudeiro.hpp"
#include "enemy.hpp"
#include "character.hpp"
#include "obstacle.hpp"
#include "game_map.hpp"

// Methods
// ---------------------------------------------------------------------------

bool CollisionResolver::CollisionResolver::isColliding(Collidable* e1, Collidable* e2) {
    return e1->getBoundingBox().intersects(e2->getBoundingBox());
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideX(Character* c, GameMap* g) {
    for(int i = c->getPosY()/TILE_SIZE; i < (c->getPosY() + c->getSizeY())/TILE_SIZE; i++) {
        for(int j = c->getPosX()/TILE_SIZE; j < (c->getPosX() + c->getSizeX())/TILE_SIZE; j++) {
            Tile* tile = g->getTile(i, j);
            if(collideX(c, tile)) return true;
        }
    }
    return false;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideY(Character* c, GameMap* g) {
    for(int i = c->getPosY()/TILE_SIZE; i < (c->getPosY() + c->getSizeY())/TILE_SIZE; i++) {
        for(int j = c->getPosX()/TILE_SIZE; j < (c->getPosX() + c->getSizeX())/TILE_SIZE; j++) {
            Tile* tile = g->getTile(i, j);
            if(collideY(c, tile)) return true;
        }
    }
    return false;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideY(Character* c, Tile* t) {
    const Tile e = *t;

    if(!isColliding(c, t)) return false;

    if(c->getSpeedY() > 0) {
        c->setPosY(e.getBoundingBox().top - c->getSizeY());
        c->setOnGround(true);
    }
    else if(c->getSpeedY() < 0) c->setPosY(e.getBoundingBox().top + e.getBoundingBox().height);
    c->setSpeedY(0);

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideX(Character* c, Tile* t) {
    const Tile e = *t;

    if(!isColliding(c, t)) return false;

    if(c->getSpeedX() > 0) {
        c->setPosX(e.getBoundingBox().left - c->getSizeX());
    }
    else if(c->getSpeedX() < 0) c->setPosX(e.getBoundingBox().left + e.getBoundingBox().width);
    c->setSpeedX(0);

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideX(Bardo* b, Enemy* c) {
    if(!isColliding(b, c)) return false;

    b->takeDamage(20); // TODO - TROCAR PRA c->attackb

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideY(Bardo* b, Enemy* c) {
    if(!isColliding(b, c)) return false;

    b->jump();
    b->takeDamage(20);

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideX(FielEscudeiro* f, Enemy* c) {
    if(!isColliding(f, c)) return false;

    f->takeDamage(10);

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideY(FielEscudeiro* f, Enemy* c) {
    if(!isColliding(f, c)) return false;

    f->jump();
    f->takeDamage(10);

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideX(Bardo* b, Obstacle* o) {
    if(!isColliding(b, o)) return false;

    if(b->getSpeedX() > 0) {
        b->setPosX(o->getBoundingBox().left - b->getSizeX());
    }
    else if(b->getSpeedX() < 0) b->setPosX(o->getBoundingBox().left + o->getBoundingBox().width);
    b->setSpeedX(0);
    if(o->getCollisionDmg()) b->takeDamage(o->getCollisionDmg());

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideY(Bardo* b, Obstacle* o) {
    if(!isColliding(b, o)) return false;

    if(b->getSpeedY() > 0) {
        b->setPosY(o->getBoundingBox().top - b->getSizeY());
        b->setOnGround(true);
    }
    else if(b->getSpeedY() < 0) {
        b->setPosY(o->getBoundingBox().top + o->getBoundingBox().height);
    }
    b->setSpeedY(0);
    // n tem problema usar takeDamage duas vezes se for o caso,
    // tem o tempo de invulnerabilidade
    if(o->getCollisionDmg()) b->takeDamage(o->getCollisionDmg());

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideX(Enemy* e, Obstacle* o) {
    if(!isColliding(e, o)) return false;

    if(e->getSpeedX() > 0) {
        e->setPosX(o->getBoundingBox().left - e->getSizeX());
    }
    else if(e->getSpeedX() < 0) e->setPosX(o->getBoundingBox().left + o->getBoundingBox().width);
    e->setSpeedX(0);

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideY(Enemy* e, Obstacle* o) {
    if(!isColliding(e, o)) return false;

    if(e->getSpeedY() > 0) {
        e->setPosY(o->getBoundingBox().top - e->getSizeY());
        e->setOnGround(true);
    }
    else if(e->getSpeedY() < 0) {
        e->setPosY(o->getBoundingBox().top + o->getBoundingBox().height);
    }
    e->setSpeedY(0);

    return true;
}

// ---------------------------------------------------------------------------

/*
// Tentei adicionar colisão inimigo-inimigo, funcionou mas n ficou mt legal

bool CollisionResolver::collideX(Enemy* e1, Enemy* e2) {
    if(!isColliding(e1, e2)) return false;

    if(e1->getSpeedX() > 0) {
        e1->setPosX(e2->getBoundingBox().left - e1->getSizeX());
    }
    else if(e1->getSpeedX() < 0) e1->setPosX(e2->getBoundingBox().left + e2->getBoundingBox().width);
    e1->setSpeedX(0);

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideY(Enemy* e1, Enemy* e2) {
    if(!isColliding(e1, e2)) return false;

    if(e1->getSpeedY() > 0) {
        e1->setPosY(e2->getBoundingBox().top - e1->getSizeY());
        e1->setOnGround(true);
    }
    else if(e1->getSpeedY() < 0) {
        e1->setPosY(e2->getBoundingBox().top + e2->getBoundingBox().height);
    }
    e1->setSpeedY(0);

    return true;
}

// ---------------------------------------------------------------------------

*/

bool CollisionResolver::collideX(FielEscudeiro* f, Obstacle* o) {
    if(!isColliding(f, o)) return false;

    if(f->getSpeedX() > 0) {
        f->setPosX(o->getBoundingBox().left - f->getSizeX());
    }
    else if(f->getSpeedX() < 0) f->setPosX(o->getBoundingBox().left + o->getBoundingBox().width);
    f->setSpeedX(0);
    if(o->getCollisionDmg()) f->takeDamage(o->getCollisionDmg());

    return true;
}

// ---------------------------------------------------------------------------

bool CollisionResolver::collideY(FielEscudeiro* f, Obstacle* o) {
    if(!isColliding(f, o)) return false;

    if(f->getSpeedY() > 0) {
        f->setPosY(o->getBoundingBox().top - f->getSizeY());
        f->setOnGround(true);
    }
    else if(f->getSpeedY() < 0) {
        f->setPosY(o->getBoundingBox().top + o->getBoundingBox().height);
    }
    f->setSpeedY(0);
    if(o->getCollisionDmg()) f->takeDamage(o->getCollisionDmg() - 5);

    return true;
}
