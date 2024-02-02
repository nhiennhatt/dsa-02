#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

void init(int arr[], int& n) {
	ifstream FILE("./data.txt");
	FILE >> n;
	for (int i = 0; i < n; i++)
		FILE >> arr[i];
}

void QuickSort(int arr[], int left, int right) {
	int middle = arr[(left + right)] / 2, currentLeft = left, currentRight = right;

	do {
		while (arr[currentLeft] < middle) currentLeft++;
		while (arr[currentRight] > middle) currentRight--;

		if (currentLeft <= currentRight) {
			swap(arr[currentLeft], arr[currentRight]);
			currentLeft++;
			currentRight--;
		}
	} while (currentLeft < currentRight);

	if (currentLeft < right) {
		QuickSort(arr, currentLeft, right);
	}

	if (currentRight > left) {
		QuickSort(arr, left, currentRight);
	}
}

int main() {
	int arr[MAX], n = 0;
	init(arr, n);
	QuickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	system("pause");
	return 0;
}