//Header file for our button class
//Include external libraries
#pragma once
#include <SFML/Graphics.hpp>

class my_Button {
    public:
    my_Button(sf::IntRect);
    void give_type(int i); // set the type of the button
    int get_type(); // get the type of the button
    const sf::IntRect get_pos() const; // get the position of the button

    private:
    int type;
    sf::IntRect pos;

};