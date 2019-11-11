

// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "salao.hpp"

// Standard libraries
// ---------------------

#include <cstdlib>

// External libraries
// ---------------------

#include <SFML/Graphics.hpp>

// Internal libraries
// ---------------------

#include "spike.hpp"
#include "lava.hpp"
#include "box.hpp"
#include "game.hpp"
#include "dragon.hpp"
#include "level_manager.hpp"

// Methods
// ---------------------------------------------------------------------------

Salao::Salao() : Level{"resources/maps/map2.json"} {
    // noop
}

// ---------------------------------------------------------------------------

Salao::~Salao() {
    // noop
}

// ---------------------------------------------------------------------------

void Salao::spawnObstacles(std::vector<int>& mat, int layerWidth) {
    for(uint i = 0; i < mat.size(); i++) {
        if(!mat[i]) continue;

        sf::Vector2f pos = getSpawnPosition(i, layerWidth);

        int spikeNum = rand()%5 + 5;
        int lavaNum = rand()%5 + 5;
        int boxNum = rand()%5 + 5;

        int spikeCount = 0;
        int lavaCount = 0;
        int boxCount = 0;

        switch(mat[i]) {
            case ObstacleClassification::SpikeObstacle:
                if(spikeCount < spikeNum) {
                    LevelManager::getInstance()->addObstacle(static_cast<Obstacle*>(new Spike(pos.x, pos.y)));
                    spikeCount++;
                }
                break;
            case ObstacleClassification::LavaObstacle:
                if(lavaCount < lavaNum) {
                    LevelManager::getInstance()->addObstacle(static_cast<Obstacle*>(new Lava(pos.x, pos.y)));
                    lavaCount++;
                }
                break;
            case ObstacleClassification::BoxObstacle:
                if(boxCount < boxNum) {
                    LevelManager::getInstance()->addObstacle(static_cast<Obstacle*>(new Box(pos.x, pos.y)));
                    boxCount++;
                }
                break;
            default:;
        }
    }
}

// ---------------------------------------------------------------------------

void Salao::spawnEnemies(std::vector<int>& mat, int layerWidth) {
    LevelManager::getInstance()->addEnemy(static_cast<Enemy*>(new Dragon(400, 200, &(Game::getInstance()->getPlayer()))));
}
