
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "character.hpp"

// Internal libraries
#include "game_map.hpp"
#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

sf::Texture Player::texture;
const int Player::jumpSpeed{2000};
const int Player::walkSpeed{500};

// Methods
// ---------------------------------------------------------------------------
Character::Character (int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0)
