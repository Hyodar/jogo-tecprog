
#include "level.hpp"

#include <fstream>

// External libraries
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <constants.hpp>

Level::Level(const char* configFile) : configPath{configFile} {
    // TODO
}

Level::~Level() {
    // noop
}

void Level::init() {
    std::ifstream file(configPath);
    json mapInfo;
    file >> mapInfo;

    std::vector<int> matrix;
    auto jsonMat = mapInfo["layers"][1]["data"];
    
    for(int n : jsonMat) {
        matrix.push_back(n);
    }

    spawnAll(matrix, static_cast<int>(mapInfo["width"]));
    // Game.loadBackground(mapInfo["backgroundPath"]); - TODO
}

void Level::spawnAll(std::vector<int>& mat, int layerWidth) {
    spawnEnemies(mat, layerWidth);
    spawnObstacles(mat, layerWidth);
}

sf::Vector2f Level::getSpawnPosition(uint pos, int layerWidth) {
    const int x = pos % layerWidth;
    const int y = pos / layerWidth;
    return sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);
}
