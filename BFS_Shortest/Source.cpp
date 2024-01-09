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

struct Queue {
	int queue[100], front = -1, rear = -1;
	void push(int value) {
		if (front == -1) front++;
		queue[++rear] = value;
	}

	int pop() {
		int result = queue[front++];
		if (front > rear) {
			front = -1;
			rear = -1;
		}
		return result;
	}

	bool isEmpty() {
		return (rear == -1 && front == -1) || (front > rear);
	}
};

void BFS(int matrix[][MAX], int nVer, int path[], int& nPath, int source, int dest) {
	Queue queue = Queue();
	int parrent[MAX];
	bool visited[MAX];
	for (int i = 0; i < nVer; i++) {
		visited[i] = 0;
		parrent[i] = -1;
	}

	queue.push(source);
	visited[source] = 1;
	while (!queue.isEmpty()) {
		int currentValue = queue.pop();
		for (int i =0; i < nVer; i++)
			if (visited[i] == 0 && matrix[currentValue][i] != 0) {
				queue.push(i);
				parrent[i] = currentValue;
				visited[i] = 1;
			}
	}

	int currentVer = dest;
	path[nPath++] = dest;
	while (parrent[currentVer] != -1) {
		path[nPath++] = parrent[currentVer];
		currentVer = parrent[currentVer];
	}
}

int main() {
	int matrix[MAX][MAX], nVer = 0;
	int path[MAX], nPath = 0;

	initMatrix(matrix, nVer);
	BFS(matrix, nVer, path, nPath, 0, 5);
	for (int i = nPath - 1; i >= 0; i--) cout << path[i] << endl;

	system("pause");
	return 0;
}