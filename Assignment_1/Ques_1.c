#include <stdio.h>

int main() {
    int arr[50];
    int res[50];
    int n;

    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    
    printf("After Removing Duplicates: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ele = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != arr[i-1]) {
            res[ele++] = arr[i];
        }
    }

    for(int i = 0; i < ele; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}