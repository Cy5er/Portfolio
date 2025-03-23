//Implementation file for our one_hit monster class
//Include internal files
#include "one_hit.hpp"
#include "game.hpp"
#include "iostream"

one_hit::one_hit(std::string name, size_t hp){
    name_ = name;
    alive_ = true;
    isHit = false;
    hitpoints_ = 1;
    hit_player = false;
    pos_ = sf::Vector2f(16,0);
    body.setRadius(8.0f);
    i = 0;
    value = 1;
    count = 0;
    body.setFillColor(sf::Color::Yellow);
    body.setPosition(pos_);
}



one_hit::one_hit(std::string name, size_t hp, sf::Vector2f position){ // constructor with a specific position
    alive_ = true;
    hit_player = false;
    isHit = false;
    hitpoints_ = 1;
    value = 1;
    pos_ = position;
    body.setRadius(8.0f);
    body.setFillColor(sf::Color::Yellow);
    body.setPosition(pos_);
    
}


one_hit::~one_hit(){}

void one_hit::render(sf::RenderWindow &window){ // render the monster
    if(isHit && !alive_){ // if it is hit and not dead
        body.setFillColor(sf::Color::White); // change the color to white
        window.draw(body);
        return;
    }
    else if(alive_ && isHit){ // if it alive and is hit
        isHit = false; // set is hit to false
        body.setFillColor(sf::Color::Red); // change the body color to red
        window.draw(body);
    }
    else{
        window.draw(body);
    }
}

void one_hit::update(std::vector<float> xx , std::vector<float> yy, int count){ // update the state of the monster
    if(hitpoints_ < 1){ // if the monster has lost all of its hp
            alive_ = false; // the monster has died
            return; // exit the function
    }

    else if(isHit && alive_){ // if it is hit and still alive
        isHit = false; // set is hit to false

        if(hitpoints_ < 1){ // if the monster has lost all of its hp
            alive_ = false;// the monster has died
            return;// exit the function
        }
    }
        if(i < count && alive_){ // only move if the times moved is less than the total amount the monster has to move
            sf::Vector2f movement(xx[i],yy[i]); // calculate how much it has to move
                    body.move(movement.x,movement.y);
                    pos_ = body.getPosition(); // if out of bounds
                    if(pos_.x > 780 || pos_.y > 780){
                        body.setPosition(780, 654);
                        getTo_.clear();
                        return;
                    }
        i++;
        }
}



void one_hit::get(sf::Vector2i map[50][50], int x, int y){ // initializes the path tiles that the monster has to visit
         for(int i = 0; i < x; i++){ // for loop for columns
            for(int j = 0;  j < y; j++){ // for loop for rows
                    if(map[i][j].x > 0){
                        getTo_.push_back(std::make_pair((float)i*16.0f,(float) j * 16.0f)); // add the current coordinates to the vector
                    }
            }
        }
}


void one_hit::offset(){ // initializes all the offsets that the monster needs to move by
    sf::Vector2f npos = pos_;
                for(int i = 0; i < getTo_.size(); i++){ // iterate through getTo
                while(abs(getTo_[i].first - npos.x) != 0  || abs(getTo_[i].second - npos.y) != 0 ){ // while the current coordinates are not the same as destination coordinates
                        xoff = ((float)getTo_[i].first - npos.x) * (1.f/60.f) * 11 ;
                        xx.push_back(xoff); // add the x offset to the vector
                        yoff = ((float)getTo_[i].second - npos.y) * (1.f/60.f) * 11 ;
                        yy.push_back(yoff);// add the y offset to the vector
                        vel.push_back(sf::Vector2f(xoff,yoff));
                    npos = sf::Vector2f(npos.x + xoff , npos.y + yoff); // add offsets to npos
                    count++; // increase the amount of steps taken
                }
            }
}
