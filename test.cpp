#include "position.h"
#include <iostream>
#include <string>

void print_velocity(Velocity v, std::string name);
void print_position(Position p, std::string name);

int main(){
    Velocity a,b;

    a.add_transposition(0,1);
    a.add_transposition(2,0);

	Position p,q;

	for(int i = 0; i < 10; i++){
		p.add_node(i);
	}

	for(int i = 9; i >= 0; i--){
		q.add_node(i);
	}

	print_position(p,"p");

	p += a;

	print_position(p,"p");
	print_position(q,"q");

	a = p-q;
	b = a;
	b *= -1;

	q += a;
	p += (a * -1);
	print_velocity(a,"p-q");
	print_velocity(b,"p-q negated");

	print_position(p,"p");
	print_position(q,"q");


    return 0;
}

void print_position(Position p, std::string name){
	std::cout << name << " is:" << std::endl;
	std::cout << "	(" << p.nodes[0];
	for(int i = 1; i < p.nodes.size(); i++){
		std::cout << ", " << p.nodes[i];
	}
	std::cout << ")" << std::endl;
}

void print_velocity(Velocity v, std::string name){
    std::cout << name << " has:" << std::endl;
    for(int i = 0; i < v.size; i++){
        std::cout << "   (" << v.from[i] << ", " << v.to[i] << ")" << std::endl;
    }
}
