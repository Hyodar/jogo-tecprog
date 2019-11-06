
#include "taberna.hpp"

#include "level_manager.hpp"
#include "entity_manager.hpp"
#include "spike.hpp"
#include "lava.hpp"
#include "box.hpp"

#include "entity.hpp"

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

        switch(mat[i]) {
            case ObstacleClassification::Spikes:
                LevelManager::getInstance()->addEntity(static_cast<Entity*>(new Spike(pos.x, pos.y)));
                break;
            /*
            case ObstacleClassification::Lava:
                LevelManager::getInstance()->addEntity(static_cast<Entity*>(new Lava(pos.x, pos.y)));
                break;
            case ObstacleClassification::Box:
                LevelManager::getInstance()->addEntity(static_cast<Entity*>(new Box(pos.x, pos.y)));
                break;
            */
            default:;
        }
    }
}

void Taberna::spawnEnemies(std::vector<int>& mat, int layerWidth) {
    // noop
}