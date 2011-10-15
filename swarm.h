#include "particle.h"
#include "node.h"
#include <string>

#ifndef SWARM
#define SWARM

class Swarm{
public:
	Swarm(int particle_count, float self_trust, float past_trust, float global_trust);

	void read_graph_definition(string filename);
	string solve();

    vector<Particle> particles;
	vector<Node> nodes;
    int node_count;
    int** adjacency_matrix;
private:
	Swarm();//shouldn't be using this
}

#endif
