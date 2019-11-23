
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

using namespace bardadv::core;
using namespace bardadv::map;

#include <constants.hpp>

// Attribute initialization
// ---------------------------------------------------------------------------

GameMap* GameMap::instance = nullptr;

// Methods
// ---------------------------------------------------------------------------

GameMap::GameMap() : background(sf::Vector2f(WINDOW_W, WINDOW_H)),
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

    if(playerPos.x - WINDOW_W/2 < 0) {
        start = 0;
    }
    else {
        start = (playerPos.x - WINDOW_W/2) / TILE_SIZE;
    }

    if(start + WINDOW_W/TILE_SIZE > sizeX) {
        start = sizeX - WINDOW_W / TILE_SIZE;
    }
}

// ---------------------------------------------------------------------------

void GameMap::draw() {

    setupTileStart();

    background.setTextureRect(sf::IntRect(start * TILE_SIZE, 0, WINDOW_W, WINDOW_H));
    Game::getInstance()->getMainWindow().draw(background);

    for(int vec = 0; vec < sizeY; vec++) {
        for(int i = start; i < start + WINDOW_W/TILE_SIZE; i++) {
            tileMap[vec][i]->draw(sf::Vector2f((i-start)*TILE_SIZE, vec*TILE_SIZE));
        }
    }
}

// ---------------------------------------------------------------------------

float GameMap::getStart() {
    return start;
}

// ---------------------------------------------------------------------------

bool GameMap::IsAtEnd() {
    return start == sizeX - WINDOW_W/TILE_SIZE;
}

// ---------------------------------------------------------------------------

bool GameMap::IsAtStart() {
    return start == 0;
}

// ---------------------------------------------------------------------------

bool GameMap::isPositionValid(int row, int col) {
    return (row >= 0 && row < sizeY) && (col >= 0 && col < sizeX);
}

// ---------------------------------------------------------------------------

int GameMap::getSizeX() {
    return sizeX;
}

// ---------------------------------------------------------------------------

int GameMap::getSizeY() {
    return sizeX;
}

// ---------------------------------------------------------------------------

int GameMap::getMapLength() {
    return sizeX * TILE_SIZE;
}

// ---------------------------------------------------------------------------

std::vector<std::vector<Tile*>>& GameMap::getTileMap() {
    return tileMap;
}

// ---------------------------------------------------------------------------

Tile* GameMap::getTile(int line, int col) {
    return tileMap[line][col];
}
