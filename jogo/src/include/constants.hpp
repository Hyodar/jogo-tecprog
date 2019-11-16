
#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

const float GRAV_ACC = 5000.0f;
const int WINDOW_H = 768;
const int WINDOW_W = 1024;

const int TILE_SIZE = 64;
const int COLLISION_TILE_SIZE = 32;

const int HEALTH_BAR_HEIGHT = 10;
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

enum MenuCommand {
    NOOP = 0,
    EXIT = 1,
    PLAY_1_TABERNA = 2,
    PLAY_2_TABERNA = 3,
    PLAY_1_SALAO = 4,
    PLAY_2_SALAO = 5,
    RESUME = 6,
    RECOVER_SAVE = 7,
    SAVE = 8,
    RETURN = 9,
};

enum Points {
    SKELETON_REWARD = 10,
    MAGE_REWARD = 20,
    FLYING_MONSTER_REWARD = 100,
    DRAGON_REWARD = 1000
};

#endif // CONSTANTS_HPP_
