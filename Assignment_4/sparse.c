#include <stdio.h>
#define SIZE 100

void createSparse(int mat[SIZE][3], int rows, int cols) {
    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = 0;
}

void showSparse(int mat[SIZE][3]) {
    printf("Row  Col  Val\n");
    for (int i = 0; i <= mat[0][2]; i++) {
        printf("%3d  %3d  %3d\n", mat[i][0], mat[i][1], mat[i][2]);
    }
}

void addElement(int mat[SIZE][3], int r, int c, int value) {
	mat[0][2]++;
    int pos = mat[0][2];
    mat[pos][0] = r;
    mat[pos][1] = c;
    mat[pos][2] = value;
}

void sortSparse(int mat[SIZE][3]) {
    int total = mat[0][2];
    for (int i = 1; i <= total; i++) {
        for (int j = i + 1; j <= total; j++) {
            if (mat[i][0] > mat[j][0] || 
               (mat[i][0] == mat[j][0] && mat[i][1] > mat[j][1])) {
                for (int k = 0; k < 3; k++) {
                    int swap = mat[i][k];
                    mat[i][k] = mat[j][k];
                    mat[j][k] = swap;
                }
            }
        }
    }
}

void sumSparse(int A[SIZE][3], int B[SIZE][3], int R[SIZE][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("Addition not possible: size mismatch.\n");
        return;
    }

    R[0][0] = A[0][0];
    R[0][1] = A[0][1];

    int i = 1, j = 1, k = 1;
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || A[i][0] == B[j][0] && A[i][1] < B[j][1]) {
            R[k][0] = A[i][0];
            R[k][1] = A[i][1];
            R[k][2] = A[i][2];
            i++;
        } 
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            R[k][0] = B[j][0];
            R[k][1] = B[j][1];
            R[k][2] = B[j][2];
            j++;
        } 
        else {
            R[k][0] = A[i][0];
            R[k][1] = A[i][1];
            R[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= A[0][2]) {
        R[k][0] = A[i][0];
        R[k][1] = A[i][1];
        R[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        R[k][0] = B[j][0];
        R[k][1] = B[j][1];
        R[k][2] = B[j][2];
        j++; k++;
    }

    R[0][2] = k - 1;
}

void getTranspose(int A[SIZE][3], int T[SIZE][3]) {
    T[0][0] = A[0][1];
    T[0][1] = A[0][0];
    T[0][2] = A[0][2];

    for (int i = 1; i <= A[0][2]; i++) {
        T[i][0] = A[i][1];
        T[i][1] = A[i][0];
        T[i][2] = A[i][2];
    }
}

int main() {
int M1[SIZE][3], M2[SIZE][3],M3[SIZE][3], MT[SIZE][3];

createSparse(M1, 4, 4);
createSparse(M2, 4, 4);

// M1
addElement(M1, 0, 0, 5);
addElement(M1, 1, 2, 8);
addElement(M1, 3, 1, 6);

// M2
addElement(M2, 0, 1, 4);
addElement(M2, 2, 2, 7);
addElement(M2, 3, 3, 9);

printf("Matrix M1 before sorting:\n");
showSparse(M1);
sortSparse(M1);
printf("Matrix M1 after sorting:\n");
showSparse(M1);

printf("Matrix M2:\n");
showSparse(M2);

sumSparse(M1, M2, M3);
printf("Matrix M3 = M1 + M2:\n");
showSparse(M3);

getTranspose(M1, MT);
printf("Transpose of M1:\n");
sortSparse(MT);
showSparse(MT);

return 0;
}
