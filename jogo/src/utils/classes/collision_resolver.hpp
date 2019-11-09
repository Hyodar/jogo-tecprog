
#ifndef COLLISION_RESOLVER_
#define COLLISION_RESOLVER_

#include "entity.hpp"

#include "tile.hpp"
#include "bardo.hpp"
#include "fiel_escudeiro.hpp"
#include "character.hpp"
#include "obstacle.hpp"
#include "game_map.hpp"

class CollisionResolver {

public:

    static bool collideX(Character* c, GameMap* g);
    static bool collideY(Character* c, GameMap* g);

    static bool collideX(Character* c, Tile* t);
    static bool collideY(Character* c, Tile* t);

    static bool collideX(Bardo* b, Character* c);
    static bool collideY(Bardo* b, Character* c);

    static bool collideX(FielEscudeiro* f, Character* c);
    static bool collideY(FielEscudeiro* f, Character* c);
    
    static bool collideX(Bardo* b, Obstacle* o);
    static bool collideY(Bardo* b, Obstacle* o);

    static bool collideX(FielEscudeiro* f, Obstacle* o);
    static bool collideY(FielEscudeiro* f, Obstacle* o);

private:

    static bool isColliding(Collidable* e1, Collidable* e2);

};

#endif // COLLISION_RESOLVER_
