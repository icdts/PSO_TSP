#include <vector>
#include <algorithm>

#ifndef VELOCITY
#define VELOCITY

class Velocity{
public:
    Velocity();
	Velocity(const Velocity &v);
	Velocity(std::vector<int> _from, std::vector<int> _to);

    Velocity& operator=(const Velocity &rhs);
    Velocity& operator*=(const double &rhs);
    Velocity& operator+=(const Velocity &rhs);
    Velocity operator*(const double &rhs);
    Velocity operator+(const Velocity &rhs);

    void add_transposition(int a, int b);
    void remove_transposition(int index);

    int size;
    std::vector<int> from;
    std::vector<int> to;
};

#endif
