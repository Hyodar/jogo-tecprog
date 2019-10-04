
#include "game_map.hpp"

#include <string>
#include <constants.hpp>

std::vector<std::vector<Tile>> GameMap::tileMap;
int GameMap::sizeX = -1;
int GameMap::sizeY = -1;

void GameMap::loadMap() {
    std::string map[24];
    map[0] = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
    for(int i = 1; i < 23; i++) map[i] = "B                              B";
    map[23] = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";

    sizeX = 32;
    sizeY = 24;

    tileMap.clear();

    for(int line = 0; line < sizeY ; line++) {
        std::vector<Tile> lineTiles;
        for(int col = 0; col < sizeX ; col++) {
            lineTiles.push_back(Tile(map[line][col]));
        }
        tileMap.push_back(lineTiles);
    }
}

void GameMap::drawTiles(sf::Vector2f playerPos) {
    // TODO - considerar playerPos

    // - window
    int start;

    if(playerPos.x - windowW/2 > 0) {
        start = (playerPos.x - windowW/2) / TILE_SIZE;
    } 
    else {
        start = 0;
    }

    if((playerPos.x + windowW/2)/TILE_SIZE > sizeX) {
        start = sizeX - windowW/TILE_SIZE;
    }
    
    for(int vec = 0; vec < sizeY; vec++) {
        for(int i = start; i < start + windowW/TILE_SIZE; i++) {
            tileMap[vec][i].draw(sf::Vector2f((i-start)*TILE_SIZE, vec*TILE_SIZE));
        }
    }
}