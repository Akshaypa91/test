#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generateRandomArray(int arr[], int n){
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
}

void bubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    printf("\n\n");
}

int main() {
    FILE*fp1;
    fp1 = fopen("output.txt","w");
    if(fp1 == NULL){
        printf("Error opening file\n");
        return 1;
    }

    fprintf(fp1,"Size\tBubble\t\tSelection\n");

    for(int i = 1; i <= 20; i++){
    int n = 1000*i;    
    int arr1[n];
    int arr2[n];
    clock_t start,end;
    
    generateRandomArray(arr1,n);
    generateRandomArray(arr2,n);

    start = clock();
    bubbleSort(arr1, n);
    end = clock();
    double timeTaken_bubble = ((double)(end - start))/CLOCKS_PER_SEC; //CLOCKS_PER_SEC is defined in the <time.h> library.

    start = clock();
    selectionSort(arr2, n);
    end = clock();
    double timeTaken_selection = ((double)(end - start))/CLOCKS_PER_SEC; //CLOCKS_PER_SEC is defined in the <time.h> library.
    


    fprintf(fp1,"%d\t%f\t%f\n",n,timeTaken_bubble,timeTaken_selection);
    
    }
fclose(fp1);

    // printf("\nBubble Sort:\n");
    // printArray(arr1, n);

    // printf("\nSelection Sort:\n");
    // printArray(arr2, n);

    return 0;
}