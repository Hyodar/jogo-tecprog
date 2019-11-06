
#ifndef LEVEL_HPP_
#define LEVEL_HPP_

#include <vector>
#include <SFML/Graphics.hpp>

class Level {

public:

    enum EnemyClassification {
        EsqueletoGuerreiro,
        MagoTrevoso,
        Dragao
    };

    enum ObstacleClassification {
        Spikes = 1,
        Lava = 2,
        Box = 6
    };

    Level(const char* configFile);
    ~Level();

    void init(); // inicializa o nivel

    sf::Vector2f getSpawnPosition(uint pos, int layerWidth);

private:
    const char* configPath;

    void spawnAll(std::vector<int>& mat, int layerWidth);
    virtual void spawnEnemies(std::vector<int>& mat, int layerWidth) = 0;
    virtual void spawnObstacles(std::vector<int>& mat, int layerWidth) = 0;

};

#endif // LEVEL_HPP_
