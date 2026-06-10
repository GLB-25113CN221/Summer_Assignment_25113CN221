#include <stdio.h>

int main()
{
    // Q-37 Write a program to print star pyramid

    int row; // row = number of rows in the pyramid

    printf("Enter the number of rows to print star pyramid: ");
    scanf("%d", &row);

    // Outer loop controls the row number
    for (int i = 1; i <= row; i++)
    {
        // Print spaces to align pyramid to center
        for (int j = 1; j <= row - i; j++)
            printf(" ");

        // Print odd number of stars: 1, 3, 5, ... (2*i-1)
        for (int k = 1; k <= 2 * i - 1; k++)
            printf("*");

        printf("\n"); // Move to next line after each row
    }

    printf("\n");

    return 0;
}