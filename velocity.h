#include <vector>
#include <algorithm>

class Velocity{
public:
    Velocity();
	Velocity(const Velocity &v);
    Velocity& operator=(const Velocity &rhs);
    Velocity& operator+=(const Velocity &rhs);
    Velocity& operator*=(const double &rhs);
    Velocity& operator+(const Velocity &rhs);
    Velocity& operator*(const double &rhs);

    void add_transposition(int a, int b);
    void remove_transposition(int index);

    int size;
    std::vector<int> from;
    std::vector<int> to;
};
