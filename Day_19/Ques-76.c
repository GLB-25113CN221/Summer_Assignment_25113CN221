#include <stdio.h>

int main()
{

    // Q-76 Write a program to find diagonal sum

    int row, col, sum = 0;
    /* row = number of rows in the matrix
       col = number of columns in the matrix
       sum = sum of all the diagonal elements
    */
    printf("Enter the number of rows and columns in matrix respectively: ");
    scanf("%d%d", &row, &col);

    int matrix[row][col]; // A matrix with 'row' rows and 'col' columns

    // Input the elements of the matrix

    printf("\nEnter the elements of the matrix: ");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sum of all the diagonal elements

    if (row == col)
    {
        for (int i = 0; i < row; i++)
        {
            sum += matrix[i][i];
        }

        printf("\nThe sum of the diagonal elements of the matrix is %d.", sum);
    }
    else
    {
        printf("\nDiagonal sun is only defined for square matrices!\n");
    }
    return 0;
}