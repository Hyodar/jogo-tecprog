
#include <SFML/Graphics.hpp>

class Tile {

private:
    sf::RectangleShape* TEST_rect;
    bool collision;
    char tileChar;

public:
    Tile(char tileChar);
    void draw(sf::Vector2f pos);

};