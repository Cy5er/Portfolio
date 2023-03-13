//Header file for our three_hit monster class
//Include external libraries
#include <SFML/Graphics.hpp>

//Include internal files
#include "base_monster.hpp"

class two_hit : public base_monster {
    
    public:
        two_hit(std::string name, size_t hp);
        two_hit(std::string name, size_t hp, sf::Vector2f position); // constructor with a specific position
        ~two_hit();
        void render(sf::RenderWindow &window); // render the monster
        void update(std::vector<float> xx , std::vector<float> yy, int count); // update the state of the monster
        void offset(); // get all the offsets the monster needs to move by
        void get(sf::Vector2i map[50][50], int x, int y); // get all the path tiles the monster needs to visit
        float xoff, yoff;
        std::vector<std::pair<float,float>> getTo_;
        sf::RectangleShape body;

};