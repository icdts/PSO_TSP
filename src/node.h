#ifndef NODE
#define NODE

#include <cmath>
#include <iostream>

class Node{
public:
  Node(int _index, double _x, double _y);
  bool operator==(const Node &rhs);

  int index;
  double x;
  double y;
  double distance_to(const Node &other);
  Node();
};

#endif
