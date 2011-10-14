#include "position.h"
#include <iostream>

Position::Position(){}
Position::Position(const Position& p){
	for(int i = 0; i < p.nodes.size(); i++){
		this->add_node(p.nodes[i]);
	}
}

Position& Position::operator=(const Position &rhs){
	if(this != &rhs){
		this->nodes.clear();

		for(int i = 0; i < rhs.nodes.size(); i++){
			this->add_node(rhs.nodes[i]);
		}
	}
	return *this;
}

Position& Position::operator+=(const Velocity &v){
    for(int i = 0; i < v.size; i++){
        int tmp = nodes[v.from[i]];
        nodes[v.from[i]] = nodes[v.to[i]];
        nodes[v.to[i]] = tmp;
    }
}

Position& Position::operator+(const Velocity &v){
	return (Position(*this) += v);
}

Velocity Position::operator-(const Position &p){
    Velocity difference;
	Position tmp_pos(p);

    for(int i = 0; i < this->nodes.size(); i++){
        int look_for = this->nodes[i];
        int found_at = -1;
        for(int j = 0; j < tmp_pos.nodes.size(); j++){
            if(tmp_pos.nodes[j] == look_for){
                found_at = j;

				int tmp = p.nodes[i];
				tmp_pos.nodes[i] = tmp_pos.nodes[j];
				tmp_pos.nodes[j] = tmp;
                break;
            }
        }

        if( i != found_at && found_at != -1 ){
            difference.add_transposition(i,found_at);
        }
    }

	std::cout << "End of sub" << std::endl;
    return difference;
}

Position& Position::add_node(int new_n){
	this->nodes.push_back(new_n);
	return *this;
}
