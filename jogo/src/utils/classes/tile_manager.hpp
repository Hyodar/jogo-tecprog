
#ifndef _TILE_MANAGER_H
#define _TILE_MANAGER_H

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class TileManager {

private:
    static std::map<int, sf::RectangleShape*> tileSet;
    static sf::Texture tileSetTexture;
    static char tileSetPath[];

    enum TileType {
        EmptyTile,
        StoneWoodFloor,
        WoodPillar,
        WoodPlatform1,
        WoodPlatform2,
        WoodPlatform3
    };

    static void createTile(int tileNumber, sf::IntRect rect);

public:
    static void loadTileSet();
    static sf::RectangleShape* TEST_getTileTexture(int tileNumber);

};

#endif
