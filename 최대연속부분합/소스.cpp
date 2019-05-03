#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<sstream>
using namespace std;

vector<int>int_token;
vector<int>fin;
int maxx = 0;
int n;

void find_max(int total, vector<int> & sublist)
{
	maxx = total;
	fin.clear();
	for (int i = 0; i < sublist.size(); i++)
		fin.push_back(sublist[i]);
}
void dfs(int st, int end, vector<int> &sublist, int total)
{
	if (st >= end) {
		if (maxx < total)find_max(total, sublist);
		return;
	}
	sublist.push_back(int_token[st]);
	total += int_token[st];
	dfs(st + 1, end, sublist, total);
	sublist.pop_back();
	total -= int_token[st];
	if (maxx < total) {
		if (maxx < total)find_max(total, sublist);
		return;
	}
}
void print()
{
	ofstream out_line;
	ofstream out("output.txt");
	out << maxx << " ";
	out << "(";
	for (int i = 0; i < fin.size(); i++)
		if (i == fin.size() - 1)out << fin[i];
		else out << fin[i] << " + ";
		out << ")";
		out.close();
}
void solve()
{
	for (int i = 0; i < n; i++)
	{
		vector<int>sublist;
		dfs(i, n, sublist, 0);
	}
}
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}
vector<int>trans_2_int(vector<string>str)
{
	vector<int> v;
	for (int i = 0; i < str.size(); i++)v.push_back(atoi(str[i].c_str()));
	return v;
}

void input()
{
	ifstream in("input.txt");
	string in_line;
	getline(in, in_line);
	vector<string>token = split(in_line, ' ');
	int_token = trans_2_int(token);
	n = int_token.size();
	in.close();
}
int main()
{
	input();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	print();
	return 0;
}