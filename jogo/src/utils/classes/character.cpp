
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "character.hpp"

// Internal libraries
#include "game_map.hpp"
#include <constants.hpp>

// Attribute initialization
const int Character::jumpSpeed{1670};
const int Character::walkSpeed{500};
// ---------------------------------------------------------------------------


// Methods
// ---------------------------------------------------------------------------
Character::Character (int x, int y, int sizeX, int sizeY, double maxHP)
    : Entity(x, y, sizeX, sizeY), speed(0, 0), hitPoints{100},
     maxHitPoints(maxHP),onGround{false} {

}

Character :: ~Character( ) { }
