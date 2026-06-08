#include <stdio.h>

int main()
{
    // Q-30 Write a program to print number triangle

    int rows; // rows = number of rows in the triangle

    printf("Enter the number of rows in the number triangle: ");
    scanf("%d", &rows);

    // Outer loop controls row number
    for (int i = 1; i <= rows; i++)
    {
        // Inner loop prints numbers from 1 to i
        for (int j = 1; j <= i; j++)
            printf("%d ", j);

        printf("\n"); // Move to next line after each row
    }

    printf("\n\n");

    return 0;
}