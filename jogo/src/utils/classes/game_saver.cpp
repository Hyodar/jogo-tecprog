
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "game_saver.hpp"

// Standard libraries
// ---------------------

#include <string>
#include <iomanip>
#include <iostream>
#include <ios>

// Internal libraries
// ---------------------

#include "game.hpp"
#include "level_manager.hpp"
#include "score_manager.hpp"

#include "bardo.hpp"
#include "fiel_escudeiro.hpp"
#include "skeleton.hpp"
#include "mage.hpp"
#include "flying_monster.hpp"
#include "dragon.hpp"
#include "spike.hpp"
#include "lava.hpp"
#include "box.hpp"
#include "fireball.hpp"
#include "energy_ball.hpp"

#include "obstacle.hpp"
#include "enemy.hpp"
#include "projectile.hpp"

#include <game_config.hpp>

using namespace bardadv::core;
using namespace bardadv::persistence;
using namespace bardadv::characters;
using namespace bardadv::projectiles;
using namespace bardadv::obstacles;

// Attribute initialization
// ---------------------------------------------------------------------------

GameSaver* GameSaver::instance = nullptr;

// Methods
// ---------------------------------------------------------------------------

GameSaver::GameSaver() {
    // noop
}

GameSaver::~GameSaver() {
    delete instance;
}

GameSaver* GameSaver::getInstance() {
    if(!instance) instance = new GameSaver();
    return instance;
}

void GameSaver::saveState() {

    std::ofstream out("data/save.json", std::ios::out | std::ios::trunc);
    out.exceptions(std::ios::badbit);

    try {
        out << std::setw(4) << Game::getInstance()->store() << std::endl;
    }
    catch(std::ifstream::failure e) {
        std::cerr << "[!] Error writing to 'data/save.json'!";
    }

    out.close();
}

// ---------------------------------------------------------------------------

bool GameSaver::recoverState() {

    std::ifstream in("data/save.json");

    // Testa se o arquivo existe
    if(!in.good()) return false;

    // Testa se o arquivo ta vazio
    in.seekg(0, std::ios::end);
    if(!in.tellg()) return false;
    in.seekg(0, std::ios::beg);

    json j;

    try {
        in >> j;
    }
    catch(json::exception& e) {
        std::cerr << "[!] Erro na leitura do arquivo de save. Iniciando jogo na fase 1 e com 1 jogador..." << std::endl;
        std::cerr << e.what() << std::endl;
        in.close();
        return false;
    }

    LevelManager::getInstance()->cleanLevel();

    Game* game = Game::getInstance();
    ScoreManager* scoreMng = ScoreManager::getInstance();
    LevelManager* levelMng = LevelManager::getInstance();

    int phase = j["phase"];
    game->setGamePhase(phase);

    int score = j["score"];
    scoreMng->setScore(score);

    std::string name = j["name"];
    game->setPlayerName(name);

    for(auto obj : j["entities"]) {
        switch((int) obj["classification"]) {
            case CharacterClassification::BARDO: {
                Bardo& bardo = game->getPlayer();
                bardo.setPosX(obj["posX"]);
                bardo.setPosY(obj["posY"]);
                bardo.setHP(obj["hp"]);
                bardo.setId(obj["id"]);

            } break;
            case CharacterClassification::FIEL_ESCUDEIRO: {
                FielEscudeiro& f = game->getFielEscudeiro();
                f.setPosX(obj["posX"]);
                f.setPosY(obj["posY"]);
                f.setHP(obj["hp"]);
                f.setId(obj["id"]);
                game->setHasEscudeiro(true);
                levelMng->getEntityManager().setFielEscudeiro(&f);

            } break;
        }
    }

    levelMng->recoverLevel(phase, j);

    in.close();

    return true;
}

// ---------------------------------------------------------------------------

json GameSaver::savePlayerScore() {
    int score = ScoreManager::getInstance()->getScore();
    std::string name = Game::getInstance()->getPlayerName();

    std::ifstream in("data/ranking.json");

    // Testa se o arquivo existe
    if(!in.good()) {
        throw "[!] Ranking file doesn't exist.";
    }

    // Testa se o arquivo ta vazio
    in.seekg(0, std::ios::end);
    if(!in.tellg()) {
        throw "[!] Ranking file is empty.";
    }
    in.seekg(0, std::ios::beg);

    json j;

    try {
        in >> j;
    }
    catch(json::exception& e) {
        std::cerr << "[!] Erro na leitura do arquivo de ranking." << std::endl;
        std::cerr << e.what() << std::endl;
        in.close();
    }

    json rank;
    rank["player"] = name;
    rank["score"] = score;
    uint place = 1;

    if(j.find("players") == j.end()) {
        j["players"].push_back(rank);
    }
    else {
        for(auto it = j["players"].begin(); it != j["players"].end(); it++) {

            if((*it)["score"] <= score) {
                j["players"].insert(it, rank);
                break;
            }
            place++;
        }

        if(place == j["players"].size()) j["players"].insert(j["players"].end() - 1, rank);
    }

    in.close();

    rank["place"] = place;

    const uint posMax = (j["players"].size() > 5)? 5 : j["players"].size();
    for(uint i = 0; i < posMax; i++) rank["ranking"].push_back(j["players"][i]);

    std::ofstream out("data/ranking.json", std::ios::out | std::ios::trunc);
    out.exceptions(std::ios::badbit);

    try {
        out << std::setw(4) << j << std::endl;
    }
    catch(std::ifstream::failure e) {
        std::cerr << "[!] Error writing to 'data/save.json'!";
    }

    out.close();

    return rank;
}
