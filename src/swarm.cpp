#include "swarm.h"

Swarm::Swarm(int particle_count, float self_trust, float past_trust, float global_trust){
	this->particle_count = particle_count;
	this->self_trust = self_trust;
	this->global_trust = global_trust;
}

void Swarm::read_graph_definition(std::string filename){
	std::ifstream graph_file;
	std::string line;
	int index;
	double real;

	this->nodes.clear();

	graph_file.open(filename.c_str());
	if(graph_file.is_open()){
		//std::cout << "File is open" << std::endl;
		while(graph_file.good()){
			getline(graph_file,line);
			std:: cout << "	" << line << std::endl;
			//First find NODE_COORD_SECTION
			line = trim(line);

			if( line == "NODE_COORD_SECTION" ){
				break;
			}
		}
		//std::cout << "Found NODE_COORD_SECTION" << std::endl;

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
				
				//std::cout << "	Read node: (" << n.index << ", " << n.x << ", " << n.y << ")" << std::endl;
				this->nodes.push_back(n);
			}
		}
	}else{
		std::cout << "Could not open file" << std::endl;
		throw(-1);
	}

	//std::cout << "Assign particle Positions" << std::endl;
	assign_particle_positions();
}

void Swarm::assign_particle_positions(){
	//std::cout << "Clear current particles" << std::endl;
	this->particles.clear();
	for(int i = 0; i < this->particle_count; i++ ){	
		//std::cout << "Create particle " << i << std::endl;
		this->particles.push_back( Particle(this->self_trust, this->past_trust, this->global_trust) );

		this->particles[i].position = shuffle();
		//std::cout << "	Picked position: " << this->particles[i].position.to_string() << std::endl;

		///std::cout << "	Calculate Value" << std::endl;
		double cur_value = this->particles[i].calculate_value();

		//std::cout << "	Best Value check" << std::endl;
		if(i==0 || this->best_value > cur_value){
			this->best_value = cur_value;
			this->best_position = this->particles[i].position;
		}
		//std::cout << "Done with " << i << std::endl;
	}
}

double Swarm::solve(){
	int moves_since_best_changed = 0;
	double tmp;

	while(moves_since_best_changed < 4){
		bool best_changed = false;

		for(int i = 0; i < this->particles.size(); i++){
			this->particles[i].calculate_new_velocity(this->best_position);

			tmp = this->particles[i].move();
			if(this->best_value > tmp){
				this->best_value = tmp;
				this->best_position = this->particles[i].position;
				moves_since_best_changed = 0;
				best_changed = true;
			}
		}
		if(!best_changed){
			moves_since_best_changed++;
		}
	}
	return this->best_value;
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
