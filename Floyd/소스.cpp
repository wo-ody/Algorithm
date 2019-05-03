#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <climits>
#include "Tokenizer.h"
#include "Edge.h"
#include "trim.h"

using namespace std;

const string DELMIT = " -> ";

template<typename T>
void print_element(T st)
{
	cout << st.get_name() << "\t" << st.get_come() << endl;
}

vector<Edge> read_edges(char *fName);

vector<string> make_node_index(vector<Edge> edges);

bool is_nodes(string node, vector<string> nodes);

vector<vector<double>> makeGraph(vector<string> nodes);

void setGraphW(vector<Edge> edges, vector<string> nodes, vector<vector<double>> &W);

int index(string node, vector<string> nodes);

void setGraphD(vector<string> nodes, vector<vector<double>> W, vector<vector<double>> &D, vector<vector<int>> &P);

vector<vector<int>> make_matrix(vector<string>nodes);

void path(vector<vector<int>> P, vector<string> nodes, int i, int j);


int main()
{
	char *fName = "edges.txt";


	vector<Edge> edges = read_edges(fName);

	for (int i = 0; i < edges.size(); i++)
	{
		cout << "fr :" << edges[i].get_fr() << "\t" << "to :" << edges[i].get_to() << "\t" << "wet :" << edges[i].get_wet() << endl;
	}


	vector<string> nodes = make_node_index(edges);

	for (int i = 0; i < nodes.size(); i++)
	{
		cout << nodes[i] << "\t" << endl;
	}

	vector<vector<double>> W = makeGraph(nodes);
	setGraphW(edges, nodes, W);

	for (int i = 0; i < W.size(); i++)
	{

		cout << endl;
		for (int j = 0; j < W[i].size(); j++)
		{
			cout << ", " << W[i][j];
		}
		cout << endl;
	}

	cout << endl << endl;
	vector<vector<double>> D = W;
	vector<vector<int >> P = make_matrix(nodes);

	setGraphD(nodes, W, D, P);

	for (int i = 0; i < D.size(); i++)
	{
		for (int j = 0; j < D[i].size(); j++)
		{
			cout << ", " << D[i][j];
		}
		cout << endl;
	}

	cout << endl;
	int i, j;
	for (i = 0; i < P.size(); i++) {
		for (j = 0; j < P.size(); j++) {
			if (i == j) continue;
			cout << nodes[i] << DELMIT;  // 시작 노드
			path(P, nodes, i, j);
			cout << nodes[j] << endl;          // 종료 노드
		}
	}


	getchar();
	getchar();
	return 0;
}


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

vector<string> make_node_index(vector<Edge> edges)
{
	vector<string> nodes;

	for (int i = 0; i < edges.size(); i++)
	{
		string fr = edges[i].get_fr();
		string to = edges[i].get_to();

		if (!is_nodes(fr, nodes))
		{
			nodes.push_back(fr);
		}
		if (!is_nodes(to, nodes))
		{
			nodes.push_back(to);
		}
	}

	return nodes;
}

bool is_nodes(string node, vector<string> nodes)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (node == nodes[i])
			return true;
	}
	return false;
}

vector<vector<double>> makeGraph(vector<string> nodes)
{
	vector <vector <double>> matrix;
	int nrow;
	int ncol;
	nrow = ncol = nodes.size();
	for (int i = 0; i < nrow; i++)
	{
		vector <double> row(ncol, DBL_MAX);
		matrix.push_back(row);
	}
	return matrix;
}

void setGraphW(vector<Edge> edges, vector<string> nodes, vector<vector<double>> &W)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		W[i][i] = 0;
	}
	for (int j = 0; j < edges.size(); j++)// edges 돌리는거
	{
		int i = index(edges[j].get_fr(), nodes);
		int k = index(edges[j].get_to(), nodes);
		W[i][k] = edges[j].get_wet();
	}
}

int index(string node, vector<string> nodes)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i] == node)
		{
			return i;
		}
	}
}

void setGraphD(vector<string> nodes, vector<vector<double>> W, vector<vector<double>> &D, vector<vector<int>> &P)
{
	int i;
	int j;
	int k;
	int n = nodes.size();
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j])
				{
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

vector<vector<int >> make_matrix(vector<string>nodes)
{
	vector <vector <int>> matrix;
	int nrow;
	int ncol;
	nrow = ncol = nodes.size();
	for (int i = 0; i < nrow; i++)
	{
		vector <int> row(ncol);
		matrix.push_back(row);
	}

	return matrix;
}

void path(vector<vector<int>> P, vector<string> nodes, int i, int j)
{
	if (P[i][j] != 0)
	{
		path(P, nodes, i, P[i][j]);
		cout << nodes[P[i][j]] << DELMIT;
		path(P, nodes, P[i][j], j);
	}
}