//Header file for our base tower class
//Include external libraries
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "base_monster.hpp"

class base_tower {
    public:
        //virtual functions as this is a base class
        base_tower(int tower_type, double fr, double rng);
        virtual ~base_tower() = default;
    
        int tower_type;
        double firerate;
        double range;
        sf::RectangleShape shape;
        bool cooldown;

};
