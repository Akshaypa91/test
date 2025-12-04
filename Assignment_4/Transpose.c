#include <stdio.h>
#define max_terms 100
    typedef struct {
        int row;
        int col;
        int value;
    } term;

void create_sparse_matrix(term *a, int matrix[6][6], int rows, int cols) {
    int terms = 1; // Start from 1 to account for the header term
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] != 0){
                a[terms].row = i;
                a[terms].col = j;
                a[terms].value = matrix[i][j];
                terms++;
            }
        }
    }
    a[0].row = rows; // Number of rows
    a[0].col = cols; // Number of columns
    a[0].value = terms - 1; // Number of non-zero terms
}
void add(term *a, term *b, term *result) {
    int i = 1, j = 1, k = 1;
    result[0].row = a[0].row; // Set the number of rows
    result[0].col = a[0].col; // Set the number of columns
    result[0].value = 0; // Initialize non-zero terms count

    while(i <= a[0].value && j <= b[0].value) {
        if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        } else if(a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            result[k++] = b[j++];
        } else {
            result[k] = a[i];
            result[k++].value += b[j++].value;
            i++;
        }
    }
    
    while(i <= a[0].value) {
        result[k++] = a[i++];
    }
    
    while(j <= b[0].value) {
        result[k++] = b[j++];
    }
    
    result[0].value = k - 1; // Update the number of non-zero terms
}
void print_sparse_matrix(term *a) {
    printf("Sparse Matrix:\n");
    printf("Rows: %d, Cols: %d, Non-zero terms: %d\n", a[0].row, a[0].col, a[0].value);
    for(int i = 1; i <= a[0].value; i++) {
        printf("Row: %d, Col: %d, Value: %d\n", a[i].row, a[i].col, a[i].value);
    }
}
void transpose(term *a, term *result) {
    result[0].row = a[0].col; // Set the number of rows
    result[0].col = a[0].row; // Set the number of columns
    result[0].value = a[0].value; // Set the number of non-zero terms

    int k = 1;
    for(int j = 0; j < a[0].col; j++) {
        for(int i = 1; i <= a[0].value; i++) {
            if(a[i].col == j) {
                result[k].row = a[i].col;
                result[k].col = a[i].row;
                result[k++].value = a[i].value;
            }
        }
    }
}
int main(){
        
    term a[max_terms];
    term b[max_terms];
    term result[max_terms];
    term transposed[max_terms];
    int matrix1[6][6] = {
        {15, 0, 0, 22, 0, -15},
        {0, 11, 3, 0, 0, 0},
        {0, 0, 0, -6, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {91, 0, 0, 0, 0, 0},
        {0, 0, 28, 0, 0, 0}
    };
    int matrix2[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 5, 0, 0, 0},
        {0, -3, 0, 4, 0, 0},
        {0, 2, 0, 1, -1, 0},
        {7, 0, 0, 0, 8, -9}
    };
    create_sparse_matrix(a,matrix1, 6, 6);    create_sparse_matrix(b,matrix2, 6, 6);
    add(a, b, result);
    print_sparse_matrix(result);
    transpose(a, transposed);
    printf("\nTransposed Matrix:\n");
    print_sparse_matrix(transposed);
    return 0;
}