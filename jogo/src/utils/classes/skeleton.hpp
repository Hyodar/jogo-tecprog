#ifndef SKELETON_HPP_
#define SKELETON_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "character.hpp"
#include "bardo.hpp"

class Skeleton : public Character {

private:
    static sf::Texture texture;
    Bardo* player;

public:
    Skeleton(int x=0, int y=0, Bardo* pp = nullptr);
    ~Skeleton();
    void checkPlayerPos();
    void update(const float deltaTime);
    void updatePosition(float deltaTime);

};
#endif //SKELETON_HPP_
