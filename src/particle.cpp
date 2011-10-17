#include "particle.h"
#include <iostream>

Particle::Particle(double self_trust,double past_trust,double global_trust){
	this->self_trust = self_trust;
	this->past_trust = past_trust;
	this->global_trust = global_trust;
	this->best_value = -1;
}

double Particle::move(){
	//std::cout << "Velocity: " << velocity.to_string() << std::endl;
    position += velocity;
	//std::cout << "New position: " << position.to_string() << std::endl;

    double new_value = this->calculate_value();
	//std::cout << new_value << std::endl;
    if(new_value < this->best_value || this->best_value < 0){
        this->best_value = new_value;
		this->best_position = position;
    }
	
    return this->best_value;
}

double Particle::calculate_value(){
    double value = 0;

	int node_count = this->position.nodes.size();

    for(int i = 0; i < node_count; i++){
        Node tmp = this->position.nodes[i];
		Node tmp2;

		if( i+1 < node_count ){
			tmp2 = this->position.nodes[i+1];
		}else{
			tmp2 = this->position.nodes[0];
		}
		double tmp_val = tmp.distance_to(tmp2);
		value += tmp_val;
    }
    return value;
}

void Particle::calculate_new_velocity(Position global_best){
	Velocity a; 
	if(this->velocity.size > 0){
		a = (this->velocity * this->self_trust);
	}
	Velocity b = ((this->best_position-this->position) * this->past_trust);
	Velocity c = ((global_best-this->position) * this->global_trust);

	//std::cout << a.to_string();
	this->velocity =  Velocity(a + b + c);
}
