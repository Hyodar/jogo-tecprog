
// Libraries
// ---------------------------------------------------------------------------

// Class header
#include "tile_manager.hpp"

// Internal libraries
#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

std::map<int, Tile> TileManager::tileSet;
sf::Texture TileManager::tileSetTexture;
char TileManager::tileSetPath[] = "resources/sheet.png";

// Methods
// ---------------------------------------------------------------------------

TileManager::TileManager() {

}

TileManager::~TileManager() {

}

void TileManager::createTile(int tileNumber, sf::IntRect textureRect,
                             sf::FloatRect colliderRect) {
    sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    shape->setTexture(&tileSetTexture);
    shape->setTextureRect(textureRect);
    Tile tile(tileNumber, shape, colliderRect);

    tileSet.insert({ tileNumber, Tile(tileNumber, shape, colliderRect) });
}

// ---------------------------------------------------------------------------

void TileManager::loadTileSet() {
    tileSetTexture.loadFromFile(tileSetPath);

    //            TILE_ID                TILE_POSITION_ON_SHEET                                 TILE_COLLIDER
    createTile(StoneWoodFloor, sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE),           sf::FloatRect(0, 0, TILE_SIZE, TILE_SIZE));
    createTile(WoodPlatform1,  sf::IntRect(2*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(0, 0, TILE_SIZE, TILE_SIZE/2));
    createTile(WoodPlatform2,  sf::IntRect(3*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(0, 0, TILE_SIZE, TILE_SIZE/2));
    createTile(WoodPlatform3,  sf::IntRect(4*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(0, 0, TILE_SIZE, TILE_SIZE/2));
    createTile(FloorSpikes,    sf::IntRect(5*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE), sf::FloatRect(0, 0, TILE_SIZE, TILE_SIZE));
    createTile(WoodPillar,     sf::IntRect(TILE_SIZE, 0, TILE_SIZE, TILE_SIZE),   sf::FloatRect(0, 0, TILE_SIZE, TILE_SIZE));
}

// ---------------------------------------------------------------------------

sf::RectangleShape* TileManager::getTileTexture(int tileNumber) {
    if(tileNumber != EmptyTile) {
        return tileSet[tileNumber].getTileTexture();
    }
    else return nullptr;
}

// ---------------------------------------------------------------------------

sf::FloatRect TileManager::getTileCollider(int tileNumber) {
    if(tileNumber != EmptyTile) {
        return tileSet[tileNumber].getTileCollider();
    }
    else return sf::FloatRect(0, 0, 0, 0);
}
