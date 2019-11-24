// Libraries
// ---------------------------------------------------------------------------

#include <sstream>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Class header
// ---------------------

#include "ranking_screen.hpp"

// Internal libraries
// ---------------------

#include "graphics_manager.hpp"
#include "game_saver.hpp"

#include <game_config.hpp>

using namespace bardadv::core;
using namespace bardadv::menus;
using namespace bardadv::persistence;

// Attribute initialization
// ---------------------------------------------------------------------------

// Methods
// ---------------------------------------------------------------------------

RankingScreen::RankingScreen() : Ent(0, 0) {
    sprite.setTexture(*(GraphicsManager::getInstance()->getRankingScreenTexture()));
}

// ---------------------------------------------------------------------------

RankingScreen::~RankingScreen() {

}

// ---------------------------------------------------------------------------

void RankingScreen::render(sf::RenderWindow& window) {
    json scores = GameSaver::getInstance()->savePlayerScore();

    sf::Font* fontPtr = GraphicsManager::getInstance()->getRankingFont();

    window.draw(sprite);

    std::stringstream stream;
    stream << scores["player"] << ": lugar " << scores["place"] << " com " << scores["score"] << " pontos !";

    sf::Text placeText;
    placeText.setFont(*fontPtr);
    placeText.setString(stream.str());
    placeText.setCharacterSize(60);
    placeText.setStyle(sf::Text::Bold);
    placeText.setFillColor(sf::Color::White);

    sf::FloatRect textRect = placeText.getLocalBounds();
    placeText.setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
    placeText.setPosition(sf::Vector2f(WINDOW_W/2.0f, WINDOW_H/4.0f + 50));

    stream.str(std::string());

    for(uint i = 1; i <= scores["ranking"].size(); i++) {
        stream << i << " - " << scores["ranking"][i-1]["player"] << " | " << scores["ranking"][i-1]["score"] << " pontos \n";
    }

    sf::Text rankingBoard;
    rankingBoard.setFont(*fontPtr);
    rankingBoard.setString(stream.str());
    rankingBoard.setCharacterSize(50);
    rankingBoard.setStyle(sf::Text::Bold);
    rankingBoard.setFillColor(sf::Color::White);

    textRect = rankingBoard.getLocalBounds();
    rankingBoard.setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
    rankingBoard.setPosition(sf::Vector2f(WINDOW_W/2.0f, 100 + WINDOW_H/2.0f));

    window.draw(placeText);
    window.draw(rankingBoard);
}

// ---------------------------------------------------------------------------

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
