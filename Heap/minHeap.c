#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int minHeap[MAX];
int sizeMin = 0;

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// Insert into Min Heap
void insertMin(int value) {
	if (sizeMin >= MAX) {
		printf("Heap is full!\n");
		return;
	}
	minHeap[sizeMin] = value;
	int i = sizeMin;
	sizeMin++;

	// Heapify Up
	while (i != 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
		swap(&minHeap[(i - 1) / 2], &minHeap[i]);
		i = (i - 1) / 2;
	}
}

// Delete minimum (root)
int deleteMin() {
	if (sizeMin <= 0)
		return -1;

	int root = minHeap[0];
	minHeap[0] = minHeap[sizeMin - 1];
	sizeMin--;

	// Heapify Down
	int i = 0;
	while (1) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int smallest = i;

		if (left < sizeMin && minHeap[left] < minHeap[smallest])
			smallest = left;
		if (right < sizeMin && minHeap[right] < minHeap[smallest])
			smallest = right;

		if (smallest == i)
			break;

		swap(&minHeap[i], &minHeap[smallest]);
		i = smallest;
	}
	return root;
}

void displayMinHeap() {
	printf("Min Heap: ");
	for (int i = 0; i < sizeMin; i++)
		printf("%d ", minHeap[i]);
	printf("\n");
}

int main() {
	insertMin(10);
	insertMin(40);
	insertMin(30);
	insertMin(5);
	displayMinHeap();
	printf("Removed Min = %d\n", deleteMin());
	displayMinHeap();

	return 0;
}