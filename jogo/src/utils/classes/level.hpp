
#include <vector>

class Level {

public:
    Level(const char* configFile);
    ~Level();

    void init(); // inicializa o nivel

private:
    const char* configPath;

    void spawnAll(std::vector<int> mat, int layerHeight);
    virtual void spawnEnemies(std::vector<int> mat, int layerHeight) = 0;
    virtual void spawnObstacles(std::vector<int> mat, int layerHeight) = 0;

};
