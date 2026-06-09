#include <stdio.h>

int main()
{
    // Q-34 Write a program to print the reverse number triangle

    int rows; // rows = number of rows in the triangle

    printf("Enter the number of rows in the reverse number triangle: ");
    scanf("%d", &rows);

    // Outer loop controls row number
    for (int i = 1; i <= rows; i++)
    {
        // Inner loop prints numbers from 1 to (rows+1-i) (decreasing length)
        for (int j = 1; j <= rows + 1 - i; j++)
            printf("%d ", j);

        printf("\n");
    }

    printf("\n\n");

    return 0;
}