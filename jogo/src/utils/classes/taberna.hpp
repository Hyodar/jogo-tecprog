
#ifndef TABERNA_HPP_
#define TABERNA_HPP_

#include <vector>

#include "level.hpp"

#include "spike.hpp"
#include "lava.hpp"
#include "box.hpp"
#include "skeleton.hpp"

class Taberna : public Level {

public:
    Taberna();
    ~Taberna();

    void spawnEnemies(std::vector<int>& mat, int layerWidth);
    void spawnObstacles(std::vector<int>& mat, int layerWidth);

private:

};

#endif // TABERNA_HPP_
