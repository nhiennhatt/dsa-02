#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

void countingSort(int arr[], int n) {
	int max = INT_MIN;
	int count[MAX], e = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[arr[i]]++;
	
	for (int i = 0; i <= max; i++)
		for (int o = 0; o < count[i]; o++)
			arr[e++] = i;
}

void init(int arr[], int& n) {
	ifstream FILE("data.txt");
	FILE >> n;
	for (int i = 0; i < n; i++)
		FILE >> arr[i];
}

int main() {
	int arr[MAX], n = 0;
	init(arr, n);
	countingSort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	system("pause");
	return 0;
}