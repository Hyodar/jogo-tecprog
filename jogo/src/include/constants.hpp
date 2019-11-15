
#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

const float gravAcc = 5000.0f;
const int windowH = 768;
const int windowW = 1024;

const int TILE_SIZE = 64;
const int COLLISION_TILE_SIZE = 32;

const int healthBarHeight = 10;
const int INVULNERABILITY_TICKS = 1500;

const float FLOORSPIKES_DMG = 20;

enum CharacterClassification {
    BARDO = 0,
    FIEL_ESCUDEIRO = 1,
    SKELETON = 2,
    MAGE = 3,
    FLYING_MONSTER = 4,
    DRAGON = 5
};

enum ObstacleClassification {
    SPIKE = 6,
    LAVA = 7,
    BOX = 8
};

enum ProjectileClassification {
    FIREBALL = 9,
    ENERGY_BALL = 10
};

#endif // CONSTANTS_HPP_
