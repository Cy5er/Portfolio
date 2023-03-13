//Header file that for our Game class
//Include external libraries
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

//Include internal files
#include "button.hpp"
#include "base_monster.hpp"
#include "base_tower.hpp"
#include "map.hpp"
#include "bullet.hpp"



/*export DISPLAY=$(awk '/nameserver / {print $2; exit}' /etc/resolv.conf 2>/dev/null):0
export LIBGL_ALWAYS_INDIRECT=0*/


class Game {

    public:
        Game();
        void run(); // function that calls all the functions needed to runt the game
        void initMonVar(); // function to initialize all the varaibles in monsters
        void spawnEnemies(); // function that spawns enemies needed for the current round
        void reset(); // reset all the game state to the starting point

        sf::Vector2i store_mouse_pos;
        int round;
        bool round_start;
        bool round_end;
        int player_hp;
        sf::Time time_per_frame = sf::seconds(1.f / 60.f);
        

    private:
        void process_events();// function that takes cares of keyboard and mouse events
        void update(sf::Time); // function that updates the game state
        void render(); // function that renders all the needed objects
        void add_tower(int); // function that places down a tower
        void show_ui(); // function that places UI elements
        void show_highlighter(); // function that shows what tile is currently selected
        void build_buttons(); // function that makes interactable buttons

        int money;
        sf::Text gameEnd; // text that stores game over text
        std::vector<std::unique_ptr<Bullet>> shooters; // vector that stores unique pointers to bullets
        sf::RenderWindow window;
        std::vector<std::unique_ptr<base_tower>> towers;// vector that stores unique pointers to towers
        std::vector<std::unique_ptr<base_monster>> monsters;// vector that stores unique pointers to monsters
        std::vector<my_Button> buttons; // vector that stores all the buttons
        std::vector<sf::Vector2i> disallowed_tiles; // vector that stores tiles that are not allowed to be built on
        sf::IntRect play_area; // coordinates for the playable area
        bool highlight_rect; // boolean that indicates if a current 
        bool clicked;
        Map tilemap;
        sf::Font my_font;
        sf::Text text; // text that stores the texts to be printed on the buttons

};

