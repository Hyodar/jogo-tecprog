
#include <vector>

class Taberna : public Level {

public:
    Taberna();
    ~Taberna();

    void spawnEnemies(std::vector<int>& mat, int layerHeight);
    void spawnObstacles(std::vector<int>& mat, int layerHeight);

private:

};
