
#include <SFML/Graphics.hpp>

class GraphicsManager {

private:

    GraphicsManager();
    static GraphicsManager* instance;

    sf::Texture backgroundTexture;
    sf::Texture bardoTexture;
    sf::Texture fielEscudeiroTexture;
    sf::Texture skeletonTexture;
    sf::Texture dragonTexture;
    sf::Texture projectileTexture;
    sf::Texture splashScreenTexture;
    sf::Texture pauseMenuTexture;
    sf::Texture startMenuTexture;
    sf::Texture gameOverMenuTexture;
    sf::Texture tileSheetTexture;
    sf::Font scorefont;

public:

    static GraphicsManager* getInstance();
    ~GraphicsManager();

    sf::Texture* getBackgroundTexture();
    sf::Texture* getBardoTexture();
    sf::Texture* getFielEscudeiroTexture();
    sf::Texture* getSkeletonTexture();
    sf::Texture* getDragonTexture();
    sf::Texture* getProjectileTexture();
    sf::Texture* getSplashScreenTexture();
    sf::Texture* getPauseMenuTexture();
    sf::Texture* getStartMenuTexture();
    sf::Texture* getGameOverMenuTexture();
    sf::Texture* getTileSheetTexture();
    sf::Font* getScoreFont(); 

};
