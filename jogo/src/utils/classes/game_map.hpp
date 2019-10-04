
#include <vector>
#include "tile.hpp"

class GameMap {

private:
    static std::vector<std::vector<Tile>> tileMap;
    static int sizeX;
    static int sizeY;

public:
    static void loadMap();
    static void drawTiles(sf::Vector2f playerPos);

};