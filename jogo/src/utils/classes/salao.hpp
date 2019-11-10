
#ifndef SALAO_HPP_
#define SALAO_HPP_

#include <vector>

#include "level.hpp"

class Salao : public Level {

public:
    Salao();
    ~Salao();

    void spawnEnemies(std::vector<int>& mat, int layerWidth);
    void spawnObstacles(std::vector<int>& mat, int layerWidth);

private:

};

#endif // SALAO_HPP_
