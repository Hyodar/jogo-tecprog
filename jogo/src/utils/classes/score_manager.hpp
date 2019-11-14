#ifndef SCORE_MANAGER_HPP_
#define SCORE_MANAGER_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class ScoreManager {

public:
    ~ScoreManager();
    static ScoreManager* getInstance();

    void process(sf::RenderWindow& window);

private:
    ScoreManager();
    static ScoreManager* instance;
    int score;

};

#endif //SCORE_MANAGER_HPP
