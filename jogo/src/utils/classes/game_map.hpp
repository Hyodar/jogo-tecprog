
#ifndef GAME_MAP_HPP_
#define GAME_MAP_HPP_

#include <vector>

#include <SFML/Graphics.hpp>

#include <constants.hpp>

namespace bardadv::map {
class Tile;

class GameMap {

private:
    GameMap();
    static GameMap* instance;

    std::vector<std::vector<Tile*>> tileMap;

    sf::RectangleShape background;

    int sizeX;
    int sizeY;
    float start;

    void setupTileStart();

public:
    ~GameMap();
    static GameMap* getInstance();

    void loadBackground();
    void loadMap();
    void clearMap();
    void draw();
    float getStart();
    bool IsAtEnd();
    bool IsAtStart();
    bool isPositionValid(int row, int col);

    int getSizeX();
    int getSizeY();

    int getMapLength();
    std::vector<std::vector<Tile*>>& getTileMap();

    Tile* getTile(int line, int col);
};

}

#endif // GAME_MAP_HPP_
