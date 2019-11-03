
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "tile.hpp"

// Internal libraries
#include "game.hpp"
#include "tile_manager.hpp"

#include <constants.hpp>

// Methods
// ---------------------------------------------------------------------------

Tile::Tile(int tileNum, int row, int col)
  : tileNumber{tileNum},
    rect{TileManager::getInstance()->getTileTexture(tileNumber)},
    collider{TileManager::getInstance()->getTileCollider(tileNumber)} {

    collider.top  += row * TILE_SIZE;
    collider.left += col * TILE_SIZE;
}

// ---------------------------------------------------------------------------

Tile::Tile(int tileNum, sf::RectangleShape* shape, sf::FloatRect coll)
: tileNumber{tileNum}, rect{shape}, collider{coll} {
    // noop
}

// ---------------------------------------------------------------------------

void Tile::draw(sf::Vector2f pos) {
    if(tileNumber != 0) {
        rect->setPosition(pos.x, pos.y);
        Game::getInstance()->getMainWindow().draw(*rect);
    }
}
