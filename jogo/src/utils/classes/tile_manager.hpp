
#ifndef TILE_MANAGER_HPP_
#define TILE_MANAGER_HPP_

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "tile.hpp"

class TileManager {

private:
    static std::map<int, Tile> tileSet;
    static sf::Texture tileSetTexture;
    static char tileSetPath[];

    static void createTile(int tileNumber, sf::IntRect textureRect, sf::FloatRect colliderRect);

public:
    TileManager();
    ~TileManager();

    enum TileType {
        EmptyTile = 0,
        StoneWoodFloor = 1,
        WoodPillar = 2,
        WoodPlatform1 = 3,
        WoodPlatform2 = 4,
        WoodPlatform3 = 5,
        FloorSpikes = 6
    };

    static void loadTileSet();
    static sf::RectangleShape* getTileTexture(int tileNumber);
    static sf::FloatRect getTileCollider(int tileNumber);

};

#endif // TILE_MANAGER_HPP_
