
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <SFML/Graphics.hpp>

#include "entity.hpp"
#include <constants.hpp>

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
        int invulnerabilityTicks;
        bool walkingRight;

        static const int jumpSpeed;
        static const int walkSpeed;

        bool onFire;

    public:
        Character(int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0, int _classification=-1, int _invulnerabilityTicks=INVULNERABILITY_TICKS);
        ~Character();

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
        const bool isAlive() const;

        void setOnGround(bool b);

        float getSpeedX() const;
        float getSpeedY() const;
        void setSpeedX(float s);
        void setSpeedY(float s);

        float getHP() const;
        void setHP(float hp);

        bool getOnFire();
        void setOnFire(bool b);
        void manageOnFire();

        virtual json store();
};

#endif // CHARACTER_HPP_
