#include "swarm.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

void print_velocity(Velocity v, std::string name);
void print_position(Position p, std::string name);

int main(int argc, char* argv[]){
  if( argc == 6){
    //Read args
    std::stringstream args;

    for(int i = 1; i < argc; i++){
      args << argv[i] << " ";
    }

    std::string filename;
    int particle_count;
    double self_trust;
    double past_trust;
    double global_trust;

    args >> filename;
    args >> particle_count;
    args >> self_trust;
    args >> past_trust;
    args >> global_trust;

    //Run optimization
    double val;
    //srand(time(0));

    Swarm s(particle_count,self_trust,past_trust,global_trust);

    std::string name(argv[1]);
    s.read_graph_definition("/home/robb/workspace/ai/PSO_TSP/tests/" + name);

    val = s.solve();
    std::cout << val << std::endl;
  }else{
    std::cout << "Invalid args.  Usage:" << std::endl;
    std::cout << "  pso_opt <filename> <particle_count> <self_trust> <past_trust> <global_trust>" << std::endl;
  }
  return 0;
}

void print_position(Position p, std::string name){
  std::cout << name << " is:" << std::endl;
  std::cout << "  (" << p.nodes[0].index;
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
