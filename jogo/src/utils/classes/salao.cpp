

// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "salao.hpp"

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
#include "game.hpp"
#include "dragon.hpp"
#include "fireball.hpp"
#include "mage.hpp"
#include "flying_monster.hpp"
#include "level_manager.hpp"

using namespace bardadv::core;
using namespace bardadv::levels;
using namespace bardadv::obstacles;
using namespace bardadv::projectiles;
using namespace bardadv::characters;

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
    const uint spikeNum = rand() % 5 + 5;
    const uint lavaNum = rand() % 5 + 5;

    std::vector<sf::Vector2f> spikes;
    std::vector<sf::Vector2f> lavas;

    for(uint i = 0; i < mat.size(); i++) {
        if(!mat[i]) continue;

        sf::Vector2f pos = getSpawnPosition(i, layerWidth);

        switch(mat[i]) {
            case ObstacleClassification::SPIKE:
                spikes.push_back(pos);
                break;
            case ObstacleClassification::LAVA:
                lavas.push_back(pos);
                break;
            default:;
        }
    }

    std::random_shuffle(spikes.begin(), spikes.end());
    std::random_shuffle(lavas.begin(), lavas.end());

    const uint maxSpikes = (spikes.size() > spikeNum)? spikeNum : spikes.size();
    const uint maxLavas = (lavas.size() > lavaNum)? lavaNum : lavas.size();

    for(uint i = 0; i < maxSpikes; i++) LevelManager::getInstance()->addObstacle(static_cast<Obstacle*>(new Spike(spikes[i].x, spikes[i].y)));
    for(uint i = 0; i < maxLavas; i++) LevelManager::getInstance()->addObstacle(static_cast<Obstacle*>(new Lava(lavas[i].x, lavas[i].y)));
}

// ---------------------------------------------------------------------------

void Salao::spawnEnemies(std::vector<int>& mat, int layerWidth) {

    const uint fmNum = rand() % 5 + 5;
    const uint mageNum = rand() % 5 + 5;

    std::vector<sf::Vector2f> fms;
    std::vector<sf::Vector2f> mages;

    for(uint i = 0; i < mat.size(); i++) {
        if(!mat[i]) continue;

        sf::Vector2f pos = getSpawnPosition(i, layerWidth);

        switch(mat[i]) {
            case CharacterClassification::FLYING_MONSTER:
                fms.push_back(pos);
                break;
            case CharacterClassification::MAGE:
                mages.push_back(pos);
                break;
            case CharacterClassification::DRAGON:
                LevelManager::getInstance()->addEnemy(static_cast<Enemy*>(new Dragon(pos.x, pos.y, &(Game::getInstance()->getPlayer()))));
                break;
            default:;
        }
    }

    std::random_shuffle(fms.begin(), fms.end());
    std::random_shuffle(mages.begin(), mages.end());

    const uint maxSkeletons = (fms.size() > fmNum)? fmNum : fms.size();
    const uint maxMages = (mages.size() > mageNum)? mageNum : mages.size();

    for(uint i = 0; i < maxSkeletons; i++) LevelManager::getInstance()->addEnemy(static_cast<Enemy*>(new FlyingMonster(fms[i].x, fms[i].y, &(Game::getInstance()->getPlayer()))));
    for(uint i = 0; i < maxMages; i++) LevelManager::getInstance()->addEnemy(static_cast<Enemy*>(new Mage(mages[i].x, mages[i].y, &(Game::getInstance()->getPlayer()))));
}

void Salao::recoverLevel(json data) {
    LevelManager* levelMng = LevelManager::getInstance();

    for(auto obj : data["entities"]) {
        switch((int) obj["classification"]) {
            case CharacterClassification::MAGE: {
                Bardo* player = dynamic_cast<Bardo*>(levelMng->getEntityManager().getEntityById(obj["playerId"]));
                Mage* m = new Mage(obj["id"], obj["hp"], obj["posX"], obj["posY"], player);

                levelMng->addEnemy(static_cast<Enemy*>(m));
            } break;
            case CharacterClassification::FLYING_MONSTER: {
                Bardo* player = dynamic_cast<Bardo*>(levelMng->getEntityManager().getEntityById(obj["playerId"]));
                FlyingMonster* fm = new FlyingMonster(obj["id"], obj["hp"], obj["timeCounter"], obj["startingPosX"], obj["startingPosY"], player);

                levelMng->addEnemy(static_cast<Enemy*>(fm));
            } break;
            case CharacterClassification::DRAGON: {
                Bardo* player = dynamic_cast<Bardo*>(levelMng->getEntityManager().getEntityById(obj["playerId"]));
                Dragon* d = new Dragon(obj["id"], obj["hp"], obj["posX"], obj["posY"], player);

                levelMng->addEnemy(static_cast<Enemy*>(d));
            } break;
            case ObstacleClassification::SPIKE: {
                Spike* s = new Spike(obj["posX"], obj["posY"]);
                s->setId(obj["id"]);

                levelMng->addObstacle(static_cast<Obstacle*>(s));
            } break;
            case ObstacleClassification::LAVA: {
                Lava* l = new Lava(obj["posX"], obj["posY"]);
                l->setId(obj["id"]);

                levelMng->addObstacle(static_cast<Obstacle*>(l));
            } break;
            case ProjectileClassification::FIREBALL: {
                Fireball* f = new Fireball(obj["posX"], obj["posY"], obj["speedX"], obj["speedY"]);
                f->setId(obj["id"]);

                levelMng->addProjectile(static_cast<Projectile*>(f));
            } break;
        }
    }
}
