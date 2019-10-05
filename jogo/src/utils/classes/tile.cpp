
#include "tile.hpp"

#include "game.hpp"
#include "tile_manager.hpp"

Tile::Tile(int tileNum) : tileNumber{tileNum} {
    TEST_rect = TileManager::TEST_getTileTexture(tileNumber);
}

void Tile::draw(sf::Vector2f pos) {
    if(tileNumber != 0) {
        TEST_rect->setPosition(pos.x, pos.y);
        Game::getMainWindow().draw(*TEST_rect);
    }
}

// TODO - fazer classe Obstacle q retorna true

bool Tile::collide() {
    return tileNumber == 1;
}
