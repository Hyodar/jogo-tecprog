
#include "tile.hpp"

#include "game.hpp"
#include "tile_manager.hpp"

Tile::Tile(char tileCh) : tileChar{tileCh} {
    TEST_rect = TileManager::TEST_getTileTexture(tileChar);
}

void Tile::draw(sf::Vector2f pos) {
    if(tileChar != ' ') {
        TEST_rect->setPosition(pos.x, pos.y);
        Game::getMainWindow().draw(*TEST_rect);
    }
}

// TODO - fazer classe Obstacle q retorna true

bool Tile::collide() {
    return tileChar == 'B' 
           || tileChar == 'P' 
           || tileChar == 'a' 
           || tileChar == 'b' 
           || tileChar == 'c';
}
