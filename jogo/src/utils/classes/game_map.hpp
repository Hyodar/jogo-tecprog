
#ifndef GAME_MAP_HPP_
#define GAME_MAP_HPP_

#include <vector>

#include <SFML/Graphics.hpp>

#include <constants.hpp>

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
    float getStart() { return start; }
    bool IsAtEnd() { return start == sizeX - windowW/TILE_SIZE; }
    bool IsAtStart() { return start == 0; }

    int getSizeX() { return sizeX; }
    int getSizeY() { return sizeX; }

    int getMapLength() { return sizeX * TILE_SIZE; }
    std::vector<std::vector<Tile*>>& getTileMap() { return tileMap; }

    Tile* getTile(int line, int col) { return tileMap[line][col]; }
};

#endif // GAME_MAP_HPP_