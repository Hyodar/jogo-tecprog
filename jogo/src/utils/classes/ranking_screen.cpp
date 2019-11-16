
#include "ranking_screen.hpp"

#include <sstream>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "graphics_manager.hpp"
#include "game_saver.hpp"

RankingScreen::RankingScreen() : Ent(0, 0) {
    sprite.setTexture(*(GraphicsManager::getInstance()->getSplashScreenTexture()));
}

RankingScreen::~RankingScreen() {

}

void RankingScreen::render(sf::RenderWindow& window) {
    json scores = GameSaver::getInstance()->savePlayerScore();

    sf::Font* fontPtr = GraphicsManager::getInstance()->getScoreFont();

    window.draw(sprite);

    std::stringstream stream;
    stream << scores["player"] << ", ficou no lugar " << scores["place"] << " com " << scores["score"] << " pontos !";

    sf::Text placeText;
    placeText.setFont(*fontPtr);
    placeText.setString(stream.str());
    placeText.setCharacterSize(60);
    placeText.setFillColor(sf::Color::White);
    placeText.setPosition(200, 300);

    stream.str(std::string());

    for(uint i = 1; i <= scores["ranking"].size(); i++) {
        stream << i << " - " << scores["ranking"][i-1]["player"] << " | " << scores["ranking"][i-1]["score"] << "pontos \n";
    }

    sf::Text rankingBoard;
    rankingBoard.setFont(*fontPtr);
    rankingBoard.setString(stream.str());
    rankingBoard.setCharacterSize(50);
    rankingBoard.setFillColor(sf::Color::White);
    rankingBoard.setPosition(350, 400);

    window.draw(placeText);
    window.draw(rankingBoard);
}

void RankingScreen::show(sf::RenderWindow& window) {
    render(window);
    window.display();

    processLoop(window);
}

// ---------------------------------------------------------------------------

void RankingScreen::processLoop(sf::RenderWindow& window) {
    sf::Event event;

    while(true) {
        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::MouseButtonPressed:
                case sf::Event::Closed:
                    return;
                default:;
            }
        }
    }
}

