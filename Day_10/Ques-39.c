#include <stdio.h>

int main()
{
    // Q-39 Write a program to print number pyramid

    int r; // r = number of rows in the pyramid

    printf("Enter the number of rows to print number pyramid: ");
    scanf("%d", &r);

    // Outer loop controls row number
    for (int i = 1; i <= r; i++)
    {
        // Print spaces for alignment
        for (int j = 1; j <= r - i; j++)
            printf(" ");

        // Print numbers in palindromic pattern: 1,2,3,...,i,...,3,2,1
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            if (k <= i)
                printf("%d", k);
            else
                printf("%d", 2 * i - k);
        }

        printf("\n"); // Move to next line after each row
    }

    printf("\n");

    return 0;
}