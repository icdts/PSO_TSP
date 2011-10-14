#include "velocity.h"
#include <vector>

#ifndef POSITION
#define POSITION

class Position{
public:
	Position();
	Position(const Position &p);
	Position& operator=(const Position & rhs);
	Position& operator+=(const Velocity & rhs);
	Position& operator+(const Velocity & rhs);
	Velocity operator-(const Position &p);
	Position& add_node(int new_n);
    std::vector<int> nodes;
};

#endif
