//Implementation file for our button class
//Include internal files
#include "button.hpp"

my_Button::my_Button(sf::IntRect ir)
    : pos(ir) {}

void my_Button::give_type(int i) { // set the type of the tower
    type = i;
}

int my_Button::get_type() {return type;} // get the type of the button

const sf::IntRect my_Button::get_pos() const {return pos;} // get the position of the button
