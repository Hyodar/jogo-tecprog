
#ifndef SCORE_MANAGER_HPP_
#define SCORE_MANAGER_HPP_

#include <SFML/Graphics.hpp>

namespace bardadv::core {

class ScoreManager {

public:
    ~ScoreManager();
    static ScoreManager* getInstance();

    void increasePoints(int p);
    void process();

    int getScore();
    void setScore(int s);

private:
    ScoreManager();
    static ScoreManager* instance;
    int score;
    sf::Text text;

};

}

#endif //SCORE_MANAGER_HPP
