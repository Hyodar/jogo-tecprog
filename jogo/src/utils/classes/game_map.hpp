
#ifndef GAME_MAP_HPP_
#define GAME_MAP_HPP_

#include <vector>

#include <SFML/Graphics.hpp>

#include "tile.hpp"
#include "obstacle.hpp"

#include <constants.hpp>

class GameMap {

private:
    GameMap();
    static GameMap* instance;

    std::vector<std::vector<Tile*>> tileMap;
    std::vector<std::vector<Obstacle>> DEPRECATED_collisionTileMap;
    
    sf::Texture backgroundTexture;
    sf::RectangleShape background;

    int sizeX;
    int sizeY;
    float start;

    void setupTileStart(sf::Vector2f playerPos);

public:
    ~GameMap();
    static GameMap* getInstance();

    void loadBackground();
    void loadMap();
    void clearMap();
    void DEPRECATED_loadCollisionMap();
    void draw(sf::Vector2f playerPos);
    float getStart() { return start; }
    bool IsAtEnd() { return start == sizeX - windowW/TILE_SIZE; }
    bool IsAtStart() { return start == 0; }

    bool getSizeX() { return sizeX; }
    int getMapLength() { return sizeX * TILE_SIZE; }
    std::vector<std::vector<Tile*>>& getTileMap() { return tileMap; }

    Tile* getTile(int line, int col) { return tileMap[line][col]; }
    Obstacle& DEPRECATED_getCollisionTile(int line, int col) { return DEPRECATED_collisionTileMap[line][col]; }
};

#endif // GAME_MAP_HPP_