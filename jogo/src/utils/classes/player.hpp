
#include <SFML/Window.hpp>
#include <SFML/Vector2.hpp>
#include "point.hpp"

class Player {

protected:
    sf::Vector2i position;
    sf::Vector2i speed;

public:
    Player() : position(), speed(6, 0) {}
    Player(int x, int y) : position(x, y), speed(6, 0) {}
    
    void move(sf::Keyboard::Key keycode);

};