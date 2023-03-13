//Implementation file for our two_hit monster class
//Include internal files
#include "two_hit.hpp"
#include "game.hpp"
#include "iostream"

two_hit::two_hit(std::string name, size_t hp){ // regular constructor
    name_ = name;
    alive_ = true;
    isHit = false;
    hitpoints_ = 2;
    hit_player = false;
    value = 2;
    pos_ = sf::Vector2f(0,0);
    body.setSize(sf::Vector2f(10,10));
    i = 0;
    count = 0;
    body.setFillColor(sf::Color::Blue);
    body.setPosition(pos_);
    
}



two_hit::two_hit(std::string name, size_t hp, sf::Vector2f position){ // constructor with specific position
    alive_ = true;
    isHit = false;
    hit_player = false;
    value = 2;
    hitpoints_ = 2;
    pos_ = position;
    body.setSize(sf::Vector2f(10,10));
    body.setFillColor(sf::Color::Blue);
    body.setPosition(pos_);
    
}


two_hit::~two_hit(){}

void two_hit::render(sf::RenderWindow &window){ // render the monster
    if(isHit && !alive_){ // if it is hit and not dead
        body.setFillColor(sf::Color::Black); // change the color to black
        window.draw(body);
        return;
    }
    else{
        window.draw(body);
    }
}

void two_hit::update(std::vector<float> xx , std::vector<float> yy, int count){ // update the state of the monster
    if(hitpoints_ <= 0){ // if the monster has lost all of its hp
            alive_ = false; // the monster has died
            return; // exit the function
        }
    if(isHit){ // if it is hit
        hitpoints_ -=1;
        isHit = false; // set is hit to false
    }
        if(i < count){ // only move if the times moved is less than the total amount the monster has to move
            sf::Vector2f movement(xx[i],yy[i]); // calculate how much it has to move
                    body.move(movement.x,movement.y);
                    pos_ = body.getPosition(); 
                    if(pos_.x > 780 || pos_.y > 780){ // if out of bounds
                        body.setPosition(780, 654); // set to last path tile
                        getTo_.clear();
                        return;
                    }
        i++; // update how many times it's moved
        }
}



void two_hit::get(sf::Vector2i map[50][50], int x, int y){ // initializes the path tiles that the monster has to visit
         for(int i = 0; i < x; i++){ // for loop for columns
            for(int j = 0;  j < y; j++){ // for loop for rows
                // if the index has a valid number then place a tile in that position
                    if(map[i][j].x > 0){
                        getTo_.push_back(std::make_pair((float)i*16.0f,(float) j * 16.0f)); // add the current coordinates to the vector
                    }
            }
        }
}


void two_hit::offset(){ // initializes all the offsets that the monster needs to move by
    sf::Vector2f npos = pos_;
                for(int i = 0; i < getTo_.size(); i++){ // iterate through getTo
                while(abs(getTo_[i].first - npos.x) != 0  || abs(getTo_[i].second - npos.y) != 0 ){ // while the current coordinates are not the same as destination coordinates
                        xoff = ((float)getTo_[i].first - npos.x) * (1.f/60.f) * 10; // calculate the x offset and make the movement look smooth
                        xx.push_back(xoff); // add the x offset to the vector
                        yoff = ((float)getTo_[i].second - npos.y) * (1.f/60.f) * 10; // calculate the x offset and make the movement look smooth
                        yy.push_back(yoff);// add the y offset to the vector
                        vel.push_back(sf::Vector2f(xoff,yoff)); // add the offsets to the velocity vector
                    npos = sf::Vector2f(npos.x + xoff , npos.y + yoff); // add offsets to npos
                    count++; // increase the amount of steps taken
                }
            }

}
