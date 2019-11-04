
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
    std::ifstream file("resources/maps/map1.json");
    json mapInfo;
    file >> mapInfo;

    spawnAll(mapInfo["layers"][1]["data"]);
    // Game.loadBackground(mapInfo["backgroundPath"]); - TODO
}

void Level::spawnAll(std::vector<int> mat, int layerHeight) {
    spawnEnemies(mat, layerHeight);
    spawnObstacles(mat, layerHeight);
}
