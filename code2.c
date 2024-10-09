#include <stdio.h>

#define SIZE 5

/* This function should take two matrices as input and return their sum. */
int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int sumMatrix[SIZE][SIZE]){
    // for each row, for each item in that row, add the items in both matricies at that index
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            sumMatrix[i][j] = m1[i][j] + m2[i][j];
        }
    }
}
/* This function should take two matrices as input and return their product. */
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int product[SIZE][SIZE]){
    // for each row and column
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            // start each entry in the product matrix at 0 so all multiplications can be added
            product[i][j] = 0;
            // multiply each row of m1 against each col of m2 and add to the product matrix
            for (int k = 0; k < SIZE; k++){
                product[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}
/* This function should take a matrix as input and return its transpose. */ 
int transposeMatrix(int m1[SIZE][SIZE], int transpose[SIZE][SIZE]){
    // flip the matrix by flipping the row and col indexes
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            transpose[i][j] = m1[j][i];
        }
    }
}
/* This function should take a matrix as input and print it in a user-friendly format. */
int printMatrix(int matrix[SIZE][SIZE]){
    // print all rows
    for (int i = 0; i < SIZE; i++){
        // print each row with formatting
        printf("|");
        for (int j = 0; j < SIZE; j++){
            printf(" %02d ", matrix[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

int main(){
    // initialize matricies
    int m1[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
    };

    // this matrix will hold the output matrix for memory purposes
    int output[SIZE][SIZE];

    // print out initial matricies for user
    printf("Matrix 1:\n");
    printMatrix(m1);
    printf("Matrix 2:\n");
    printMatrix(m2);

    // get the dimensions of each matrix in order to determine if the operation is valid
    int rowsm1 = sizeof(m1) / sizeof(m1[0]);
    int colsm1 = sizeof(m1[0]) / sizeof(m1[0][0]);
    int rowsm2 = sizeof(m2) / sizeof(m2[0]);
    int colsm2 = sizeof(m2[0]) / sizeof(m2[0][0]);

    // print the two matricies added, with checking for invalid dimensions
    printf("Matrix1 + Matrix2:\n");
    if (rowsm1 == rowsm2 || colsm1 == colsm2){
        addMatrices(m1, m2, output);
        printMatrix(output);
    } else{
        printf("Matricies are the wrong size for addition.");
    }
    
    // print the two matricies multiplied against each other, with checking for invalid dimensions
    printf("Matrix1 * Matrix2:\n");
    if (colsm1 == rowsm2){
        multiplyMatrices(m1, m2, output);
        printMatrix(output);
    } else{
        printf("Matricies are the wrong size for multiplication.");
    }

    // print both matricies transposed
    printf("Matrix 1 Transpose:\n");
    transposeMatrix(m1, output);
    printMatrix(output);

    printf("Matrix 2 Transpose:\n");
    transposeMatrix(m2, output);
    printMatrix(output);
}

