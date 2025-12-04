#include <stdio.h>

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// Heapify function (Max Heap)
void heapify(int arr[], int n, int i) {
	int largest = i;       // Assume root is largest
	int left = 2 * i;  // Left child
	int right = 2 * i + 1; // Right child

	// If left child is larger
	if (left < n && arr[left] > arr[largest])
		largest = left;

	// If right child is larger
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// If largest is not root
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest); //Recursively heapify affected subtree
	}
}

void heapSort(int arr[], int n) {
	// Step 1: Build Max Heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Step 2: Extract elements from heap
	for (int i = n - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]); // Move max to end
		heapify(arr, i, 0);     // Heapify reduced heap
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int arr[] = {12, 11, 5, 7, 3, 19, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Original Array: ");
	printArray(arr, n);

	heapSort(arr, n);

	printf("Sorted Array: ");
	printArray(arr, n);

	return 0;
}