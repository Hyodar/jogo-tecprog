
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <SFML/Graphics.hpp>

#include"entity.hpp"

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
        virtual void updatePosition();
        void render(sf::RenderWindow& window);
        
        void isInvulnerable();
        void takeDamage(float dmg);
                
        void checkCollisionX();
        void checkCollisionY();

};

#endif //Character.hpp
