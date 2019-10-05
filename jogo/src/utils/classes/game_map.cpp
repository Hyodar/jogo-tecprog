
#include "game_map.hpp"
#include "game.hpp"

#include <fstream>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::vector<std::vector<Tile>> GameMap::tileMap;
std::vector<std::vector<Obstacle>> GameMap::collisionTileMap;

sf::Texture GameMap::backgroundTexture;
sf::RectangleShape GameMap::background(sf::Vector2f(windowW, windowH));

int GameMap::sizeX = -1;
int GameMap::sizeY = -1;
float GameMap::start = 0.0f;

void GameMap::loadBackground() {
    backgroundTexture.loadFromFile("resources/maps/map1_background.png");
    background.setTexture(&backgroundTexture);
}

void GameMap::loadMap() {

    loadBackground();

    std::ifstream file("resources/maps/map1.json");
    json mapInfo;
    file >> mapInfo;

    sizeX = mapInfo["width"];
    sizeY = mapInfo["height"];

    tileMap.clear();

    for(int line = 0; line < sizeY ; line++) {
        std::vector<Tile> lineTiles;
        for(int col = 0; col < sizeX ; col++) {
            int tile = mapInfo["layers"][0]["data"][line*sizeX + col];
            lineTiles.push_back(Tile(tile));
        }
        tileMap.push_back(lineTiles);
    }
    
    loadCollisionMap();
}

void GameMap::loadCollisionMap() {
    
    std::ifstream file("resources/maps/map1_collision.json");
    json mapInfo;
    file >> mapInfo;

    collisionTileMap.clear();

    int collX = sizeX * (TILE_SIZE / COLLISION_TILE_SIZE);
    int collY = sizeY * (TILE_SIZE / COLLISION_TILE_SIZE);

    for(int line = 0; line < collY; line++) {
        std::vector<Obstacle> lineTiles;
        for(int col = 0; col < collX; col++) {
            int obstacleType = mapInfo["layers"][1]["data"][line*collX + col];
            lineTiles.push_back(Obstacle(obstacleType));
        }
        collisionTileMap.push_back(lineTiles);
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
        start = sizeX - windowW / TILE_SIZE;
    }
}

void GameMap::draw(sf::Vector2f playerPos) {

    setupTileStart(playerPos);

    background.setTextureRect(sf::IntRect(start * TILE_SIZE, 0, windowW, windowH));
    Game::getMainWindow().draw(background);
    
    for(int vec = 0; vec < sizeY; vec++) {
        for(int i = start; i < start + windowW/TILE_SIZE; i++) {
            tileMap[vec][i].draw(sf::Vector2f((i-start)*TILE_SIZE, vec*TILE_SIZE));
        }
    }
}
