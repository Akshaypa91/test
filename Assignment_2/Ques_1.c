#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN   100

void bubbleSort(char arr[][MAX_LEN], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(arr[j], arr[j + 1]) > 0) {
				char temp[MAX_LEN];
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);
			}
		}
	}
}

int main() {
	FILE *fin, *fout;
	char words[MAX_WORDS][MAX_LEN];
	int count = 0;

	fin = fopen("input.txt", "r");
	if (fin == NULL) {
		perror("Error opening input file");
		return 1;
	}

	while (fscanf(fin, "%99s", words[count]) == 1) {
		count++;
		if (count >= MAX_WORDS) break;
	}
	fclose(fin);

	bubbleSort(words, count);

	fout = fopen("output.txt", "w");
	if (fout == NULL) {
		perror("Error opening output file");
		return 1;
	}

	for (int i = 0; i < count; i++) {
		fprintf(fout, "%s\n", words[i]);
	}
	fclose(fout);

	printf("Sorting completed! Check output.txt\n");
	return 0;
}