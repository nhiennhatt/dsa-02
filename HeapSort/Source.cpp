#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

void init(int arr[], int& n) {
	ifstream FILE("./data.txt");
	FILE >> n;
	for (int i = 0; i < n; i++) FILE >> arr[i];
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int arr[], int n, int i) {
	int largest = i, left = 2*i + 1, right = 2*i + 2;
	
	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[i], arr[0]);
		heapify(arr, i, 0);
	}
}

int main() {
	int arr[MAX], n = 0;
	init(arr, n);
	heapSort(arr, n);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";

	system("pause");
	return 0;
}