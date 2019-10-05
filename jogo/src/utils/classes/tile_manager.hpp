
#ifndef _TILE_MANAGER_H
#define _TILE_MANAGER_H

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class TileManager {

private:
    static std::map<char, sf::RectangleShape*> tileSet;
    static sf::Texture tileSetTexture;
    static char tileSetPath[];

    static void createTile(char tileChar, sf::IntRect rect);

public:
    static void loadTileSet();
    static sf::RectangleShape* TEST_getTileTexture(char tileChar);

};

#endif
