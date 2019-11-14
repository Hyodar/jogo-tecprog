
#ifndef ENT_HPP_
#define ENT_HPP_

#include <SFML/Graphics.hpp>

class Ent {

protected:
    sf::Vector2f position;

public:
    Ent(float posX, float posY) : position(posX, posY) {}
    ~Ent() {}

    virtual void render(sf::RenderWindow& window) = 0;

    sf::Vector2f getPosition() { return position; }    
    void setPosX(float p) { position.x = p; }
    void setPosY(float p) { position.y = p; }
    float getPosX() { return position.x; }
    float getPosY() { return position.y; }

};

#endif // ENT_HPP_
