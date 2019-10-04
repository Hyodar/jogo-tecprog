
#include "tile_manager.hpp"

#include <constants.hpp>

std::map<char, sf::Texture&> TileManager::tileSet;
char TileManager::tileSetPath[] = "resources/tileset.png";
/*
void TileManager::loadTileSet() {
    tileSetTexture.loadFromFile(tileSetPath);

    //  TODO
}

sf::Texture& TileManager::getTileTexture(char tileChar) {
    
    // TODO return tileSet[tileChar];
}
*/
sf::RectangleShape* TileManager::TEST_getTileTexture(char tileChar) {
    sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));

    if(tileChar == '0') {
       rect->setFillColor(sf::Color::Black); 
    }
    else if(tileChar == 'B') {
        rect->setFillColor(sf::Color::Yellow);
    }

    return rect;
}
