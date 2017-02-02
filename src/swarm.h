#include "particle.h"
#include "node.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#ifndef SWARM
#define SWARM

class Swarm{
public:
  Swarm(int particle_count, float self_trust, float past_trust, float global_trust);

  void read_graph_definition(std::string filename);
  double solve();

  std::vector<Particle> particles;
  std::vector<Node> nodes;
  double best_value;
  Position best_position;
private:
  bool normal_search();
  bool lazy_descent();
  bool energetic_descent();

  void particles_back_to_best();
  bool move_all_slowly();


  Swarm();//shouldn't be using this
  std::string trim(std::string);
  void assign_particle_positions();
  Position shuffle();

  double self_trust;
  double past_trust;
  double global_trust;
  int particle_count;
};

#endif
