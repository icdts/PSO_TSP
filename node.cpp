#include "node.h"

Node::Node(){
	this->index = -1;
	this->x = 0;
	this->y = 0;
}

Node::Node(int _index, double _x, double _y){
    this->index = _index;
    this->x = _x;
    this->y = _y;
}

bool Node::operator==(const Node &rhs){
	if(this->index == rhs.index){
		return true;
	}
	return false;
}

double Node::distance_to(const Node &other){
   return std::sqrt((x*x) + (y*y));
}
