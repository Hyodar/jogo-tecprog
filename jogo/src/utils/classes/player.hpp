
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player {

protected:
    sf::Vector2i size;
    sf::Vector2f position;
    sf::Vector2f speed;

    static sf::Texture texture;
    sf::Sprite sprite;

public:
    Player(int x=0, int y=0);
    
    void update(const float deltaTime);
    void render(sf::RenderWindow& window);
    void jump();

    sf::Vector2f getPosition() { return position; }

};
