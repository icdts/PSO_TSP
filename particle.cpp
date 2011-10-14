#include "particle.h"

int Particle::move(int** adjacency_matrix, int null_weight){
    position += velocity;

    int new_value = this->calculate_value(adjacency_matrix, position.nodes.size(), null_weight);
    if(new_value < this->best_value){
        this->best_value = new_value;
    }

    return this->best_value;
}

int Particle::calculate_value(int** adjacency_matrix, int node_count, int null_weight){
    int value = 0;
    for(int i = 0; i < node_count; i++){
        int tmp;
        if( i+1 < node_count){
            tmp = position.nodes[i+1];
        }else{
            tmp = position.nodes[0];
        } 

        tmp = adjacency_matrix[ position.nodes[i] ][ tmp ];
        if(0 != tmp){
            value += tmp;
        }else{
            value += null_weight;
        }
    }
    return value;
}
