//Implementation file that for our Game class
//Include external libraries
#include <vector>
#include <memory>
#include <cmath>
#include <fstream>

//Include internal files
#include "game.hpp"
#include "base_monster.hpp"
#include "one_hit.hpp"
#include "base_tower.hpp"
#include "single_shot_tower.hpp"
#include "button.hpp"
#include "map.hpp"
#include "bullet.hpp"
#include "two_hit.hpp"
#include "three_hit.hpp"

Game::Game() : window(sf::VideoMode(1200,800), "SFML window"), towers(), monsters() {
    play_area = sf::IntRect(0,0,800,800); // set 800*800 play area
    money = 10;
    round_start = false;
    round = 0;
    round_end = true;
    player_hp = 10;
    build_buttons(); // build all the buttons
    tilemap.fill(); // fill the tilemap with the tiles
    disallowed_tiles = tilemap.get_path(); // all path tiles are not buildable tiles

    if (!my_font.loadFromFile("src/fonts/arial.ttf")) { // when failed to load font
        std::cout << "font load failed" << std::endl; // print failure statement
    } 

    else {
        std::cout <<"font load successful" << std::endl;
        text.setFont(my_font);
        gameEnd.setFont(my_font);
    }

}

void Game::run() {
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        process_events(); // check and process events

        if(player_hp > 0){ // if the player is alive
        time_since_last_update += clock.restart(); // increase time since last update

        while (time_since_last_update > time_per_frame) { // keep updating if the time from last update is greater than time per frame
            process_events();
            time_since_last_update -= time_per_frame;
            update(time_per_frame);
        }

        }

        render(); // render all the objects
    }
}

void Game::initMonVar(){
        for(auto &&it:monsters){ // go through all the monsters
            it->get(tilemap.map,tilemap.counter.x, tilemap.counter.y); // get the path tiles that the monster has to visit
            it->offset();// calculate all the offsets that the monster needs to move by to reach all the path tiles
        }
}

void Game::spawnEnemies(){
    if(round_start && round == 1){ // round 1
        auto mons = std::make_unique<one_hit>("monster", 1,sf::Vector2f(16,16)); // create a one hit monster at specific coordinates
        auto mon = std::make_unique<two_hit>("monster", 1,sf::Vector2f(-16 * 4,0));
        monsters.push_back(std::move(mons)); // push back the monster into the monsters vector
        monsters.push_back(std::move(mon));
        Game::initMonVar(); // initialise all the monster varaibles
        round_start = false; // round has started
    }
    if(round_start && round == 2){ // round 2
        monsters.clear(); // clear the monsters vector from pervious round
        auto mons = std::make_unique<one_hit>("monster", 10,sf::Vector2f(16,16));// create a one hit monster at specific coordinates
        auto monss = std::make_unique<one_hit>("monster", 10,sf::Vector2f(-16,16));
        auto mon = std::make_unique<two_hit>("monster", 10,sf::Vector2f(-16 * 4,0));// create a two hit monster at specific coordinates
        auto mo = std::make_unique<three_hit>("monster", 10,sf::Vector2f(64,16));// create a three hit monster at specific coordinates
        monsters.push_back(std::move(mons));// push back the monster into the monsters vector
        monsters.push_back(std::move(monss));
        monsters.push_back(std::move(mon));
        monsters.push_back(std::move(mo));
        Game::initMonVar();// initialise all the monster varaibles
        round_start = false; // round has started
    }
    if(round_start && round == 3){ // round 3 repeat the same as before but with more monsters
        monsters.clear();
        auto mons = std::make_unique<one_hit>("monster", 10,sf::Vector2f(16,16));
        auto monss = std::make_unique<one_hit>("monster", 10,sf::Vector2f(-16 * 4,16));
        auto mon = std::make_unique<two_hit>("monster", 10,sf::Vector2f(-16,0));
        auto monn = std::make_unique<two_hit>("monster", 10,sf::Vector2f(-16 * 4,0));
        auto mo = std::make_unique<three_hit>("monster", 10,sf::Vector2f(64,16));
        monsters.push_back(std::move(mons));
        monsters.push_back(std::move(monss));
        monsters.push_back(std::move(mon));
        monsters.push_back(std::move(monn));
        monsters.push_back(std::move(mo));
        Game::initMonVar();
        round_start = false;
    }
    if(round_start && round == 4){
        monsters.clear();
        auto mons = std::make_unique<one_hit>("monster", 10,sf::Vector2f(16,16));
        auto monss = std::make_unique<one_hit>("monster", 10,sf::Vector2f(-16 * 4,16));
        auto mon = std::make_unique<two_hit>("monster", 10,sf::Vector2f(-16,0));
        auto monn = std::make_unique<two_hit>("monster", 10,sf::Vector2f(-16 * 4,0));
        auto mo = std::make_unique<three_hit>("monster", 10,sf::Vector2f(64,16));
        auto moo = std::make_unique<three_hit>("monster", 10,sf::Vector2f(64 * 4,16));
        monsters.push_back(std::move(mons));
        monsters.push_back(std::move(monss));
        monsters.push_back(std::move(mon));
        monsters.push_back(std::move(monn));
        monsters.push_back(std::move(mo));
        monsters.push_back(std::move(moo));
        Game::initMonVar();
        round_start = false;
    }
    if(round_start && round == 5){
        monsters.clear();
        auto mons = std::make_unique<one_hit>("monster", 1,sf::Vector2f(16,16));
        auto monss = std::make_unique<one_hit>("monster", 1,sf::Vector2f(-16 * 4,16));
        auto monsss = std::make_unique<one_hit>("monster", 1,sf::Vector2f(-16 * 4* 4,16));
        auto mon = std::make_unique<two_hit>("monster", 2,sf::Vector2f(-16,0));
        auto monn = std::make_unique<two_hit>("monster", 2,sf::Vector2f(-16 * 4,0));
        auto monnn = std::make_unique<two_hit>("monster", 2,sf::Vector2f(-16 * 4* 4,0));
        auto mo = std::make_unique<three_hit>("monster", 3,sf::Vector2f(64,16));
        auto moo = std::make_unique<three_hit>("monster", 3,sf::Vector2f(64* 4,16));
        auto mooo = std::make_unique<three_hit>("monster", 3,sf::Vector2f(64* 4* 4,16));
        monsters.push_back(std::move(mons));
        monsters.push_back(std::move(monss));
        monsters.push_back(std::move(monsss));
        monsters.push_back(std::move(mon));
        monsters.push_back(std::move(monn));
        monsters.push_back(std::move(monnn));
        monsters.push_back(std::move(mo));
        monsters.push_back(std::move(moo));
        monsters.push_back(std::move(mooo));
        Game::initMonVar();
        round_start = false;
    }
    
}

void Game::reset(){ // reset the game state
    // reset all varaible values to the original values
    money = 10;
    round_start = false;
    round = 0;
    round_end = true;
    player_hp = 3;

    //clear all vectors
    monsters.clear();
    shooters.clear();
    towers.clear();
}


void Game::process_events() { // process mouse and keyboard events (i.e button clicks)
  
    sf::Event event;
    bool clicked = false;
    while (window.pollEvent(event)) { // poll for an event

        if (event.type == sf::Event::Closed) { // if trying to close window
            window.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && player_hp <= 0){ // if the player is dead and the screen is clicked
                Game::reset(); // reset the game
            }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && player_hp > 0) { // if the player is alive and the screen is clicked
            if (play_area.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) { // if clicked within the play area
                highlight_rect = true; // set tile selected as true
                store_mouse_pos = sf::Mouse::getPosition(window); // store the mouse position
            }
            for (auto& it: buttons) { // loop through all the buttons
                if (it.get_pos().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && highlight_rect) { // if clicked on a button
                    if (it.get_type() == 0) { // if is single tower
                        if(money >= 3){ // if the player has enough money
                            add_tower(1); // create the tower
                            money -=3; // subtract the money
                        } else {
                            std::cout << "not enough money to build a tower" << std::endl;
                        }
                    }
                    // same thing was single tower was done for the rest of the different types of towers
                    if (it.get_type() == 2) {
                        if(money >= 4){
                            add_tower(2);
                            money -=4;
                        } else {
                            std::cout << "not enough money to build a tower" << std::endl;
                        }
                    }
                    if (it.get_type() == 4) {
                        if(money >= 5){
                            add_tower(3);
                            money -=5;
                        } else {
                            std::cout << "not enough money to build a tower" << std::endl;
                        }
                    }
                    if (it.get_type() == 3) { // if clicked on reset 
                        Game::reset(); // reset the game state
                        }
                    highlight_rect = false; // tile is no longer selected
                }
            if (it.get_pos().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){ // if clicked on a button
            if(it.get_type() == 1 && !round_start && round_end){ // if start round is clicked and the last round has ended and the current round has not started
                if(round < 5){
                    round_start = true; // set that the current round has started 
                    round++; // increase the round number
                }
            }
            }
        }
    }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){ // on a right click
            for (auto&& it: buttons) {
                if (it.get_pos().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && highlight_rect && it.get_type() == 5) { // if clicked on manually spawn enemies and a tile is selected
                // spawn one enemy of each type
                auto mons = std::make_unique<one_hit>("monster", 10);
                auto mon = std::make_unique<two_hit>("monster", 10);
                auto mo = std::make_unique<three_hit>("monster", 10);
                monsters.push_back(std::move(mons));
                monsters.push_back(std::move(mon));
                monsters.push_back(std::move(mo));
                Game::initMonVar();
                highlight_rect = false; 
                }
            }
        }
        // Resize event, currently not in use but can be built in the future
        // if (event.type == sf::Event::Resized) {
        //     std::cout << "window resized new x: " << window.getSize().x << "and new y: "<<  window.getSize().y << std::endl;
        //     //auto xmulti = window.getSize().x/1200.0;
        //     //auto ymulti = window.getSize().y/800.0;
        //     std::cout << "new x: " << store_mouse_pos.x << std::endl;
        // }  
    }
}

void Game::update(sf::Time frame_time) { // update the game state
    Game::spawnEnemies(); // spawn the enemies if the round just started
    float dist_x;
    float dist_y;
    float distance;

    for (auto&& it : monsters) { // loop through all the monsters
        it->update(it->xx, it->yy,it->count); // update the states of the monsters
        round_end = true;

        if(it->alive_){ // if the monster is still alive
            round_end = false; // round has not ended
            it->already_paid = false; // the monster has not already given player its money

            for (auto&& tower: towers) { // loop through all the towers
                dist_x = abs(tower->shape.getPosition().x - it->pos_.x); // calculate the distance from the towers to the monsters
                dist_y = abs(tower->shape.getPosition().y - it->pos_.y);
                distance = std::sqrt(std::pow(dist_x,2) + std::pow(dist_y,2));

                if(!tower->cooldown && distance < tower->range) { // if the tower is not on cooldown and the monster is in range
                    auto bul = std::make_unique<Bullet>(tower->shape.getPosition()); // create a bullet at the towers location
                    shooters.push_back(std::move(bul)); // add the bullet to the vector of bullets
                    tower->cooldown = true; // set that the tower is now on cooldown
                }

            }

        }

        for(auto &i:shooters){ // loop though all the bullets

            if (it->alive_ && !i->collides) { // if the monster is alive and hasn't been hit
            i->update(*it); // shoot the bullet at the monster
            }

        if(!it->alive_ && !it->already_paid){ // if the monster is dead and has not given its money
                it->already_paid = true; // then set that the monster has given the money to true
                money += it->value; // add its money to the player's money
            }

        }

      if( it->pos_.x >= 780 && it->pos_.y >= 650 && !it->hit_player){ // if the monster has reached the end of the path and has not been it
        it->hit_player = true; // the monster has hit the player
        player_hp -= it->value; // subtract the monsters hp from player hp
         round_end = true;
      }
    }

    for (auto&& tower : towers) { // loop through all the towers
        if (tower->cooldown) { // if the the tower is on cooldown
            tower->firerate -= frame_time.asMilliseconds(); // subtract the frame rate from the fire rate
            if (tower->firerate < 0) { // if the tower has shot all that it can
                tower->cooldown = false; // set that it is no longer on cool down
                // reset all the towers fire rates back to their original ones
                if (tower->tower_type == 1) {tower->firerate = 1000.0;} 
                if (tower->tower_type == 2) {tower->firerate = 5000.0;}
                if (tower->tower_type == 3) {tower->firerate = 400.0;}    
            }
        }
    }
    
    if(round_end){ // if the round has ended then clear the monster and bullet vectors
        monsters.clear();
        shooters.clear();
    }
    if(round_end && round == 5){
        player_hp =0; // when all 5 rounds is over, set player hp tp 0 to trigger the game over screen
    }

    return;
}

void Game::render() {
    window.clear(); // clear the window from the last update
    show_ui(); // generate the UI
    tilemap.render(window); // render the tilemap
    if (highlight_rect) { // if a tile is highlighted
        show_highlighter(); // render the highlight
    }
    for (auto&& it : monsters) {
        it->render(window); // render all the monsters
    }

    for (auto&& tower : towers) {
        window.draw(tower->shape); // render all the towers
    }
    for(auto &i:shooters){
        i->render(window); // render all the bullets
    }

    window.draw(text); // render all the text for the buttons
    if(player_hp <= 0 || round == 6){ // if the player is dead
        window.clear(sf::Color::Black); // set the screen to black
        window.draw(gameEnd); // shoe game over text
    }
    window.display(); // display the window
}

void Game::add_tower(int type){ // add a specific type of tower

    sf::Vector2i check_tile; // store the tile position of where the tower is trying to be built
    check_tile.x = (store_mouse_pos.x/16);
    check_tile.y = (store_mouse_pos.y/16);
    for (auto&& disallowed : disallowed_tiles) { // check all of the dissallowed tiles

        if (disallowed == check_tile) { // if it matches
            std::cout << "invalid build tile" << std::endl; // return failure statement and no tower is built
            return;
        } 

    }

    if (type == 1) { // if it is a type 1 tower
        auto tower = std::make_unique<single_shot_tower>(1, 1000.0, 150.0); // make a tower with tower type 1, 1 sec shoot time, and 150 pixel range
        sf::RectangleShape tower_shape;
        tower->shape = tower_shape;
        tower->shape.setSize(sf::Vector2f(12,12));
        tower->shape.setPosition((store_mouse_pos.x/16)*16 ,(store_mouse_pos.y/16)*16);
        tower->shape.setPosition(tower->shape.getPosition().x + 2, tower->shape.getPosition().y+2); // place the tower at the correct position
        towers.push_back(std::move(tower)); // add the tower to towers vector
        disallowed_tiles.push_back((check_tile)); // add the tile that the tower is built on to dissallowed tiles
    }
    //do the same for the rest of the types of towers but with different fire rates and ranges
    if (type == 2) {
        auto tower = std::make_unique<single_shot_tower>(2, 5000.0, 450.0);
        sf::RectangleShape tower_shape;
        tower->shape = tower_shape;
        tower->shape.setFillColor(sf::Color::Red);
        tower->shape.setSize(sf::Vector2f(12,12));
        tower->shape.setPosition((store_mouse_pos.x/16)*16 ,(store_mouse_pos.y/16)*16);
        tower->shape.setPosition(tower->shape.getPosition().x + 2, tower->shape.getPosition().y+2);
        towers.push_back(std::move(tower));
        disallowed_tiles.push_back((check_tile));
    }

    if (type == 3) {
        auto tower = std::make_unique<single_shot_tower>(3, 400.0, 50.0);
        sf::RectangleShape tower_shape;
        tower->shape = tower_shape;
        tower->shape.setFillColor(sf::Color::Green);
        tower->shape.setSize(sf::Vector2f(12,12));
        tower->shape.setPosition((store_mouse_pos.x/16)*16 ,(store_mouse_pos.y/16)*16);
        tower->shape.setPosition(tower->shape.getPosition().x + 2, tower->shape.getPosition().y+2);
        towers.push_back(std::move(tower));
        disallowed_tiles.push_back((check_tile));
    }
}

void Game::show_ui() { // function that shows the UI elements

    // create a rectangle shape for the borders of the buttons
    sf::RectangleShape rect1;
    rect1.setSize(sf::Vector2f(390,790));
    rect1.setOutlineColor(sf::Color::Blue);
    rect1.setOutlineThickness(5);
    rect1.setPosition(805,5);
    window.draw(rect1);
    //initialize text
    std::string text_for_tower = "";
    text.setString(text_for_tower);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::Black);

    // make the border for the buttons at the correct places
    int x_offset = 850;
    int y_offset = 100;
    int type_of_button = 0;
    while (y_offset < 500) {
        ++type_of_button;
        while (x_offset < 1000) {
            rect1.setSize(sf::Vector2f(100,100));
            rect1.setOutlineColor(sf::Color::Blue);
            rect1.setOutlineThickness(5);
            rect1.setPosition(x_offset+25,y_offset);
            text.setPosition(x_offset+30,y_offset+30);
            // write the right text for the buttons
            if (type_of_button == 1) {
                text_for_tower = "Build Single \nBasic Tower\nCost: 3";
            } else if (type_of_button == 2) {
                text_for_tower = "Build Sniper \nShot Tower\nCost: 4";
            } else if (type_of_button == 3) {
                text_for_tower = "Build Rapid\nFire Tower\nCost: 5";
            } else {std::cout << "no button was clicked" << std::endl;}
            text.setString(text_for_tower);
            window.draw(rect1);
            window.draw(text);
            x_offset += 150;
        } 
        if (type_of_button == 1) {
            text_for_tower = "Start round";
        } else if (type_of_button == 2) {
            text_for_tower = "Reset";
        } else if (type_of_button == 3) {
            text_for_tower = "Manual \nenemy spawn";
        } else {std::cout << "no button was clicked" << std::endl;}
        text.setPosition(x_offset+30,y_offset+30);
        text.setString(text_for_tower);
        rect1.setSize(sf::Vector2f(100,100));
        rect1.setOutlineColor(sf::Color::Blue);
        rect1.setOutlineThickness(5);
        rect1.setPosition(x_offset+25,y_offset);
        window.draw(rect1);
        window.draw(text);
        x_offset = 850;
        y_offset += 150;
    }

    // Draw player money here
    std::string money_in_text = std::to_string(money);
    text.setPosition(900,600);
    text.setString("Player Money: ");
    window.draw(text);
    text.setPosition(1010,600);
    text.setString(money_in_text);
    window.draw(text);

    // Draw round here
    text.setPosition(900,700);
    text.setString("Round number:");
    window.draw(text);
    std::string round_in_text = std::to_string(round);
    text.setPosition(1015,700);
    text.setString(round_in_text);
    window.draw(text);

    //Draw player hp here
    text.setPosition(900,650);
    text.setString("Player hp:");
    window.draw(text);
    std::string hp_in_txt = std::to_string(player_hp);
    text.setPosition(1015,650);
    text.setString(hp_in_txt);
    window.draw(text);

    //Draw game over here
    gameEnd.setPosition(480,330);
    gameEnd.setString("Game Over\nClick to restart");
}

void Game::show_highlighter() { // fuction the highlights a selected tile
    sf::RectangleShape highlight;
    highlight.setSize(sf::Vector2f(16,16));
    highlight.setFillColor(sf::Color::Transparent);
    highlight.setOutlineColor(sf::Color::White);
    highlight.setOutlineThickness(2);
    // for ints 7/2 --> 3 and then we multiply it again to not make the box move so smoothly and make it snap
    highlight.setPosition((store_mouse_pos.x/16)*16, (store_mouse_pos.y/16)*16);
    window.draw(highlight);
}

void Game::build_buttons() { // function that builds all the buttons
    int x_offset = 850;
    int y_offset = 100;
    int type_num = 0;

    // while within a certain offset
    while (y_offset < 500) {
        while (x_offset < 1000) { // creates buttons of the left column
            auto btn = my_Button(sf::IntRect(x_offset+25, y_offset, 100,100)); // create a button
            btn.give_type(type_num); // give it a certain type
            ++type_num; // increase the type_num
            buttons.push_back(btn); // add the button to the buttons vector
            x_offset += 150; // increase the x offset
        }
        // creates buttons on the right columns
        auto btn = my_Button(sf::IntRect(x_offset+25, y_offset, 100,100)); // create a button
        btn.give_type(type_num);// give it a certain type
        ++type_num;// increase the type_num
        buttons.push_back(btn); // add the button to the buttons vector
        x_offset = 850; // increase the x offset
        y_offset += 150; // increase the y offset
    }
}
