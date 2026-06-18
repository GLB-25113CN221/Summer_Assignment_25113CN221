#include <stdio.h>

int main()
{

    // Q-73 Write a program to add matrices

    int row, col; // row = no. of row in matrices, col = no. of column in matrices

    printf("Enter the number of rows and columns in matrices: ");
    scanf("%d%d", &row, &col);

    int A[row][col], B[row][col], C[row][col]; // matrix A, B and C where C will store (A + B)

    // Input the elements of matrix A
    printf("Enter the elements of matrix A: ");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Input the elements of matrix B
    printf("Enter the elements of matrix B: ");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Addition of the two matrices
    printf("The summation of matrices is: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
            printf("\t%d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}