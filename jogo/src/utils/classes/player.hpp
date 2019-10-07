
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player {

protected:
    sf::Vector2i size;
    sf::Vector2f position;
    sf::Vector2f speed;

    double hitPoints;
    double maxHitPoints;
    int invulnerable;
    sf::RectangleShape healthBar;
    
    bool onGround;
    static const int jumpSpeed;
    static const int walkSpeed;

    static sf::Texture texture;
    sf::Sprite sprite;

public:
    Player(int x=0, int y=0);
    
    void update(const float deltaTime);
    void render(sf::RenderWindow& window);
    void jump();
    void checkCollisionX();
    void checkCollisionY();

    sf::Vector2f getPosition() { return position; }
    sf::FloatRect getBoundingBox() { return sf::FloatRect(position.x, position.y, size.x, size.y); }
    void isInvulnerable();
    void takeDamage(float dmg); // TODO - colocar timer de invulnerabilidade

};

#endif // PLAYER_HPP_
