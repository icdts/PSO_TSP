#include "swarm.h"
#include <iostream>
#include <string>
#include <cstdlib>

void print_velocity(Velocity v, std::string name);
void print_position(Position p, std::string name);

int main(int argc, char* argv[]){
	double val;

	srand(time(0));

	Swarm s(100,0.2,0.4,0.4);
	std::cout << "Reading graph " << argv[1] << std::endl;

	std::string name(argv[1]);
	s.read_graph_definition("/home/rnolan/workspace/ai/PSO_TSP/tests/" + name);

	std::cout << "Done, solving." << std::endl;
	val = s.solve();
	std::cout << "Done.  Result: " << val << std::endl;

	return 0;
}

void print_position(Position p, std::string name){
	std::cout << name << " is:" << std::endl;
	std::cout << "	(" << p.nodes[0].index;
	for(int i = 1; i < p.nodes.size(); i++){
		std::cout << ", " << p.nodes[i].index;
	}
	std::cout << ")" << std::endl;
}

void print_velocity(Velocity v, std::string name){
    std::cout << name << " has:" << std::endl;
    for(int i = 0; i < v.size; i++){
        std::cout << "   (" << v.from[i] << ", " << v.to[i] << ")" << std::endl;
    }
}
