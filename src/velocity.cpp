#include "velocity.h"
#include <iostream>

Velocity::Velocity(){
    this->size = 0;
}

Velocity::Velocity(const Velocity &v){
  this->size = 0;
  for(int i = 0; i < v.size; i++){
    this->add_transposition(v.from[i], v.to[i]);
  }
}

Velocity::Velocity(std::vector<int> _from, std::vector<int> _to){
  this->size = 0;
  for(int i = 0; i < _from.size(); i++){
    this->add_transposition(_from[i],_to[i]);
  }
}

Velocity& Velocity::operator=(const Velocity &rhs){
    //self assignment check
    if(this != &rhs){
        //deallocate everything
        this->to.clear();
        this->from.clear();
        this->size = 0;

        //copy values
        for(int i = 0; i < rhs.size; i++){
            this->add_transposition(rhs.from[i], rhs.to[i]);
        }
    }
    return *this;
}

Velocity& Velocity::operator+=(const Velocity &rhs){
    for(int i = 0; i < rhs.size; i++){
        this->add_transposition(rhs.from[i], rhs.to[i]);
    }
    return *this;
}

Velocity& Velocity::operator*=(const double &rhs){
    double d = rhs;
  //std::cout << "d: " << d << std::endl;
  std::vector<int> from(this->from);
  std::vector<int> to(this->to);

  this->from.clear();
  this->to.clear();
  int size = this->size;
  this->size = 0;

    if( 0 != d){
        if( 0 > d ){
      //std::cout << "d: is negative " << std::endl;
            d = d * -1;
      std::reverse(from.begin(), from.end());
      std::reverse(to.begin(), to.end());
        }

        if( 0 < d ){
            while( d >= 2 ){
                for(int i = 0; i < size; i++){
                    this->add_transposition(from[i],to[i]);
                }
                d--;
        //std::cout << "subbed d: " << d << std::endl;
            }

      if(d >= 1){d--;}

            if( d > 0 ){
                int cv = ceil(d* size);
        //std::cout << "cv: " << cv << std::endl;
                for(int i = 0; i < cv; i++){
                    this->add_transposition(from[i],to[i]);
                }
            }
        }
    }

  return *this;
}

Velocity Velocity::operator*(const double &rhs){
  Velocity ret(*this);
  ret *= rhs;
  return ret;
}

Velocity Velocity::operator+(const Velocity &rhs){
  Velocity ret(*this);
  ret += rhs;
    return ret;
}

void Velocity::remove_transposition(int index){
    this->size -= 1;
    this->from.erase(this->from.begin() + index);
    this->to.erase(this->to.begin() + index);
}

void Velocity::add_transposition(int a, int b){
    this->size += 1;
    this->from.push_back(a);
    this->to.push_back(b);
}

std::string Velocity::to_string(){
  std::stringstream ss;

  ss << "(";
  if( this->size > 0 ){
    ss << "(" << this->from[0] << ", " << this->to[0] << ")"; 
    for(int i = 1; i < this->size; i++){
      ss << ", (" << this->from[i] << ", " << this->to[i] << ")"; 
    }
  }
  ss << ")";

  return ss.str();
}
