#include <stdio.h>

int main()
{
    // Q-29 Write a program to print half pyramid pattern

    int row; // row = number of rows in the pyramid

    printf("Enter the number of rows in half pyramid: ");
    scanf("%d", &row);

    // Outer loop controls number of rows
    for (int i = 1; i <= row; i++)
    {
        // Inner loop prints i stars in each row
        for (int j = 1; j <= i; j++)
            printf("* ");

        printf("\n"); // Move to next line after each row
    }

    printf("\n\n");

    return 0;
}