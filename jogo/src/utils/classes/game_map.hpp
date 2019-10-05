
#ifndef _GAME_MAP_HPP
#define _GAME_MAP_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "tile.hpp"
#include "obstacle.hpp"

#include <constants.hpp>

class GameMap {

private:
    static std::vector<std::vector<Tile>> tileMap;
    static std::vector<std::vector<Obstacle>> collisionTileMap;
    
    static sf::Texture backgroundTexture;
    static sf::RectangleShape background;

    static int sizeX;
    static int sizeY;
    static float start;

    static void setupTileStart(sf::Vector2f playerPos);

public:
    static void loadBackground();
    static void loadMap();
    static void loadCollisionMap();
    static void draw(sf::Vector2f playerPos);
    static bool IsAtEnd() { return start == sizeX - windowW/TILE_SIZE; }
    static bool IsAtStart() { return start == 0; }

    static bool getSizeX() { return sizeX; }
    static int getMapLength() { return sizeX * TILE_SIZE; }
    static std::vector<std::vector<Tile>>& getTileMap() { return tileMap; }

    static Tile& getTile(int line, int col) { return tileMap[line][col]; }
    static Obstacle& getCollisionTile(int line, int col) { return collisionTileMap[line][col]; }
};

#endif