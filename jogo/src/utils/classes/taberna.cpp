
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
#include "box.hpp"
#include "skeleton.hpp"
#include "mage.hpp"
#include "energy_ball.hpp"
#include "level_manager.hpp"
#include "game.hpp"

using namespace bardadv::core;
using namespace bardadv::obstacles;
using namespace bardadv::projectiles;
using namespace bardadv::characters;
using namespace bardadv::levels;

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
    const uint boxNum = rand() % 5 + 5;

    std::vector<sf::Vector2f> spikes;
    std::vector<sf::Vector2f> boxes;

    for(uint i = 0; i < mat.size(); i++) {
        if(!mat[i]) continue;

        sf::Vector2f pos = getSpawnPosition(i, layerWidth);

        switch(mat[i]) {
            case ObstacleClassification::SPIKE:
                spikes.push_back(pos);
                break;
            case ObstacleClassification::BOX:
                boxes.push_back(pos);
                break;
            default:;
        }
    }

    std::random_shuffle(spikes.begin(), spikes.end());
    std::random_shuffle(boxes.begin(), boxes.end());

    const uint maxSpikes = (spikes.size() > spikeNum)? spikeNum : spikes.size();
    const uint maxBoxes = (boxes.size() > boxNum)? boxNum : boxes.size();

    for(uint i = 0; i < maxSpikes; i++) LevelManager::getInstance()->addObstacle(static_cast<Obstacle*>(new Spike(spikes[i].x, spikes[i].y)));
    for(uint i = 0; i < maxBoxes; i++) LevelManager::getInstance()->addObstacle(static_cast<Obstacle*>(new Box(boxes[i].x, boxes[i].y)));
}

// ---------------------------------------------------------------------------

void Taberna::spawnEnemies(std::vector<int>& mat, int layerWidth) {
    const uint skeletonNum = rand() % 5 + 5;
    const uint mageNum = rand() % 5 + 5;

    std::vector<sf::Vector2f> skeletons;
    std::vector<sf::Vector2f> mages;

    for(uint i = 0; i < mat.size(); i++) {
        if(!mat[i]) continue;

        sf::Vector2f pos = getSpawnPosition(i, layerWidth);

        switch(mat[i]) {
            case CharacterClassification::SKELETON:
                skeletons.push_back(pos);
                break;
            case CharacterClassification::MAGE:
                mages.push_back(pos);
                break;
            default:;
        }
    }

    std::random_shuffle(skeletons.begin(), skeletons.end());
    std::random_shuffle(mages.begin(), mages.end());

    const uint maxSkeletons = (skeletons.size() > skeletonNum)? skeletonNum : skeletons.size();
    const uint maxMages = (mages.size() > mageNum)? mageNum : mages.size();

    for(uint i = 0; i < maxSkeletons; i++) LevelManager::getInstance()->addEnemy(static_cast<Enemy*>(new Skeleton(skeletons[i].x, skeletons[i].y, &(Game::getInstance()->getPlayer()))));
    for(uint i = 0; i < maxMages; i++) LevelManager::getInstance()->addEnemy(static_cast<Enemy*>(new Mage(mages[i].x, mages[i].y, &(Game::getInstance()->getPlayer()))));
}

// ---------------------------------------------------------------------------

void Taberna::recoverLevel(json data) {
    LevelManager* levelMng = LevelManager::getInstance();

    for(auto obj : data["entities"]) {
        switch((int) obj["classification"]) {
            case CharacterClassification::SKELETON: {
                Bardo* player = dynamic_cast<Bardo*>(levelMng->getEntityManager().getEntityById(obj["playerId"]));
                Skeleton* s = new Skeleton(obj["id"], obj["hp"], obj["posX"], obj["posY"], player);

                levelMng->addEnemy(static_cast<Enemy*>(s));
            } break;
            case CharacterClassification::MAGE: {
                Bardo* player = dynamic_cast<Bardo*>(levelMng->getEntityManager().getEntityById(obj["playerId"]));
                Mage* m = new Mage(obj["id"], obj["hp"], obj["posX"], obj["posY"], player);

                levelMng->addEnemy(static_cast<Enemy*>(m));
            } break;
            case ObstacleClassification::SPIKE: {
                Spike* s = new Spike(obj["posX"], obj["posY"]);
                s->setId(obj["id"]);

                levelMng->addObstacle(static_cast<Obstacle*>(s));
            } break;
            case ObstacleClassification::BOX: {
                Box* b = new Box(obj["posX"], obj["posY"]);
                b->setId(obj["id"]);

                levelMng->addObstacle(static_cast<Obstacle*>(b));
            } break;
            case ProjectileClassification::ENERGY_BALL: {
                EnergyBall* e = new EnergyBall(obj["posX"], obj["posY"], obj["speedX"], obj["speedY"]);
                e->setId(obj["id"]);
                e->setAlreadySplited(true);

                levelMng->addProjectile(static_cast<Projectile*>(e));
            } break;
        }
    }
}
