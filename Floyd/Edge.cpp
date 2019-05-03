#include <string>
#include <vector>
#include "Edge.h"

using namespace std;

Edge::Edge() {}

Edge::Edge(string _fr_, string _to_, double _wet_) {
	fr = _fr_;
	to = _to_;
	wet = _wet_;
}

string Edge::get_fr() const {
	return fr;
}

string Edge::get_to() const {
	return to;
}

double Edge::get_wet() const {
	return wet;
}

void Edge::set_fr(string _fr_) {
	fr = _fr_;
}

void Edge::set_to(string _to_) {
	to = _to_;
}

void Edge::set_wet(double _wet_) {
	wet = _wet_;
}

ostream& operator<<(ostream& os, Edge& edge)
{
	os << edge.get_fr() << ' ' << edge.get_to() << ' ' << edge.get_wet();
	return os;
}


