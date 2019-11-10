
#ifndef TILE_MANAGER_HPP_
#define TILE_MANAGER_HPP_

#include <map>
#include <SFML/Graphics.hpp>

#include "tile.hpp"

class TileManager {

private:
    static TileManager* instance;
    TileManager();

    std::map<int, Tile> tileSet;

    void createTile(int tileNumber, sf::IntRect textureRect, sf::FloatRect colliderRect);

public:
    ~TileManager();
    static TileManager* getInstance();

    enum TileType {
        EmptyTile = 0,
        StoneWoodFloor = 1,
        WoodPillar = 2,
        WoodPlatform1 = 3,
        WoodPlatform2 = 4,
        WoodPlatform3 = 5,
        FloorSpikes = 6
    };

    void loadTileSet();
    sf::RectangleShape* getTileTexture(int tileNumber);
    sf::FloatRect getTileCollider(int tileNumber);

};

#endif // TILE_MANAGER_HPP_
