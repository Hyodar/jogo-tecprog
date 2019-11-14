
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "taberna.hpp"

// Standard libraries
// ---------------------

#include <cstdlib>
#include <vector>
#include <random>

// External libraries
// ---------------------

#include <SFML/Graphics.hpp>

// Internal libraries
// ---------------------

#include "spike.hpp"
#include "lava.hpp"
#include "box.hpp"
#include "skeleton.hpp"
#include "level_manager.hpp"
#include "game.hpp"

// Methods
// ---------------------------------------------------------------------------

Taberna::Taberna() : Level{"resources/maps/map1.json"} {
    // noop
}

// ---------------------------------------------------------------------------

Taberna::~Taberna() {
    // noop
}

// ---------------------------------------------------------------------------

void Taberna::spawnObstacles(std::vector<int>& mat, int layerWidth) {
    const uint spikeNum = rand() % 5 + 5;
    const uint lavaNum = rand() % 5 + 5;
    const uint boxNum = rand() % 5 + 5;

    std::vector<sf::Vector2f> spikes;
    std::vector<sf::Vector2f> lavas;
    std::vector<sf::Vector2f> boxes;

    for(uint i = 0; i < mat.size(); i++) {
        if(!mat[i]) continue;

        sf::Vector2f pos = getSpawnPosition(i, layerWidth);

        switch(mat[i]) {
            case ObstacleClassification::SpikeObstacle:
                spikes.push_back(pos);
                break;
            case ObstacleClassification::LavaObstacle:
                lavas.push_back(pos);
                break;
            case ObstacleClassification::BoxObstacle:
                boxes.push_back(pos);
                break;
            default:;
        }
    }

    std::random_shuffle(spikes.begin(), spikes.end());
    std::random_shuffle(lavas.begin(), lavas.end());
    std::random_shuffle(boxes.begin(), boxes.end());

    const uint maxSpikes = (spikes.size() > spikeNum)? spikeNum : spikes.size();
    const uint maxLavas = (lavas.size() > lavaNum)? lavaNum : lavas.size();
    const uint maxBoxes = (boxes.size() > boxNum)? boxNum : boxes.size();

    for(uint i = 0; i < maxSpikes; i++) LevelManager::getInstance()->addObstacle(static_cast<Obstacle*>(new Spike(spikes[i].x, spikes[i].y)));
    for(uint i = 0; i < maxLavas; i++) LevelManager::getInstance()->addObstacle(static_cast<Obstacle*>(new Lava(lavas[i].x, lavas[i].y)));
    for(uint i = 0; i < maxBoxes; i++) LevelManager::getInstance()->addObstacle(static_cast<Obstacle*>(new Box(boxes[i].x, boxes[i].y)));
}

// ---------------------------------------------------------------------------

void Taberna::spawnEnemies(std::vector<int>& mat, int layerWidth) {
    int skeletonNum = rand() % 5 + 5;
    int mageNum = rand() % 5 + 5;

    int skeletonCount = 0;
    int mageCount = 0;

    for(uint i = 0; i < mat.size(); i++) {
        if(!mat[i]) continue;

        sf::Vector2f pos = getSpawnPosition(i, layerWidth);

        switch(mat[i]) {
            case CharacterClassification::SKELETON:
                if(skeletonCount < skeletonNum) {
                    LevelManager::getInstance()->addEnemy(static_cast<Enemy*>(new Skeleton(pos.x, pos.y, &(Game::getInstance()->getPlayer()))));
                    skeletonCount++;
                }
                break;
            default:;
        }
    }
}
