
#include "tile_manager.hpp"

#include <constants.hpp>

std::map<char, sf::RectangleShape*> TileManager::tileSet;
sf::Texture TileManager::tileSetTexture;
char TileManager::tileSetPath[] = "resources/sheet.png";

void TileManager::createTile(char tileChar, sf::IntRect rect) {
    sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    shape->setTexture(&tileSetTexture);
    shape->setTextureRect(rect);

    tileSet.insert({ tileChar, shape });
}

void TileManager::loadTileSet() {
    tileSetTexture.loadFromFile(tileSetPath);

    createTile('B', sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
    createTile('P', sf::IntRect(TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    createTile('a', sf::IntRect(2*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    createTile('b', sf::IntRect(3*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    createTile('c', sf::IntRect(4*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
}

/*
sf::Texture& TileManager::getTileTexture(char tileChar) {
    
    // TODO return tileSet[tileChar];
}
*/

sf::RectangleShape* TileManager::TEST_getTileTexture(char tileChar) {
    return tileSet[tileChar];
}
