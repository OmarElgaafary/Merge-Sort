#include <iostream>


void printarr(int arr[], int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++) {
		std::cout << arr[i];
		if (i < length - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]";
}
void Merge(int arr[], int low, int mid, int high);
void MergeSort(int arr[],int low, int high);



int main() {

	int data[20] = {20, 19, 18, 17, 16, 15 , 14 ,13, 12, 11, 10, 9, 8 ,7, 6, 5, 4, 3, 2, 1};

	MergeSort(data, 0, 19);
	printarr(data, 20);


}

void Merge(int arr[], int low, int mid, int high) {

	int* C = new int[high + 1];
	int i = low;
	int k = low;
	int j = mid + 1;

	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) {
		
			C[k++] = arr[i++];
		}
		else if (arr[j] < arr[i]) {
			
			C[k++] = arr[j++];
		}
	}

	for (; i <= mid; i++) {
		C[k++] = arr[i];	
	}

	for (; j <= high; j++) {
		C[k++] = arr[j];
	}

	for (int x = low; x <= high; x++) {
		arr[x] = C[x];
	}

	delete[] C;
}


void MergeSort(int arr[], int low, int high) {

	if (low < high) {
		int mid = (low + high) / 2;

		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		Merge(arr, low, mid, high);
	}
}


