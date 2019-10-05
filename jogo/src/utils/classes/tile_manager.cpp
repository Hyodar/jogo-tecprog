
#include "tile_manager.hpp"

#include <constants.hpp>

std::map<int, sf::RectangleShape*> TileManager::tileSet;
sf::Texture TileManager::tileSetTexture;
char TileManager::tileSetPath[] = "resources/sheet.png";

void TileManager::createTile(int tileNumber, sf::IntRect rect) {
    sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    shape->setTexture(&tileSetTexture);
    shape->setTextureRect(rect);

    tileSet.insert({ tileNumber, shape });
}

void TileManager::loadTileSet() {
    tileSetTexture.loadFromFile(tileSetPath);

    tileSet.insert({ EmptyTile, nullptr });

    createTile(StoneWoodFloor, sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
    createTile(WoodPlatform1,  sf::IntRect(2*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    createTile(WoodPlatform2,  sf::IntRect(3*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    createTile(WoodPlatform3,  sf::IntRect(4*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    createTile(WoodPillar,     sf::IntRect(TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
}

sf::RectangleShape* TileManager::getTileTexture(int tileNumber) {
    return tileSet[tileNumber];
}
