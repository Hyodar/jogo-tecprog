
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class TileManager {

private:
    static std::map<char, sf::Texture&> tileSet;
    static sf::Texture tileSetTexture;
    static char tileSetPath[];

public:
    static void loadTileSet();
    static sf::Texture& getTileTexture(char tileChar);
    static sf::RectangleShape* TEST_getTileTexture(char tileChar);

};