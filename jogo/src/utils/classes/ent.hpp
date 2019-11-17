
#ifndef ENT_HPP_
#define ENT_HPP_

#include <SFML/Graphics.hpp>

class Ent {

protected:

    sf::Vector2f position;

public:
    Ent(float posX = 0, float posY = 0);
    ~Ent();

    virtual void render(sf::RenderWindow& window) = 0;

    sf::Vector2f getPosition() const;
    void setPosX(float p);
    void setPosY(float p);
    float getPosX() const;
    float getPosY() const;

};

#endif // ENT_HPP_
