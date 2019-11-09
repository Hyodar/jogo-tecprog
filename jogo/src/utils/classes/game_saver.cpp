
#include "game_saver.hpp"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "level_manager.hpp"
#include "spike.hpp"
#include "lava.hpp"
#include "box.hpp"
#include "game.hpp"
#include "entity.hpp"
#include "character.hpp"
#include "bardo.hpp"

void GameSaver::saveState() {

    json j; // "data/save.json"

    j["phase"] = LevelManager::getInstance()->getCurrentLevel();
    j["score"] = Game::getInstance()->getScore();

    //const Bardo& b = Game::getInstance()->getPlayer();

    // j["bardo"] = { b.getPosX(), b.getPosY(), b.getHP() };
    // //j["fielescudeiro"] = { f.getPosX(), f.getPosY(), f.getHP() };
    // // TODO - player 2

    auto obstacles = json::array();
    for(Obstacle* e : LevelManager::getInstance()->getObstacles()) {
       obstacles.push_back(e->store());
    }

    j["obstacles"] = obstacles;

    // auto enemies = json::array();
    // for(Character* c : LevelManager::getInstance()->getEnemies()) {
    //     enemies.push_back({ /*e->enemyNum,*/ c->getPosX(), c->getPosY(), c->getHP() });
    // }

    // j["enemies"] = enemies;

}

bool GameSaver::recoverState() {
    // TODO

    return false;
}