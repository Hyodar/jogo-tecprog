
#ifndef GAME_SAVER_HPP_
#define GAME_SAVER_HPP_

class GameSaver {

private:
    GameSaver();
    static GameSaver* instance;

public:
    ~GameSaver();
    static GameSaver* getInstance();

    void saveState();
    bool recoverState();

};

#endif // GAME_SAVER_HPP_