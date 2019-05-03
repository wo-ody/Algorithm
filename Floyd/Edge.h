#ifndef EDGE_H
#define EDGE_H
#include <string>
#include <vector>

using namespace std;

class Edge {
public:
	Edge();									// default constructor 
	Edge(string fr, string to, double wet); // constructor
	string get_fr() const;
	string get_to() const;
	double get_wet() const;
	void set_fr(string fr);
	void set_to(string to);
	void set_wet(double wet);
private:
	string fr;		// source node
	string to;		// destination node
	double wet;		// weight
};
ostream& operator<<(ostream& os, Edge& edge);
#endif
