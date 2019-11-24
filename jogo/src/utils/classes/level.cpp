
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "level.hpp"

// Standard libraries
// ---------------------

#include <fstream>

// External libraries
// ---------------------

#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Internal libraries
// ---------------------

#include <game_config.hpp>

using namespace bardadv::levels;

// Methods
// ---------------------------------------------------------------------------

Level::Level(const char* configFile) : configPath{configFile} {
    // TODO
}

// ---------------------------------------------------------------------------

Level::~Level() {
    // noop
}

// ---------------------------------------------------------------------------

void Level::init() {
    std::ifstream file(configPath);
    json mapInfo;
    file >> mapInfo;

    std::vector<int> matrix1;
    auto jsonMat = mapInfo["layers"][1]["data"];

    for(int n : jsonMat) {
        matrix1.push_back(n);
    }

    /*
    std::vector<int> matrix2;
    jsonMat = mapInfo["layers"][2]["data"];

    for(int n : jsonMat) {
        matrix2.push_back(n);
    }
    */

    spawnAll(matrix1, matrix1, static_cast<int>(mapInfo["width"]));
    // Game.loadBackground(mapInfo["backgroundPath"]); - TODO
}

// ---------------------------------------------------------------------------

void Level::spawnAll(std::vector<int>& mat1, std::vector<int>& mat2, int layerWidth) {
    spawnObstacles(mat1, layerWidth);
    spawnEnemies(mat2, layerWidth);
}

// ---------------------------------------------------------------------------

sf::Vector2f Level::getSpawnPosition(uint pos, int layerWidth) {
    const int x = pos % layerWidth;
    const int y = pos / layerWidth;
    return sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);
}

// ---------------------------------------------------------------------------

const char* Level::getConfigPath() {
    return configPath;
}
