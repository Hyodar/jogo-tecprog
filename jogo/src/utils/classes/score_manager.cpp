
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "score_manager.hpp"

// Standard libraries
// ---------------------

#include <iostream>
#include <sstream>
#include <string>

// Internal libraries
// ---------------------

#include "game.hpp"
#include "graphics_manager.hpp"
#include <constants.hpp>

using namespace bardadv::core;

// Attribute initialization
// ---------------------------------------------------------------------------

ScoreManager* ScoreManager::instance = nullptr;

// Methods
// ---------------------------------------------------------------------------
ScoreManager::ScoreManager() : score{0} {
    text.setFont(*(GraphicsManager::getInstance()->getScoreFont()));
    text.setFillColor(sf::Color::White);
    text.setPosition(75,50);
    text.setCharacterSize(40);
}

// ---------------------------------------------------------------------------

ScoreManager::~ScoreManager(){
    delete instance;
}

// ---------------------------------------------------------------------------


ScoreManager* ScoreManager::getInstance() {
    if(!instance) instance = new ScoreManager;
    return instance;
}

// ---------------------------------------------------------------------------

void ScoreManager::increasePoints(int p) {
    score += p;
}

// ---------------------------------------------------------------------------

void ScoreManager::process(){
    std::stringstream str;
    str << " score: " << score;

    text.setString(str.str());
    Game::getInstance()->getMainWindow().draw(text);
}

// ---------------------------------------------------------------------------

int ScoreManager::getScore(){
    return score;
}

// ---------------------------------------------------------------------------

void ScoreManager::setScore(int s){
    score = s;
}
