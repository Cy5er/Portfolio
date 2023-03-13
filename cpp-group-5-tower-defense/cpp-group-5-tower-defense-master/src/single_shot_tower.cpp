//Implementation file for of single_shot_tower class
//Include internal files
#include "single_shot_tower.hpp"

single_shot_tower::single_shot_tower(int tower_type, double fr, double rng) // constructor
: base_tower(tower_type,fr,rng) {
    cooldown = false;
}