#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

void initMatrix(int matrix[][MAX], int& nVer) {
	ifstream FILE("./data.txt");
	FILE >> nVer;
	for (int i = 0; i < nVer; i++)
		for (int o = 0; o < nVer; o++)
			FILE >> matrix[i][o];
}

void Prim(int matrix[][MAX], int nVer, int T1[], int T2[], int Tw[], int& nT, int start) {
	int passed[MAX];
	for (int i = 0; i < nVer; i++) passed[i] = 0;

	passed[start] = 1;

	while (nT < nVer - 1) {
		int min = INT_MAX, xMin = -1, yMin = -1;
		for (int i = 0; i < nVer; i++)
			if (passed[i] == 1)
				for (int o = 0; o < nVer; o++)
					if (matrix[i][o] < min && passed[o] == 0 && matrix[i][o] > 0) {
						min = matrix[i][o];
						xMin = i;
						yMin = o;
					}
		T1[nT] = xMin;
		T2[nT] = yMin;
		passed[yMin] = 1;
		Tw[nT++] = min;
	}
}

int main() {
	int matrix[MAX][MAX], nVer = 0;
	int T1[MAX], T2[MAX], Tw[MAX], nT = 0;

	initMatrix(matrix, nVer);
	Prim(matrix, nVer, T1, T2, Tw, nT, 0);
	for (int i = 0; i < nT; i++) cout << "(" << T1[i] << ", " << T2[i] << ") = " << Tw[i] << endl;

	system("pause");
	return 0;
}