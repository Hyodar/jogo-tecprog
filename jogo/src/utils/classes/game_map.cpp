
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "game_map.hpp"

// Standard libraries
// ---------------------

#include <fstream>

// External libraries
// ---------------------

#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Internal libraries
// ---------------------

#include "game.hpp"
#include "tile.hpp"
#include "graphics_manager.hpp"
#include "level_manager.hpp"

#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

GameMap* GameMap::instance = nullptr;

// Methods
// ---------------------------------------------------------------------------

GameMap::GameMap() : background(sf::Vector2f(windowW, windowH)),
 sizeX{-1}, sizeY{-1}, start{0.0f} {
    // noop
}

// ---------------------------------------------------------------------------

GameMap::~GameMap() {
    delete instance;
}

// ---------------------------------------------------------------------------

GameMap* GameMap::getInstance() {
    if(!instance) instance = new GameMap;
    return instance;
}

// ---------------------------------------------------------------------------

void GameMap::loadBackground() {
    background.setTexture(GraphicsManager::getInstance()->getBackgroundTexture());
}

// ---------------------------------------------------------------------------

void GameMap::loadMap() {

    loadBackground();

    std::ifstream file(LevelManager::getInstance()->getLevel()->getConfigPath());
    json mapInfo;
    file >> mapInfo;

    clearMap();

    sizeX = mapInfo["width"];
    sizeY = mapInfo["height"];

    for(int row = 0; row < sizeY ; row++) {
        std::vector<Tile*> lineTiles;
        for(int col = 0; col < sizeX ; col++) {
            int tile = mapInfo["layers"][0]["data"][row*sizeX + col];

            lineTiles.push_back(new Tile(tile, row, col));
        }
        tileMap.push_back(lineTiles);
    }

    file.close();
}

// ---------------------------------------------------------------------------

void GameMap::clearMap() {

    for(std::vector<Tile*>& v : tileMap) {
        for(Tile* t : v) {
            delete t;
        }
        v.clear();
    }

    tileMap.clear();
}

// ---------------------------------------------------------------------------

void GameMap::setupTileStart() {
    sf::Vector2f playerPos = Game::getInstance()->getPlayer().getPosition();

    if(playerPos.x - windowW/2 < 0) {
        start = 0;
    }
    else {
        start = (playerPos.x - windowW/2) / TILE_SIZE;
    }

    if(start + windowW/TILE_SIZE > sizeX) {
        start = sizeX - windowW / TILE_SIZE;
    }
}

// ---------------------------------------------------------------------------

void GameMap::draw() {

    setupTileStart();

    background.setTextureRect(sf::IntRect(start * TILE_SIZE, 0, windowW, windowH));
    Game::getInstance()->getMainWindow().draw(background);

    for(int vec = 0; vec < sizeY; vec++) {
        for(int i = start; i < start + windowW/TILE_SIZE; i++) {
            tileMap[vec][i]->draw(sf::Vector2f((i-start)*TILE_SIZE, vec*TILE_SIZE));
        }
    }
}

// ---------------------------------------------------------------------------
