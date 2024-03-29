#ifndef GRAPHICSMANAGER_HPP_
#define GRAPHICSMANAGER_HPP_

#include <SFML/Graphics.hpp>

namespace bardadv::core {

class GraphicsManager {

private:
    GraphicsManager();
    static GraphicsManager* instance;

    sf::Texture backgroundTexture;
    sf::Texture bardoTexture;
    sf::Texture fielEscudeiroTexture;
    sf::Texture skeletonTexture;
    sf::Texture mageTexture;
    sf::Texture flyingMonsterTexture;
    sf::Texture dragonTexture;
    sf::Texture projectileTexture;
    sf::Texture splashScreenTexture;
    sf::Texture rankingScreenTexture;
    sf::Texture pauseMenuTexture;
    sf::Texture startMenuTexture;
    sf::Texture gameOverMenuTexture;
    sf::Texture tileSheetTexture;

    sf::Font scoreFont;
    sf::Font rankingFont;

public:

    static GraphicsManager* getInstance();
    ~GraphicsManager();

    sf::Texture* getBackgroundTexture();
    sf::Texture* getBardoTexture();
    sf::Texture* getFielEscudeiroTexture();
    sf::Texture* getSkeletonTexture();
    sf::Texture* getMageTexture();
    sf::Texture* getFlyingMonsterTexture();
    sf::Texture* getDragonTexture();
    sf::Texture* getProjectileTexture();
    sf::Texture* getSplashScreenTexture();
    sf::Texture* getRankingScreenTexture();
    sf::Texture* getPauseMenuTexture();
    sf::Texture* getStartMenuTexture();
    sf::Texture* getGameOverMenuTexture();
    sf::Texture* getTileSheetTexture();
    sf::Font* getScoreFont();
    sf::Font* getRankingFont();

};

}

#endif // GRAPHICSMANAGER_HPP_
