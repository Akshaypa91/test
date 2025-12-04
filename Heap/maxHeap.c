#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int maxHeap[MAX];
int sizeMax = 0;

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// Insert into Max Heap
void insertMax(int value) {
	if (sizeMax >= MAX) {
		printf("Heap is full!\n");
		return;
	}
	maxHeap[sizeMax] = value;
	int i = sizeMax;
	sizeMax++;

	// Heapify Up
	while (i != 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
		swap(&maxHeap[(i - 1) / 2], &maxHeap[i]);
		i = (i - 1) / 2;
	}
}

// Delete maximum (root)
int deleteMax() {
	if (sizeMax <= 1) return -1;

	int root = maxHeap[1];
	maxHeap[1] = maxHeap[sizeMax - 1];
	sizeMax--;

	int i = 1;
	while (1) {
		int left = 2 * i;
		int right = 2 * i + 1;
		int largest = i;

		if (left < sizeMax && maxHeap[left] > maxHeap[largest])
			largest = left;
		if (right < sizeMax && maxHeap[right] > maxHeap[largest])
			largest = right;

		if (largest == i)
			break;

		swap(&maxHeap[i], &maxHeap[largest]);
		i = largest;
	}
	return root;
}

void displayMaxHeap() {
	printf("Max Heap: ");
	for (int i = 0; i < sizeMax; i++)
		printf("%d ", maxHeap[i]);
	printf("\n");
}

int main() {
	insertMax(10);
	insertMax(40);
	insertMax(30);
	insertMax(5);
	displayMaxHeap();
	printf("Removed Max = %d\n", deleteMax());
	displayMaxHeap();

	return 0;
}