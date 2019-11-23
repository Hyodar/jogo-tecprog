
#ifndef BARDO_HPP_
#define BARDO_HPP_

#include <string>

#include <thread>
#include <mutex>

#include <SFML/Graphics.hpp>

#include "character.hpp"

namespace bardadv::characters {

class Enemy;

class Bardo : public Character {

private:
    int attackCounter;
    int attackInterval;

    int onFireCounter;

    static std::mutex* invulnerabilityMutex;
    std::thread* invulnerabilityThread;
    std::thread* onFireThread;

    void resetAttackCounter();

public:
    Bardo(int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0);
    ~Bardo();

    void updateStartPosition();
    void checkKeys();
    void render(sf::RenderWindow& window);
    sf::FloatRect getBoundingBox() const;
    sf::FloatRect getAttackBoundingBox() const;

    void initThreads();

    void collideX(Enemy* e);

    void updatePositionX(const float deltaTime);
    void updatePositionY(const float deltaTime);

    void checkInvulnerability();
    void checkOnFire();

    bool isAttacking();

    void burn();

    json store();

};

}

#endif // BARDO_HPP_
