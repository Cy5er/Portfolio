//Header file for our bullet class
//Include external libraries
#pragma once
#include <SFML/Graphics.hpp>

//Include the internal files
#include "base_monster.hpp"

class Bullet{
    public:
        sf::CircleShape shape;
        sf::Vector2f position;
        sf::Vector2f m_pos;
        std::vector<sf::Vector2f> m_vel;
        bool collides;
        int damage;
        Bullet();
        Bullet(sf::Vector2f start_pos); // constructor with a specific position
        ~Bullet();
        void render(sf::RenderWindow& window); // render the bullet
        bool collision(base_monster& mon); // check if the bullet collides with a monster
        void update(base_monster& mon); // update the state of the bullet
};