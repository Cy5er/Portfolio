//Implementation file for our map class
//Include external libraries
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

//Include internal files
#include "map.hpp"


Map::Map(){
    openfile.open("src/map.txt", std::ifstream::in); // read the map from the file
}

Map::~Map(){}

void Map::fill(){ // fill the tilemap with the correct tiles
     if(openfile.is_open()){ // if the file opens
        std::string str;
        openfile >> str; // get and store the location of the image file
        texture.loadFromFile(str); // load the texture from the file
        sprite.setTexture(texture); // set the texture
        
        while(!openfile.eof()){ // if not at the end of the line
            std::string str;
            openfile >> str; // get and store the value of that specific tile from map.txt
            char x = str[0];
            char y = str[2];
            
            if(!isdigit(x) || !isdigit(y)){ // if x or y isn't a digit
                map[counter.x][counter.y] = sf::Vector2i(-1,-1); // set the map values for that tile to be -1,-1
            }

            else { // if it is a valid number
                map[counter.x][counter.y] = sf::Vector2i(x - '0', y -'0'); //set the map values for that tile to be x,y
            }

            if(openfile.peek() == '\n'){ // if the next character is \n then go to the next row in map
                counter.x = 0;
                counter.y++;
            }

            else{
                counter.x++; // else go to the next column in map
            }
        }
        counter.y++; // go to the next row in map
        
    }
    // generate the map file to push to dissallowed tiles
    // map[i][j].x == 0 --> grass; map[i][j].x == 1 --> path
    sf::Vector2i path;
    for(int i = 0; i < 50; i++){ // for loop for columns
        for(int j = 0;  j < 50; j++){ // for loop for rows
            if(map[i][j].x > 0) {
                path.x = i*16;
                path.y = j*16;
                path_tiles.push_back((path/16));
            }
        }
    }
}

void Map::render(sf::RenderWindow &window){ // render the tilemap
        for(int i = 0; i < counter.x; i++){ // for loop for columns
            for(int j = 0;  j <counter.y; j++){ // for loop for rows
               // if the index has a valid number then place a tile in that position
                    sprite.setPosition(i * 16, j * 16); 
                    sprite.setTextureRect(sf::IntRect(map[i][j].x * 16, map[i][j].y * 16, 16,16)); // set the right texture
                    window.draw(sprite); // draw the map
                
            }
        }
}

const std::vector<sf::Vector2i>& Map::get_path() { // get the path tiles
    return path_tiles;
}