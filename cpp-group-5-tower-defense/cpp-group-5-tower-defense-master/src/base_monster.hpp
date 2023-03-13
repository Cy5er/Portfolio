//Header file for our base monster class
//Include external libraries
#pragma once
#include <SFML/Graphics.hpp>

class base_monster{
    public:
        // all are virtual functions as this is a base class
        virtual ~base_monster() = default;
        virtual void render(sf::RenderWindow&) = 0;
        virtual void update(std::vector<float> xx , std::vector<float> yy, int count) = 0;
        virtual void offset() = 0;
        virtual void get(sf::Vector2i map[50][50], int x, int y) = 0;

        std::string name_;
        sf::Vector2f pos_;
        int hitpoints_;
        bool isHit;
        int i=0;
        std::vector<float> xx , yy; // vector the stores the x and y offsets
        std::vector<sf::Vector2f> vel; // vector the stores the velocity of the monster
        float xoff,yoff;
        int value;
        int count =0;
        bool alive_;
        bool hit_player;
        bool already_paid;
};