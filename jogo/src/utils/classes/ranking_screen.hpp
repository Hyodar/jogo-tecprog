
#ifndef RANKING_SCREEN_HPP_
#define RANKING_SCREEN_HPP_

#include <SFML/Graphics.hpp>

#include "ent.hpp"

namespace bardadv::menus {

class RankingScreen : public bardadv::core::Ent {

private:
    sf::Sprite sprite;

    void processLoop(sf::RenderWindow& window);

public:
    RankingScreen();
    ~RankingScreen();

    void render(sf::RenderWindow& window);
    void show(sf::RenderWindow& window);

};

}

#endif // RANKING_SCREEN_HPP_