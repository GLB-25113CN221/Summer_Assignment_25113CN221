#include <stdio.h>

int main()
{
    // Q-33 Write a program to print the reverse star pattern

    int row; // row = number of rows in the pattern

    printf("Enter the number of rows in the reverse star pattern: ");
    scanf("%d", &row);

    // Outer loop controls number of rows
    for (int i = 1; i <= row; i++)
    {
        // Inner loop prints stars from row i to row (decreasing pattern)
        for (int j = i; j <= row; j++)
            printf("* ");

        printf("\n");
    }

    printf("\n\n");

    return 0;
}