#include <string>
#include <vector>
#include "disjoint.h"

using namespace std;

void makeset(int i, vector<int> &U)
{
	U[i] = i;
}

int find(int i, vector<int>&U)
{
	int j = i;
	while (U[j] != j)
		j = U[j];
	return j;
}
void merge(int p, int q, vector<int>&U)
{
	if (p < q)U[q] = p;
	else U[p] = q;
}
bool equal(int p, int q) {
	return p == q;
}
vector<int>initial(map<string, int>nodes)
{
	vector<int> U(nodes.size());
	for (int i = 0; i < nodes.size(); i++)
	{
		makeset(i, U);
	}
	return U;
}
