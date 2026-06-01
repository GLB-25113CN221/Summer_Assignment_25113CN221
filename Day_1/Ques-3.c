#include <stdio.h>

int main()
{
    // Q-3 Write a program to find factorial of a number

    int number, fact = 1;

    printf("\nEnter a number to find it's factorial: ");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++)
    {
        fact *= i;
    }

    printf("Factorial of %d is %d\n\n", number, fact);

    return 0;
}