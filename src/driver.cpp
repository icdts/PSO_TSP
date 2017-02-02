#include "swarm.h"
#include <iostream>

int main(){
  Swarm swarm(10, 0.2, 0.3, 0.4);

  swarm.read_graph_definition("graph.tsp");

  std::cout << swarm.solve() << std::endl;

  return 0;
}
