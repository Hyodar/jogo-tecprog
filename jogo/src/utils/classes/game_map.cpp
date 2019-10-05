
#include "game_map.hpp"

#include <string>
#include <constants.hpp>

std::vector<std::vector<Tile>> GameMap::tileMap;
int GameMap::sizeX = -1;
int GameMap::sizeY = -1;
float GameMap::start = 0.0f;

void GameMap::loadMap() {
    std::string map[16];
    map[0] = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
    for(int i = 1; i < 11; i++) map[i] = "P                                                              P";
    map[9] = "P         abc                  abc                             P";
    map[11] = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";

    sizeX = 64;
    sizeY = 12;

    tileMap.clear();

    for(int line = 0; line < sizeY ; line++) {
        std::vector<Tile> lineTiles;
        for(int col = 0; col < sizeX ; col++) {
            lineTiles.push_back(Tile(map[line][col]));
        }
        tileMap.push_back(lineTiles);
    }
}

void GameMap::setupTileStart(sf::Vector2f playerPos) {
    if(playerPos.x - windowW/2 < 0) {
        start = 0;
    } 
    else {
        start = (playerPos.x - windowW/2) / TILE_SIZE;
    }

    if(start + windowW/TILE_SIZE > sizeX) {
        start = sizeX - windowW/TILE_SIZE;
    }
}

void GameMap::drawTiles(sf::Vector2f playerPos) {
    // TODO - considerar playerPos

    setupTileStart(playerPos);
    
    for(int vec = 0; vec < sizeY; vec++) {
        for(int i = start; i < start + windowW/TILE_SIZE; i++) {
            tileMap[vec][i].draw(sf::Vector2f((i-start)*TILE_SIZE, vec*TILE_SIZE));
        }
    }
}
