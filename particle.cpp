#include "particle.h"
#include <iostream>

Particle::Particle(){
	this->best_value = INT_MAX;
}

Particle::Particle(Position p, Velocity v){
	this->position = p;
	this->velocity = v;
	this->best_value = INT_MAX;
}

int Particle::move(){
    position += velocity;

    int new_value = this->calculate_value();
    if(new_value < this->best_value){
        this->best_value = new_value;
    }
	
    return this->best_value;
}

int Particle::calculate_value(){
    int value = 0;
	int node_count = this->position.nodes.size();

    for(int i = 0; i < node_count; i++){
        Node tmp = this->position.nodes[i];
		Node tmp2;

		if( i+1 < node_count ){
			Node tmp2 = this->position.nodes[i+1];
		}else{
			Node tmp2 = this->position.nodes[0];
		}

		value += tmp.distance_to(tmp2);
    }

    return value;
}
