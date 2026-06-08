#include <stdio.h>

int main()
{
    // Q-31 Write a program to print character triangle

    int row1; // row1 = number of rows in the triangle

    printf("Enter the number of rows in the character triangle: ");
    scanf("%d", &row1);

    // Outer loop controls row number
    for (int i = 1; i <= row1; i++)
    {
        // Inner loop prints characters from A to corresponding letter
        for (int j = 1; j <= i; j++)
            printf("%c ", 64 + j); // 64 + j gives ASCII: 65=A, 66=B, etc.

        printf("\n"); // Move to next line after each row
    }

    printf("\n\n");

    return 0;
}