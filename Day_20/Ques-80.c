#include <stdio.h>

int main()
{

    // Q-80 Write a program to find column-wise sum

    int row, col;            // number of rows and column in the matrix
    int col_no, col_sum = 0; // col_no = the column whose sum to find

    printf("Enter the row and column of the matrix respectively: ");
    scanf("%d%d", &row, &col);

    int matrix[row][col]; // the matrix

    // Input the elements of the matrix

    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the column number to find it's sum: ");
    scanf("%d", &col_no);

    // Calculate row wise sum

    for (int i = 0; i < row; i++)
    {

        col_sum += matrix[i][col_no];
    }

    printf("The sum of %d column is %d", col_no, col_sum);

    return 0;
}