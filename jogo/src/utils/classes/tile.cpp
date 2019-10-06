
#include "tile.hpp"

#include "game.hpp"
#include "tile_manager.hpp"
#include <constants.hpp>

Tile::Tile(int tileNum, int row, int col) : tileNumber{tileNum} {
    rect = TileManager::getTileTexture(tileNumber);
    collider = TileManager::getTileCollider(tileNumber);
    
    collider.top  += row * TILE_SIZE;
    collider.left += col * TILE_SIZE;
}

Tile::Tile(int tileNum, sf::RectangleShape* shape, sf::FloatRect coll) 
: tileNumber{tileNum}, rect{shape}, collider{coll} {
    // noop
}

void Tile::draw(sf::Vector2f pos) {
    if(tileNumber != 0) {
        rect->setPosition(pos.x, pos.y);
        Game::getMainWindow().draw(*rect);
    }
}

bool Tile::collide(Player& player) const {
    return player.getBoundingBox().intersects(collider);
}
