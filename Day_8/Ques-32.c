#include <stdio.h>

int main()
{
    // Q-32 Write a program to print repeated-number pattern

    int row2; // row2 = number of rows in the pattern

    printf("Enter the number of rows in the repeated-number pattern: ");
    scanf("%d", &row2);

    // Outer loop controls row number
    for (int i = 1; i <= row2; i++)
    {
        // Inner loop prints current row number (i) repeatedly
        for (int j = 1; j <= i; j++)
            printf("%d ", i);

        printf("\n"); // Move to next line after each row
    }

    printf("\n\n");

    return 0;
}