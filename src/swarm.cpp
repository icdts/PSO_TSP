#include "swarm.h"

Swarm::Swarm(int particle_count, float self_trust, float past_trust, float global_trust){
  this->particle_count = particle_count;
  this->self_trust = self_trust;
  this->past_trust = past_trust;
  this->global_trust = global_trust;
}

double Swarm::solve(){
  int moves_since_best_changed = 0;

  while(moves_since_best_changed <= 4){
    bool best_changed = false;

    if( moves_since_best_changed < 2 ){
      best_changed = normal_search();
    }else{
      if( moves_since_best_changed < 4 ){
        best_changed = lazy_descent();
      }else{
        best_changed = energetic_descent();
      }
    }
    if(!best_changed){
      moves_since_best_changed++;
    }else{
      moves_since_best_changed = 0;
    }
    //std::cout << "Best value so far: " << this->best_value << std::endl;
  }
  return this->best_value;
}


bool Swarm::normal_search(){
  bool best_changed = false;
  double tmp;
  for(int i = 0; i < this->particles.size(); i++){
    this->particles[i].calculate_new_velocity(this->best_position);

    tmp = this->particles[i].move();
    if(this->best_value > tmp){
      this->best_value = tmp;
      this->best_position = this->particles[i].position;
      best_changed = true;
    }
  }

  return best_changed;
}

bool Swarm::lazy_descent(){
  bool best_changed = false;
  int maximum_moves = this->nodes.size();

  //Move all particles to their last best position
  particles_back_to_best();  

  //Search around their best's, moving slowly.  Stop if best changes.
  int count = 0;
  while( count < maximum_moves && !best_changed ){
    best_changed = move_all_slowly();  
    count++;
  }

  return best_changed;
}

bool Swarm::energetic_descent(){
  bool best_changed = true;
  int maximum_moves = this->nodes.size();

  //Move all particles to their last position
  particles_back_to_best();

  //Move slowly around bests as long as we find a better solution in
    //under maximum_moves
  while(best_changed){
    best_changed = false;
    for(int i = 0; i < maximum_moves; i++){
      best_changed = move_all_slowly();
    }
  }

  return best_changed;
}

void Swarm::particles_back_to_best(){
  for(int i = 0; i < this->particles.size(); i++){
    this->particles[i].position = this->particles[i].best_position;
  }
}

bool Swarm::move_all_slowly(){
  bool best_changed = false;
  for(int i = 0; i < this->particles.size(); i++){
    Velocity v;
    int a = rand() % this->nodes.size();
    int b = rand() % this->nodes.size();

    v.add_transposition(a,b);
    this->particles[i].velocity = v;
    double val = this->particles[i].move();

    if( val < this->best_value ){
      this->best_value = val;
      this->best_position = this->particles[i].position;
      best_changed = true;
    }
  }
  return best_changed;
}

void Swarm::read_graph_definition(std::string filename){
  std::ifstream graph_file;
  std::string line;
  int index;
  double real;

  this->nodes.clear();

  graph_file.open(filename.c_str());
  if(graph_file.is_open()){
    while(graph_file.good()){
      getline(graph_file,line);
      //std:: cout << "  " << line << std::endl;
      //First find NODE_COORD_SECTION
      line = trim(line);

      if( line == "NODE_COORD_SECTION" ){
        break;
      }
    }

    //Read in nodes
    while(graph_file.good()){
      Node n;

      getline(graph_file,line);

      std::istringstream iss(line, std::istringstream::in);
      iss >> n.index;
      iss >> n.x;
      iss >> n.y;

      //Check for invalid line
      if(n.index > 0){
        n.index--; //We index from 0, file indexes from 1

        this->nodes.push_back(n);
      }
    }
  }else{
    std::cout << "Could not open file: " << filename << std::endl;
    throw(-1);
  }

  assign_particle_positions();
}

void Swarm::assign_particle_positions(){
  this->particles.clear();
  for(int i = 0; i < this->particle_count; i++ ){  
    this->particles.push_back( Particle(this->self_trust, this->past_trust, this->global_trust) );

    this->particles[i].position = shuffle();

    double cur_value = this->particles[i].calculate_value();

    if(i==0 || this->best_value > cur_value){
      this->best_value = cur_value;
      this->best_position = this->particles[i].position;
    }
  }
}

Position Swarm::shuffle(){
  Position p;
  std::vector<Node> new_vec(this->nodes);

  //Knuth-Fisher-Yates shuffle
  for(int i = new_vec.size() - 1; i > 0; i--){
    int n = rand() % (i + 1);
    Node tmp = new_vec[i];
    new_vec[i] = new_vec[n];
    new_vec[n] = tmp;
  }

  p.nodes = new_vec;
  return p;
}

std::string Swarm::trim(std::string s){
  s.erase(0,s.find_first_not_of(" \t"));
  s.erase(s.find_last_not_of(" \t")+1);
  return s;
}
