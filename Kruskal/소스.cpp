#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Tokenizer.h"
#include "Edge.h"
#include "trim.h"
#include "disjoint.h"

using namespace std;

const string DELMIT = " -> ";

template<typename T>
void print_element(T st)
{
	cout << st.get_name() << "\t" << st.get_come() << endl;
}

vector<Edge> read_edges(char *fName);
map<string, int> make_node(vector<Edge> edges);
void set_index(string vertex, int &index, map<string, int>&nodes);
int index(string node, vector<string> nodes);
vector<vector<int>> make_matrix(vector<string>nodes);
vector<Edge> kruscal(vector<Edge> edges, map<string, int> nodes);
void print_edges(vector<Edge> nodes);

int main()
{
	char *fName = "C:\\Users\\shmon\\Documents\\Visual Studio 2017\\Projects\\Project11\\edges.txt";
	vector<Edge> edges = read_edges(fName);
	//print_egdes(edges);함수 짜기

	map<string, int> nodes = make_node(edges);//make_node -> map

	vector<Edge> F = kruscal(edges, nodes);
	print_edges(F);

	return 1;

}//main


vector<Edge> read_edges(char *fName)
{
	ifstream fin(fName);
	string buf;
	Tokenizer str;
	string fr, to;
	float wet;
	vector<Edge> edges;

	while (getline(fin, buf)) {
		str.set(buf, "#");
		fr = trim(str.next());
		to = trim(str.next());
		string tmp = trim(str.next());
		wet = atof(tmp.c_str());
		edges.push_back(Edge(fr, to, wet));
	}
	return edges;
}

map<string, int> make_node(vector<Edge> edges)
{
	map<string, int> nodes;
	map<string, int>::iterator it;
	int index = 0;
	for (int i = 0; i < edges.size(); i++) {
		set_index(edges[i].get_fr(), index, nodes);//똑같은 vertex 넘기는 작업
		set_index(edges[i].get_to(), index, nodes);
	}
	return nodes;
}

void set_index(string vertex, int &index, map<string, int>&nodes)
{
	map<string, int>::iterator it;
	it = nodes.find(vertex);

	if (it == nodes.end())//끝까지 감
	{
		nodes[vertex] = index;
		index++;
	}

}

void print_nodes(map<string, int>&nodes)
{
	map<string, int>::iterator it;
	for (it = nodes.begin(); it != nodes.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}

void print_edges(vector<Edge> nodes)
{
	for (int i = 0; i < nodes.size(); i++)  
		cout << i << " " << nodes[i] << endl;
}

template <class T1>
void print_vector(vector<T1>& V) {

	int i;
	cout << "---------------------------------" << endl;
	for (i = 0; i < V.size(); i++)  cout << i << " " << V[i] << endl;
}

vector<Edge> kruscal(vector<Edge> edges, map<string, int> nodes)
{
	sort(edges.begin(), edges.end());
	vector<Edge> F;

	vector<int> U = initial(nodes);
	int n = nodes.size();
	int k = 0;
	while (F.size() < n - 1)
	{
		Edge e = edges[k]; k++;
		int i = nodes[e.get_fr()];
		int j = nodes[e.get_to()];
		int p = find(i, U);
		int q = find(j, U);
		if (!equal(p, q)) {
			merge(p, q, U);
			F.push_back(e);
		}
	}
	return F;
}

