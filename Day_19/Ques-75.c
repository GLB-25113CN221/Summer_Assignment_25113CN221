#include <stdio.h>

int main()
{
    // Q-75 Write a program to transpose matrix

    int row, col; // row = number of rows in matrix, col = number of columns in matrix

    printf("Enter the number of rows and columns in matrix respectively: ");
    scanf("%d%d", &row, &col);

    int A[row][col], T[col][row]; // A matrix 'A' of 'row' rows and 'col' columns

    // Input the elements of matrix A
    printf("\nEnter the elements of matrix A: ");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Transpose the matrix A

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            T[j][i] = A[i][j];
        }
    }

    // Print the transverse of the matrix

    printf("\nThe transpose of the matrix is: \n");

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("\t%d", T[i][j]);
        }
        printf("\n");
    }

    return 0;
}