#ifndef SKELETON_HPP_
#define SKELETON_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "enemy.hpp"
#include "bardo.hpp"

class Skeleton : public Enemy {

private:
    static sf::Texture texture;
    
    int jumpCounter;
    int jumpInterval;

public:
    Skeleton(int x=0, int y=0, Bardo* pp = nullptr);
    ~Skeleton();
    void checkPlayerPos();
    void update(const float deltaTime);
    void updatePositionX(float deltaTime);
    void updatePositionY(float deltaTime);

};
#endif //SKELETON_HPP_
