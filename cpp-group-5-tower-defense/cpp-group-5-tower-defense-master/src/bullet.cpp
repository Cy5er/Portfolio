//Implementation file for our bullet class
//Include external libraries
#include <iostream>

//Include internal files
#include "bullet.hpp"


Bullet::Bullet(){ // default constructor
    shape.setRadius(5.f);
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(40.f,40.f);
    damage = 1;
    collides = false;
    position = shape.getPosition();
}
Bullet::Bullet(sf::Vector2f start_pos){ // constructor with a specific position
    shape.setRadius(1.f);
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(start_pos);
    damage = 1;
    collides = false;
    position = shape.getPosition();
}
Bullet::~Bullet(){}

void Bullet::render(sf::RenderWindow& window){
    if(collides){ // if the bullet has it an enemy
        return; // exit the function
    }
    window.draw(shape); // render the bullet
}

bool Bullet::collision(base_monster& mon){ // function that returns if a bullet has it an enemy or not
    if(abs(position.x) >= abs(mon.pos_.x - 20) && abs(position.y) >= abs(mon.pos_.y - 20)){ // if the bullet and the monster intersect
        mon.isHit = true; // monster is hit

        if(mon.hitpoints_ < 1){ // if the monster has lost all of its hp
            return true;
        }
        mon.hitpoints_ -= 1; // subtract 1 from the monster's hp
        collides = true;
        return collides; // return that the it has collied
    }

    else{ // if it does not intersect
        collides = false;
        return collides; // return that it has not collided
    }
}

void Bullet::update(base_monster& mon){ // update the state of the bullet
    position = shape.getPosition();
    m_pos = mon.pos_;
    m_vel = mon.vel;
    if(!collides){ // if the monster has not collided
        collision(mon); // check for collision
    }
    if(collides == 0){ // if it has collided
        for(auto vel: m_vel){ // loop though all the velocities of the monster
            //set positions with the new positions
            position = shape.getPosition();
            m_pos = mon.pos_;
            sf::Vector2f diff = (m_pos - position);
            sf::Vector2f go;
            // using v1 = ((x2-x1) + v2 * t) / t, calculate the velocity that tge bullets needs to intersect the monster
            go.x = (diff.x + (vel.x * 0.1))/0.1f;
            go.y = (diff.y + (vel.y * 0.1))/0.1f;
            shape.move(go.x * 11/60, go.y * 11/60); // move the monster with the right velocity and a multiplying factor to make it look smooth
        }
    }
}