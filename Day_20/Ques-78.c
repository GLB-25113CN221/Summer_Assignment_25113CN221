#include <stdio.h>

int main()
{
    // Q-78 Write a program to check symmetric matrix

    int n, symmetric = 1;

    printf("Enter the size of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetry
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                symmetric = 0;
                break;
            }
        }
        if (symmetric == 0)
            break;
    }

    if (symmetric == 1)
        printf("The matrix is SYMMETRIC.\n");
    else
        printf("The matrix is NOT SYMMETRIC.\n");

    return 0;
}
