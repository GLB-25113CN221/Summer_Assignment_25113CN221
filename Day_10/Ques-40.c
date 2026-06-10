#include <stdio.h>

int main()
{
    // Q-40 Write a program to print character pyramid

    int row1; // row1 = number of rows in the pyramid

    printf("Enter the number of rows to print character pyramid: ");
    scanf("%d", &row1);

    // Outer loop controls row number
    for (int i = 1; i <= row1; i++)
    {
        // Print spaces for alignment
        for (int j = 1; j <= row1 - i; j++)
            printf(" ");

        // Print characters in palindromic pattern: A, B, C, ..., i, ..., C, B, A
        // 64 + k gives ASCII: 65=A, 66=B, 67=C, etc.
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            if (k <= i)
                printf("%c", 64 + k);
            else
                printf("%c", 64 + 2 * i - k);
        }

        printf("\n"); // Move to next line after each row
    }

    printf("\n");

    return 0;
}