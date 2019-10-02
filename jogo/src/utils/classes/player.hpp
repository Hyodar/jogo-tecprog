
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "point.hpp"

class Player {

protected:
    sf::Vector2f position;
    sf::Vector2f speed;
    sf::Sprite sprite;

public:
    Player(int x=0, int y=0);
    
    void update(const float deltaTime);
    void render(sf::RenderWindow& window);

};
