#include <stdio.h>

int main()
{
    // Q-35 Write a program to print the repeated character pattern

    int row1; // row1 = number of rows in the pattern

    printf("Enter the number of rows in the repeated character triangle: ");
    scanf("%d", &row1);

    // Outer loop controls row number
    for (int i = 1; i <= row1; i++)
    {
        // Inner loop prints character i times
        for (int j = 1; j <= i; j++)
            printf("%c ", 64 + i); // 64 + i gives ASCII: 65=A, 66=B, etc.

        printf("\n");
    }

    printf("\n\n");

    return 0;
}