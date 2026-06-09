#include <stdio.h>

int main()
{
    // Q-36 Write a program to print hollow square pattern

    int a; // a = number of units in the side of the square

    printf("Enter the number of units in the side of the square: ");
    scanf("%d", &a);

    // Outer loop controls rows
    for (int i = 1; i <= a; i++)
    {
        // First and last rows are solid (full stars)
        if (i == 1 || i == a)
        {
            for (int j = 1; j <= a; j++)
                printf("*");
        }
        else
        {
            // Middle rows: print star at borders, space inside
            for (int j = 1; j <= a; j++)
            {
                if (j == 1 || j == a)
                    printf("*");
                else
                    printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n\n");

    return 0;
}