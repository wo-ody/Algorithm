#ifndef DISJOINT_H
#define DISJOINT_H
#include <iostream>
#include<vector>
#include <map>
using namespace std;

void makeset(int i, vector<int> &U);
int find(int i, vector<int>&U);
void merge(int p, int q, vector<int>&U);
bool equal(int p, int q);
vector<int>initial(map<string, int>nodes);

#endif