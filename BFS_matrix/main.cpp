#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

struct Queue
{
	int queue[MAX], front = -1, rear = -1;
	void push(int value) {
		if (front == -1) front++;
		queue[++rear] = value;
	}

	int pop() {
		int value = queue[front++];
		if (front > rear) {
			rear = -1;
			front = -1;
		}

		return value;
	}

	bool isEmpty() {
		if ((rear == -1 && front == -1) || (front > rear)) return true;
		return false;
	}
};

void initMatrix(int matrix[][MAX], int& nVer) {
	ifstream FILE("./data.txt");
	FILE >> nVer;
	for (int i = 0; i < nVer; i++)
		for (int o = 0; o < nVer; o++)
			FILE >> matrix[i][o];
}

void BFS(int matrix[][MAX], int& nVer, int start, int bfs[], int& nBfs) {
	int visited[MAX];
	Queue queue = Queue();
	for (int i = 0; i < nVer; i++) visited[i] = 0;

	queue.push(start);
	visited[start] = 1;

	while (!queue.isEmpty()) {
		int currentValue = queue.pop();
		bfs[nBfs++] = currentValue;
		for (int i = 0; i < nVer; i++)
			if (matrix[currentValue][i] == 1 && visited[i] == 0) {
				queue.push(i);
				visited[i] = 1;
			}
	}
}

int main() {
	int matrix[MAX][MAX], nVer = 0, bfs[MAX], nBfs = 0;
	initMatrix(matrix, nVer);
	BFS(matrix, nVer, 0, bfs, nBfs);

	for (int i = 0; i < nBfs; i++) cout << bfs[i] << endl;

	system("pause");
	return 0;
}