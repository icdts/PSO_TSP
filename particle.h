#include "velocity.h"
#include "position.h"
#include <climits>

#ifndef PARTICLE
#define PARTICLE

class Particle{
public:
	Particle();
	Particle(Position p, Velocity v);

    int move();  //Move based on velocity, return best value seen
    int calculate_value();  //Get sum of wieghts of the edges we're using
    Velocity velocity;
    Position position;
    Position best_found;
    int best_value;
};

#endif
