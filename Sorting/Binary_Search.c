#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int lp = 0, rp = n-1;

    while(lp <= rp) {
        int mid = (lp + rp) / 2;

        if(arr[mid] == target) {
            return mid;
        }
        else if(target < arr[mid]) {
            rp = mid - 1;
        }
        else {
            lp = mid + 1;
        }
    }
    return -1;
}

int main() {
	int arr[] = {2, 4, 6, 8, 10, 12, 14};
	int n = sizeof(arr) / sizeof(arr[0]);

	int index = binarySearch(arr, n, 10);

	if (index != -1)
		printf("Found at index %d\n", index);
	else
		printf("Not found");

	return 0;
}