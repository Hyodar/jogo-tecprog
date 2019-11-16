
#ifndef GAME_SAVER_HPP_
#define GAME_SAVER_HPP_

#include <fstream>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class GameSaver {

private:
    GameSaver();
    static GameSaver* instance;

public:
    ~GameSaver();
    static GameSaver* getInstance();

    void saveState();
    bool recoverState();
    json savePlayerScore();

};

#endif // GAME_SAVER_HPP_