
// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "score_manager.hpp"
#include "graphics_manager.hpp"

// Standard libraries
// ---------------------

#include <iostream>

// Internal libraries
// ---------------------

// Attribute initialization
// ---------------------------------------------------------------------------

ScoreManager* ScoreManager::instance = nullptr;

// Methods
// ---------------------------------------------------------------------------
ScoreManager::ScoreManager(){
    score = 0;
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

void ScoreManager::process(sf::RenderWindow& window){
    sf::Text text;
    text.setString("asdasdasdasdadsads");
    text.setFont(*(GraphicsManager::getInstance()->getScoreFont()));
    //text.setString("Hello world");
    text.setFillColor(sf::Color::Red);
    //text.setFont(sf::Font::getDefaultFont());
    //text.setFont(*(GraphicsManager::getInstance()->getScoreFont()));
    text.setPosition(400,200);
    text.setCharacterSize(40);
    window.draw(text);
}
