//Implementation file of our base tower class
#include "base_tower.hpp"

base_tower::base_tower(int tower_type_, double fr, double rng)
    : tower_type(tower_type_), firerate(fr), range(rng) {}