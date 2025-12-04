#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
	int arr[] = {2, 4, 6, 8, 10, 12, 14};
	int n = sizeof(arr) / sizeof(arr[0]);

	int index = linearSearch(arr, n, 10);

	if (index != -1)
		printf("Found at index %d\n", index);
	else
		printf("Not found");

	return 0;
}