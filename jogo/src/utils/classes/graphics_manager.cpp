// Libraries
// ---------------------------------------------------------------------------

// Class header
// ---------------------

#include "graphics_manager.hpp"

// Internal libraries
// ---------------------

using namespace bardadv::core;

// Attribute initialization
// ---------------------------------------------------------------------------

GraphicsManager* GraphicsManager::instance = nullptr;

// Methods
// ---------------------------------------------------------------------------

GraphicsManager::GraphicsManager() {
    backgroundTexture.loadFromFile("resources/maps/background.png");
    bardoTexture.loadFromFile("resources/bardo.png");
    fielEscudeiroTexture.loadFromFile("resources/fiel_escudeiro.png");
    skeletonTexture.loadFromFile("resources/skeleton.png");
    mageTexture.loadFromFile("resources/mage.png");
    flyingMonsterTexture.loadFromFile("resources/flying_monster.png");
    dragonTexture.loadFromFile("resources/dragon.png");
    projectileTexture.loadFromFile("resources/projectiles.png");
    splashScreenTexture.loadFromFile("resources/splash_screen.png");
    rankingScreenTexture.loadFromFile("resources/ranking_screen.png");
    pauseMenuTexture.loadFromFile("resources/pause_menu.png");
    startMenuTexture.loadFromFile("resources/start_menu.png");
    gameOverMenuTexture.loadFromFile("resources/game_over_menu.png");
    tileSheetTexture.loadFromFile("resources/sheet.png");
    scoreFont.loadFromFile("resources/bilboregular.ttf");
    rankingFont.loadFromFile("resources/dungeon.ttf");
}

// ---------------------------------------------------------------------------

GraphicsManager::~GraphicsManager() {
    // noop

}

// ---------------------------------------------------------------------------

GraphicsManager* GraphicsManager::getInstance() {
    if(!instance) instance = new GraphicsManager;
    return instance;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getBackgroundTexture() {
    return &backgroundTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getBardoTexture() {
    return &bardoTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getFielEscudeiroTexture() {
    return &fielEscudeiroTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getSkeletonTexture() {
    return &skeletonTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getMageTexture() {
    return &mageTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getFlyingMonsterTexture() {
    return &flyingMonsterTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getDragonTexture() {
    return &dragonTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getProjectileTexture() {
    return &projectileTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getSplashScreenTexture() {
    return &splashScreenTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getRankingScreenTexture() {
    return &rankingScreenTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getPauseMenuTexture() {
    return &pauseMenuTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getStartMenuTexture() {
    return &startMenuTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getGameOverMenuTexture() {
    return &gameOverMenuTexture;
}

// ---------------------------------------------------------------------------

sf::Texture* GraphicsManager::getTileSheetTexture() {
    return &tileSheetTexture;
}

// ---------------------------------------------------------------------------

sf::Font* GraphicsManager::getScoreFont() {
    return &scoreFont;
}

// ---------------------------------------------------------------------------

sf::Font* GraphicsManager::getRankingFont(){
    return &rankingFont;
}
