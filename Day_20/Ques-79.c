#include <stdio.h>

int main()
{

    // Q-79 Write a program to find row-wise sum

    int row, col;            // number of rows and column in the matrix
    int row_no, row_sum = 0; // row_no = the row whose sum to find

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

    printf("Enter the row number to find it's sum: ");
    scanf("%d", &row_no);

    // Calculate row wise sum

    for (int i = 0; i < col; i++)
    {

        row_sum += matrix[row_no][i];
    }

    printf("The sum of %d row is %d", row_no, row_sum);

    return 0;
}