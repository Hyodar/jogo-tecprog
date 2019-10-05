
#include "tile.hpp"

#include "game.hpp"
#include "tile_manager.hpp"

Tile::Tile(int tileNum) : tileNumber{tileNum} {
    rect = TileManager::getTileTexture(tileNumber);
}

void Tile::draw(sf::Vector2f pos) {
    if(tileNumber != 0) {
        rect->setPosition(pos.x, pos.y);
        Game::getMainWindow().draw(*rect);
    }
}
