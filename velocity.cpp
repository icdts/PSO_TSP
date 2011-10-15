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
    if( 0 == d){
        this->from.clear();
        this->to.clear();
        this->size = 0;
    }else{
        int size = this->size;
        if( 0 > d ){
            d = d * -1;
			std::reverse(this->from.begin(), this->from.end());
			std::reverse(this->to.begin(), this->to.end());
        }
        if( 0 < d ){
            while( d >= 2 ){
                for(int i = 0; i < size; i++){
                    this->add_transposition(this->from[i],this->to[i]);
                }
                d--;
            }

			if(d >= 1){d--;}

            if( d > 0 ){
                int cv = size * d;
                for(int i = 0; i < cv; i++){
                    this->add_transposition(this->from[i],this->to[i]);
                }
            }
        }
    }
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
