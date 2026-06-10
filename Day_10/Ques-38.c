#include <stdio.h>

int main()
{
    // Q-38 Write a program to print reverse pyramid

    int rows; // rows = number of rows in the pyramid

    printf("Enter the number of rows to print reverse star pyramid: ");
    scanf("%d", &rows);

    // Outer loop runs from rows down to 1 (decreasing)
    for (int i = rows; i >= 1; i--)
    {
        // Print spaces (increases as i decreases)
        for (int j = 1; j <= rows - i; j++)
            printf(" ");

        // Print odd number of stars: 2*i-1
        for (int k = 1; k <= 2 * i - 1; k++)
            printf("*");

        printf("\n"); // Move to next line after each row
    }

    printf("\n");

    return 0;
}