
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <SFML/Graphics.hpp>

#include "entity.hpp"
#include "level_manager.hpp"
#include "entity_manager.hpp"

class Character : public Entity {

    protected:
        sf::Sprite sprite;
        sf::RectangleShape healthBar;

        sf::Vector2f speed;

        double hitPoints;
        double maxHitPoints;
        bool onGround;
        static const int jumpSpeed;
        static const int walkSpeed;

        int invulnerable;

    public:
        Character(int x=0, int y=0, int sizeX=0, int sizeY=0, double maxHP=0);
        ~Character();

        virtual void checkKeys();
        void jump();
        
        void update(const float deltaTime);
        virtual void updatePositionX(float deltaTime);
        virtual void updatePositionY(float deltaTime);
        void render(sf::RenderWindow& window);
        
        void isInvulnerable();
        void takeDamage(float dmg);
        
        bool collide(Collidable& c);

        void setOnGround(bool b) { onGround = b; }

        float getSpeedX() { return speed.x; }
        float getSpeedY() { return speed.y; }

        void setSpeedX(float s) { speed.x = s; }
        void setSpeedY(float s) { speed.y = s; }

        void setPosX(float p) { position.x = p; }
        void setPosY(float p) { position.y = p; }
        float getPosX() { return position.x; }
        float getPosY() { return position.y; }

        float getHP() { return hitPoints; }
        void setHP(float hp) { hitPoints = hp; }

};

#endif //Character.hpp
