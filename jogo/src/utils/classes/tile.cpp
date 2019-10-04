
#include "tile.hpp"

#include "game.hpp"
#include "tile_manager.hpp"

Tile::Tile(char tileCh) : collision{false}, tileChar{tileCh} {
    if(tileChar == 'B') {
        collision = true;
    }

    TEST_rect = TileManager::TEST_getTileTexture(tileChar);
}

void Tile::draw(sf::Vector2f pos) {
    if(tileChar != '0') {
        TEST_rect->setPosition(pos.x, pos.y);
        Game::getMainWindow().draw(*TEST_rect);
    }
}