//Header file for our map class
//Include all the external libraries
#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>

class Map{
    public:
        sf::Sprite sprite;
        sf::Texture texture;
        std::ifstream openfile;
        sf::Vector2i map[50][50];
        sf::Vector2i counter = sf::Vector2i(0,0);
        Map();
        ~Map();
        void fill(); // fill the tilemap with the correct tiles
        void render(sf::RenderWindow &window); // render the tilemap
        const std::vector<sf::Vector2i>& get_path(); // get the path tiles
    private:
        std::vector<sf::Vector2i> path_tiles;
};