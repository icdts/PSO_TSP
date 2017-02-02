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
  //std::cout << "  Inside += position before: " << this->to_string() << std::endl;
    for(int i = 0; i < v.size; i++){
        Node tmp = nodes[v.from[i]];
        nodes[v.from[i]] = nodes[v.to[i]];
        nodes[v.to[i]] = tmp;
    }
  //std::cout << "  Inside += position after: " << this->to_string() << std::endl;
}

Position Position::operator+(const Velocity &v){
  Position ret(*this);
  ret += v;
  return ret;
}

Velocity Position::operator-(const Position &p){
    Velocity difference;
  Position tmp_pos(p);

    for(int i = 0; i < this->nodes.size(); i++){
        Node look_for = this->nodes[i];
        int found_at = -1;
        for(int j = 0; j < tmp_pos.nodes.size(); j++){
            if(tmp_pos.nodes[j] == look_for){
                found_at = j;

        Node tmp = p.nodes[i];
        tmp_pos.nodes[i] = tmp_pos.nodes[j];
        tmp_pos.nodes[j] = tmp;
                break;
            }
        }

        if( i != found_at && found_at != -1 ){
            difference.add_transposition(i,found_at);
        }
    }

    return difference;
}

Position& Position::add_node(Node new_n){
  this->nodes.push_back(new_n);
  return *this;
}

std::string Position::to_string(){
  std::stringstream ss;

  ss << "(";
  ss << this->nodes[0].index;
  for(int i = 1; i < this->nodes.size(); i++){
    ss << ", " << this->nodes[i].index;
  }
  ss << ")";

  return ss.str();
}
