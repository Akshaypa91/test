#include <stdio.h>
#include <stdlib.h>

void swapValues(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void maxHeapify(int arr[], int size, int root) {
    int largest = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < size && arr[leftChild] > arr[largest])
        largest = leftChild;

    if (rightChild < size && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != root) {
        swapValues(&arr[root], &arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void heapSortAscending(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swapValues(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void showArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int count;
    printf("Enter how many integers you want to sort: ");
    scanf("%d", &count);

    int *data = (int *)malloc(count * sizeof(int));
    if (data == NULL) {
        printf("Error: Memory allocation unsuccessful.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", count);
    for (int i = 0; i < count; i++)
        scanf("%d", &data[i]);

    printf("\nInput array:\n");
    showArray(data, count);

    heapSortAscending(data, count);

    printf("\nSorted array (Ascending order using Heap Sort):\n");
    showArray(data, count);

    free(data);
    return 0;
}
