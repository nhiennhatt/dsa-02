#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

struct Node {
	int value = -1;
	Node* next = NULL;
};

struct Queue {
	int queue[MAX], front = -1, rear = -1;
	void push(int value) {
		if (front == -1) front++;
		queue[++rear] = value;
	}

	int pop() {
		int value = queue[front++];
		if (front > rear) {
			front = -1;
			rear = -1;
		}
		return value;
	}

	bool isEmpty() {
		if ((front == -1 && rear == -1) || (front > rear)) return true;
		return false;
	}
};

void initList(Node* list[], int& numVertex) {
	ifstream FILE("./data.txt");
	FILE >> numVertex;

	for (int i = 0; i < numVertex; i++) {
		int edge = 0;
		FILE >> edge;
		Node* current = NULL;
		for (int o = 0; o < edge; o++) {
			Node* newNode = new Node();
			FILE >> newNode->value;
			if (o == 0)
				list[i] = newNode;
			else {
				current->next = newNode;
			}
			current = newNode;
		}
	}
}

void deAlloc(Node* list[], int numVertex) {
	for (int i = 0; i < numVertex; i++) {
		Node* current = list[i];
		while (current != NULL) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}
}

int findBFS(Node* list[], int numVer, int start, int value) {
	Queue queue = Queue();
	int visited[MAX], count = 0;
	for (int i = 0; i < numVer; i++) visited[i] = 0;

	queue.push(start);
	visited[start] = 1;

	while (!queue.isEmpty()) {
		int currentValue = queue.pop();
		count++;
		if (currentValue == value) return count;
		Node* currentNode = list[currentValue];
		while(currentNode != NULL) {
			if (visited[currentNode->value] == 0) {
				queue.push(currentNode->value);
				visited[currentNode->value] = 1;
			}
			currentNode = currentNode->next;
		}
	}
	
	return -1;
}

int main() {
	int numVertex = 0;
	Node* list[MAX];

	initList(list, numVertex);
	
	cout << findBFS(list, numVertex, 0, 3) << endl;

	deAlloc(list, numVertex);

	system("pause");
	return 0;
}
