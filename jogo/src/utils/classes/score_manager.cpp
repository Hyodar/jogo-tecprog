
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "score_manager.hpp"
#include "graphics_manager.hpp"

// Standard libraries
// ---------------------

#include <iostream>
#include <sstream>
#include <string.h>

// Internal libraries
// ---------------------

// Attribute initialization
// ---------------------------------------------------------------------------

ScoreManager* ScoreManager::instance = nullptr;

// Methods
// ---------------------------------------------------------------------------
ScoreManager::ScoreManager(){
    score = 0;
    text.setFont(*(GraphicsManager::getInstance()->getScoreFont()));
    text.setFillColor(sf::Color::White);
    text.setPosition(75,50);
    text.setCharacterSize(40);
}

// ---------------------------------------------------------------------------

ScoreManager::~ScoreManager(){
    //noop
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

void ScoreManager::process(sf::RenderWindow& window){

    std::stringstream str;
    str << " score: " << score;
    std::string s = str.str();

    text.setString(s);
    window.draw(text);
}
