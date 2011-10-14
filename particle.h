#include "velocity.h"
#include "position.h"

#ifndef PARTICLE
#define PARTICLE

class Particle{
public:
    int move(int** adjacency_matrix, int null_weight);  //Move based on velocity, return best value seen
    int calculate_value(int** adjacency_matrix, int node_count, int null_weight);  //Get sum of wieghts of the edges we're using
    Velocity velocity;
    Position position;
    Position best_found;
    int best_value;
};

#endif
