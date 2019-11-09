
#ifndef LEVEL_HPP_
#define LEVEL_HPP_

#include <vector>
#include <SFML/Graphics.hpp>
#include <constants.hpp>

#include "obstacle.hpp"

class Level {

public:

    Level(const char* configFile);
    ~Level();

    void init(); // inicializa o nivel

    sf::Vector2f getSpawnPosition(uint pos, int layerWidth);
    
    const char* getConfigPath() { return configPath; }

private:
    const char* configPath;

    void spawnAll(std::vector<int>& mat1, std::vector<int>& mat2, int layerWidth);
    virtual void spawnEnemies(std::vector<int>& mat, int layerWidth) = 0;
    virtual void spawnObstacles(std::vector<int>& mat, int layerWidth) = 0;

};

#endif // LEVEL_HPP_
