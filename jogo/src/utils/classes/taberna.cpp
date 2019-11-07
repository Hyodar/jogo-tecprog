
#include "taberna.hpp"

#include "level_manager.hpp"
#include "entity_manager.hpp"

#include "entity.hpp"

#include <cstdlib>

#include <SFML/Graphics.hpp>

Taberna::Taberna() : Level{"resources/maps/map1.json"} {
    // noop
}

Taberna::~Taberna() {
    // noop
}

void Taberna::spawnObstacles(std::vector<int>& mat, int layerWidth) {
    for(int i = 0; i < mat.size(); i++) {
        if(!mat[i]) continue;

        sf::Vector2f pos = getSpawnPosition(i, layerWidth);

        int spikeNum = rand() % 5 + 5;
        int lavaNum = rand() % 5 + 5;
        int boxNum = rand() % 5 + 5;

        int spikeCount = 0;
        int lavaCount = 0;
        int boxCount = 0;

        switch(mat[i]) {
            case ObstacleClassification::SpikeObstacle:
                if(spikeCount < spikeNum) {
                    LevelManager::getInstance()->addObstacle(static_cast<Entity*>(new Spike(pos.x, pos.y)));
                    spikeCount++;
                }
                break;
            case ObstacleClassification::LavaObstacle:
                if(lavaCount < lavaNum) {
                    LevelManager::getInstance()->addObstacle(static_cast<Entity*>(new Lava(pos.x, pos.y)));
                    lavaCount++;
                }
                break;
            case ObstacleClassification::BoxObstacle:
                if(boxCount < boxNum) {
                    LevelManager::getInstance()->addObstacle(static_cast<Entity*>(new Box(pos.x, pos.y)));
                    boxCount++;
                }
                break;
            default:;
        }
    }
}

void Taberna::spawnEnemies(std::vector<int>& mat, int layerWidth) {
    // noop
}