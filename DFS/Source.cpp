#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

struct Stack {
	int stack[MAX], amount = 0;
	void push(int value) {
		stack[amount++] = value;
	}

	int pop() {
		return stack[--amount];
	}

	bool isEmpty() {
		if (amount <= 0) return true;
		return false;
	}
};

struct Node {
	int value = 0;
	Node* next = NULL;
};

void initList(Node* list[], int& numVertext) {
	ifstream FILE("./data.txt");
	FILE >> numVertext;

	for (int i = 0; i < numVertext; i++) {
		int edge;
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
			Node* temp = current->next;
			delete current;
			current = temp;
		}
	}
}

void DFS(Node* list[], int numVertex, int start, int dfs[], int& nDfs) {
	int visited[MAX], printed[MAX];
	Stack stack = Stack();
	for (int i = 0; i < numVertex; i++) {
		visited[i] = 0;
		printed[i] = 0;
	}

	stack.push(start);
	visited[start] = 1;

	while (!stack.isEmpty()) {
		int currentVertex = stack.pop();
		if (printed[currentVertex] == 0) {
			dfs[nDfs++] = currentVertex;
			printed[currentVertex] = 1;
		}
		
		Node* currentNode = list[currentVertex];
		while (currentNode != NULL) {
			if (visited[currentNode->value] == 0) {
				stack.push(currentVertex);
				stack.push(currentNode->value);
				visited[currentNode->value] = 1;
				break;
			}
			currentNode = currentNode->next;
		}
	}
}

int main() {
	Node* list[MAX];
	int numVertex = 0, dfs[MAX], nDfs = 0;

	initList(list, numVertex);
	DFS(list, numVertex, 0, dfs, nDfs);
	deAlloc(list, numVertex);

	for (int i = 0; i < nDfs; i++) cout << dfs[i] << endl;

	system("pause");
	return 0;
}
