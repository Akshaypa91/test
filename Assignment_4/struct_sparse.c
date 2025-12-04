#include <stdio.h>
#define SIZE 100

typedef struct {
    int row;
    int col;
    int val;
} Node;

typedef struct {
    int rows;
    int cols;
    int nonZero;
    Node data[SIZE];
} SparseMatrix;

void initMatrix(SparseMatrix *mat, int r, int c) {
    (*mat).rows = r;
    (*mat).cols = c;
    (*mat).nonZero = 0;
}

void insertElement(SparseMatrix *mat, int r, int c, int value) {
    if (value == 0) return;
    int idx = (*mat).nonZero;
    (*mat).data[idx].row = r;
    (*mat).data[idx].col = c;
    (*mat).data[idx].val = value;
    (*mat).nonZero++;
}

void printMatrix(SparseMatrix mat) {
    printf("Row  Col  Val\n");
    for (int i = 0; i < mat.nonZero; i++) {
        printf("%3d  %3d  %3d\n", mat.data[i].row, mat.data[i].col, mat.data[i].val);
    }
}

void sortMatrix(SparseMatrix *mat) {
    for (int i = 0; i < (*mat).nonZero; i++) {
        for (int j = i + 1; j < (*mat).nonZero; j++) {
            if ((*mat).data[i].row > (*mat).data[j].row ||
               ((*mat).data[i].row == (*mat).data[j].row &&
                (*mat).data[i].col > (*mat).data[j].col)) {
                Node temp = (*mat).data[i];
                (*mat).data[i] = (*mat).data[j];
                (*mat).data[j] = temp;
            }
        }
    }
}

SparseMatrix addMatrix(SparseMatrix A, SparseMatrix B) {
    SparseMatrix result;
    initMatrix(&result, A.rows, A.cols);

    if (A.rows != B.rows || A.cols != B.cols) {
        printf("Addition not possible: dimension mismatch.\n");
        return result;
    }

    int i = 0, j = 0;
    while (i < A.nonZero && j < B.nonZero) {
        if (A.data[i].row < B.data[j].row ||
           (A.data[i].row == B.data[j].row && A.data[i].col < B.data[j].col)) {
            insertElement(&result, A.data[i].row, A.data[i].col, A.data[i].val);
            i++;
        } 
        else if (B.data[j].row < A.data[i].row ||
                (B.data[j].row == A.data[i].row && B.data[j].col < A.data[i].col)) {
            insertElement(&result, B.data[j].row, B.data[j].col, B.data[j].val);
            j++;
        } 
        else {
            int sum = A.data[i].val + B.data[j].val;
            if (sum != 0) {
                insertElement(&result, A.data[i].row, A.data[i].col, sum);
            }
            i++; j++;
        }
    }

    while (i < A.nonZero) {
        insertElement(&result, A.data[i].row, A.data[i].col, A.data[i].val);
        i++;
    }
    while (j < B.nonZero) {
        insertElement(&result, B.data[j].row, B.data[j].col, B.data[j].val);
        j++;
    }

    return result;
}

SparseMatrix transposeMatrix(SparseMatrix A) {
    SparseMatrix T;
    initMatrix(&T, A.cols, A.rows);

    for (int i = 0; i < A.nonZero; i++) {
        insertElement(&T, A.data[i].col, A.data[i].row, A.data[i].val);
    }

    sortMatrix(&T);
    return T;
}

int main() {
SparseMatrix M1, M2, M3, MT;

initMatrix(&M1, 4, 4);
initMatrix(&M2, 4, 4);

insertElement(&M1, 0, 0, 7);
insertElement(&M1, 1, 3, 5);
insertElement(&M1, 2, 1, 9);

insertElement(&M2, 0, 2, 4);
insertElement(&M2, 1, 1, 6);
insertElement(&M2, 3, 3, 8);

printf("Matrix M1 (unsorted):\n");
printMatrix(M1);

sortMatrix(&M1);
printf("Matrix M1 (sorted):\n");
printMatrix(M1);

printf("Matrix M2:\n");
printMatrix(M2);

M3 = addMatrix(M1, M2);
printf("Matrix M3 = M1 + M2:\n");
printMatrix(M3);

MT = transposeMatrix(M1);
printf("Transpose of M1:\n");
printMatrix(MT);

return 0;

}
