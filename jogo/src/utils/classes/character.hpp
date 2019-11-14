
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class Tile;
class Obstacle;

class Character : public Entity {

    protected:
        sf::Sprite sprite;
        sf::RectangleShape healthBar;

        sf::Vector2f speed;

        double hitPoints;
        double maxHitPoints;
        
        bool onGround;

        int invulnerable;
        bool walkingRight;

        static const int jumpSpeed;
        static const int walkSpeed;

    public:
        Character(int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0);
        ~Character();

        virtual void checkKeys();
        void jump(const float factor = 1);
        
        void update(const float deltaTime);
        virtual void updatePositionX(float deltaTime);
        virtual void updatePositionY(float deltaTime);
        virtual void render(sf::RenderWindow& window);

        virtual void collideX(Tile* t);
        virtual void collideY(Tile* t);

        virtual void collideX(Obstacle* o);
        virtual void collideY(Obstacle* o);
        
        void isInvulnerable();
        void takeDamage(float dmg);
        const bool isAlive() const { return hitPoints > 0; }

        void setOnGround(bool b) { onGround = b; }

        float getSpeedX() { return speed.x; }
        float getSpeedY() { return speed.y; }
        void setSpeedX(float s) { speed.x = s; }
        void setSpeedY(float s) { speed.y = s; }

        float getHP() { return hitPoints; }
        void setHP(float hp) { hitPoints = hp; }
};

#endif // CHARACTER_HPP_
