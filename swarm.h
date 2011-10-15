#include <particle>

#ifndef SWARM
#define SWARM

class Swarm{
public:
	Swarm(int particle_count, float self_trust, float past_trust, float global_trust);

    vector<Particle> particles;
    int node_count;
    int** adjacency_matrix;
private:
	Swarm();//shouldn't be using this
}

#endif
