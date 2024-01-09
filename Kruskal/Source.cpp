#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

struct Edge {
	int source, dest, w;
	Edge(int i, int o, int wei) {
		source = i;
		dest = o;
		w = wei;
	}
	Edge() {}
};

void swap(Edge& a, Edge& b) {
	Edge temp = a;
	a = b;
	b = temp;
}

struct UnionSet {
	int set[MAX], n;

	UnionSet(int num) {
		n = num;
		for (int i = 0; i < n; i++) {
			set[i] = i;
		}
	}

	int Find(int value) {
		if (value == set[value]) return value;
		return Find(set[value]);
	}

	void Union(int a, int b) {
		int parrentA = Find(a);
		int parrentB = Find(b);
		set[parrentB] = parrentA;
	}
};

void sort(Edge E[], int nE) {
	for (int i = 0; i < nE - 1; i++)
		for (int o = i + 1; o < nE; o++)
			if (E[i].w > E[o].w)
				swap(E[i], E[o]);
}

void inputMatrix(int matrix[][MAX], int& nVer) {
	ifstream FILE("./data.txt");
	FILE >> nVer;
	for (int i = 0; i < nVer; i++)
		for (int o = 0; o < nVer; o++)
			FILE >> matrix[i][o];
}

void initE(Edge E[], int& nE, int matrix[][MAX], int nVer) {
	for (int i = 0; i < nVer; i++)
		for (int o = 0; o < nVer; o++)
			if (matrix[i][o] > 0)
				E[nE++] = Edge(i, o, matrix[i][o]);
}

void Kruskal(Edge E[], int nE, Edge T[], int& nT, int nVer) {
	sort(E, nE);
	int currentE = 0;
	UnionSet unionSet = UnionSet(nE);
	while (currentE < nE && nT < nVer - 1) {
		if (unionSet.Find(E[currentE].dest) != unionSet.Find(E[currentE].source)) {
			T[nT++] = Edge(E[currentE].source, E[currentE].dest, E[currentE].w);
			unionSet.Union(E[currentE].source, E[currentE].dest);
		}
		currentE++;
	}
}

int main() {
	int matrix[MAX][MAX], nVer = 0, nE = 0, nT = 0;
	Edge E[MAX], T[MAX];

	inputMatrix(matrix, nVer);
	initE(E, nE, matrix, nVer);
	Kruskal(E, nE, T, nT, nVer);
	for (int i = 0; i < nT; i++) cout << "(" << T[i].source << "," << T[i].dest << ") = " << T[i].w << endl;

	system("pause");
	return 0;
}