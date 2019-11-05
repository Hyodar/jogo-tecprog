
#include "level.hpp"

#include <fstream>

// External libraries
#include <nlohmann/json.hpp>
using json = nlohmann::json;

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

    spawnAll(matrix, static_cast<int>(mapInfo["height"]));
    // Game.loadBackground(mapInfo["backgroundPath"]); - TODO
}

void Level::spawnAll(std::vector<int>& mat, int layerHeight) {
    spawnEnemies(mat, layerHeight);
    spawnObstacles(mat, layerHeight);
}
