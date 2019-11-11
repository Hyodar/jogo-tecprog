
#include "graphics_manager.hpp"

GraphicsManager* GraphicsManager::instance = nullptr;

GraphicsManager::GraphicsManager() {
    backgroundTexture.loadFromFile("resources/maps/background.png");
    bardoTexture.loadFromFile("resources/bardo.png");
    fielEscudeiroTexture.loadFromFile("resources/fiel_escudeiro.png");
    skeletonTexture.loadFromFile("resources/skeleton.png");
    dragonTexture.loadFromFile("resources/dragon.png");
    projectileTexture.loadFromFile("resources/projectiles.png");
    splashScreenTexture.loadFromFile("resources/splash_screen.png");
    pauseMenuTexture.loadFromFile("resources/pause_menu.png");
    startMenuTexture.loadFromFile("resources/start_menu.png");
    tileSheetTexture.loadFromFile("resources/sheet.png");
}

GraphicsManager::~GraphicsManager() {
    // noop
}

GraphicsManager* GraphicsManager::getInstance() {
    if(!instance) instance = new GraphicsManager;
    return instance;
}

sf::Texture* GraphicsManager::getBackgroundTexture() {
    return &backgroundTexture;
}

sf::Texture* GraphicsManager::getBardoTexture() {
    return &bardoTexture;
}

sf::Texture* GraphicsManager::getFielEscudeiroTexture() {
    return &fielEscudeiroTexture;
}

sf::Texture* GraphicsManager::getSkeletonTexture() {
    return &skeletonTexture;
}

sf::Texture* GraphicsManager::getDragonTexture() {
    return &dragonTexture;
}

sf::Texture* GraphicsManager::getProjectileTexture() {
    return &projectileTexture;
}

sf::Texture* GraphicsManager::getSplashScreenTexture() {
    return &splashScreenTexture;
}

sf::Texture* GraphicsManager::getPauseMenuTexture() {
    return &pauseMenuTexture;
}

sf::Texture* GraphicsManager::getStartMenuTexture() {
    return &startMenuTexture;
}

sf::Texture* GraphicsManager::getTileSheetTexture() {
    return &tileSheetTexture;
}
