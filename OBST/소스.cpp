#include "Key.h"
#include "Tokenizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct Node {
	Key key;
	Node* left;
	Node* right;
}Node;

string readFile(string fname) {
	ifstream file(fname.data());
	string result;

	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			result = result + line + "\n";
		}
		file.close();
		return result;
	}
}



vector<string> readData(string fname) {
	vector<string> result;
	Tokenizer str;
	string token;

	str.set(readFile(fname), "\n");

	while ((token = str.next()) != "") {
		result.push_back(token);
	}
	return result;
}

vector<Key> read_keys(string fName) {
	vector<Key> result;
	vector<string> lines = readData(fName);

	for (int i = 0; i < lines.size(); i++) {
		Tokenizer str;
		string token;
		vector<string> tokens;
		string line = lines[i];
		str.set(line);

		while ((token = str.next()) != "") {
			tokens.push_back(token);
		}
		Key key(tokens[0], tokens[1]);
		result.push_back(key);
	}
	return result;
}

template <class T1, class T2>
vector<vector<T1> > make_matrix(vector<T2> &L) {
	vector<vector<T1> > M;
	int i, j;
	for (i = 0; i <= L.size(); i++) {
		vector<T1> row(L.size() + 1, 0);
		M.push_back(row);
	}
	// dummy row
	vector<T1> row(L.size() + 1, 0);
	M.push_back(row);
	return M;
}

template <class T1>
void print_matrix(vector<vector<T1>>& M) {
	int i, j;
	cout << "---------------------------------" << endl;
	for (i = 0; i < M.size(); i++)
		for (j = 0; j < M[i].size(); j++)
			cout << i << " " << j << " " << M[i][j] << endl;
}

int minimum(double a, double b) {
	return (a < b) ? a : b;
}

double sum(vector<double> &p, int a, int b) {
	double result = 0;
	for (int i = a; i <= b; i++) {
		result += p[i];
	}
	return result;
}

double optsearchtree(int n, vector<Key> &keys, vector<vector<double> > &A, vector<vector<int> > &R, vector<double> &p) {
	int i, j, k, diagonal;
	for (i = 1; i <= n; i++) {
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0;
	R[n + 1][n] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			double minA = 2222222;
			int minR;
			for (k = i; k <= j; k++) {
				double temp = A[i][k - 1] + A[k + 1][j];
				if (minA > temp) {
					minA = temp;
					minR = k;
				}
			}
			A[i][j] = minA + sum(p, i, j);
			R[i][j] = minR;
		}
	}
	return A[1][n];
}

Node* tree(int i, int j, vector<Key> &keys, vector<vector<int> > &R) {
	int k;
	Node *p;
	k = R[i][j];

	if (k == 0)
		return NULL;

	else {
		Node *p = new Node;
		p->key = keys[k - 1];
		p->left = tree(i, k - 1, keys, R);
		p->right = tree(k + 1, j, keys, R);
		return p;
	}
}

void print_tree(int p, Node* root) {
	if (root == NULL) return;
	for (int i = 0; i < p; i++) cout << "    ";
	cout << root->key.get_key() << endl;
	print_tree(p + 1, root->left);
	print_tree(p + 1, root->right);
}

int main() {
	string fName = "lab5-matrix.txt";
	vector<Key> keys = read_keys(fName);
	sort(keys.begin(), keys.end());
	vector<double> p;

	p.push_back(0);
	for (int i = 0; i < keys.size(); i++) {
		p.push_back(keys[i].get_value());
	}

	vector<vector<double> > A = make_matrix<double, Key>(keys);
	vector<vector<int> > R = make_matrix<int, Key>(keys);

	double minavg = optsearchtree(keys.size(), keys, A, R, p);

	Node *root = tree(1, keys.size(), keys, R);

	print_tree(0, root);

	return 1;

}