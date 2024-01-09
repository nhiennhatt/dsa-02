#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

struct Stack {
	int stack[MAX], n = 0;
	
	void push(int value) {
		stack[n++] = value;
	}

	int pop() {
		return stack[--n];
	}

	bool isEmpty() {
		return n <= 0;
	}
};

void initMatrix(int matrix[][MAX], int& nVer) {
	ifstream FILE("./data.txt");
	FILE >> nVer;
	for (int i = 0; i < nVer; i++)
		for (int o = 0; o < nVer; o++)
			FILE >> matrix[i][o];
}

void DFS(int matrix[][MAX], int nVer, int start, int dfs[], int& nDfs) {
	int visited[MAX], printed[MAX];
	Stack stack = Stack();
	for (int i = 0; i < nVer; i++) {
		visited[i] = 0;
		printed[i] = 0;
	}

	stack.push(start);
	visited[start] = 1;

	while (!stack.isEmpty()) {
		int currentVer = stack.pop();
		if (printed[currentVer] == 0) {
			dfs[nDfs++] = currentVer;
			printed[currentVer] = 1;
		}

		for (int i = 0; i < nVer; i++)
			if (matrix[currentVer][i] == 1 && visited[i] == 0) {
				stack.push(currentVer);
				stack.push(i);
				visited[i] = 1;
				break;
			}
	}
}

int main() {
	int matrix[MAX][MAX], nVer = 0, dfs[MAX], nDfs = 0;
	initMatrix(matrix, nVer);
	DFS(matrix, nVer, 0, dfs, nDfs);
	for (int i = 0; i < nDfs; i++) cout << dfs[i] << endl;

	system("pause");
	return 0;
}