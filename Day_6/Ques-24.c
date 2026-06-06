#include <stdio.h>

int main()
{
    // Q-24 Write a program to find x^n without using pow()

    int x, a, value = 1;
    /* x = base number
     a = exponent (power)
     value = result (starts at 1 for multiplication) */

    printf("Enter a number: ");
    scanf("%d", &x);

    printf("Enter the power: ");
    scanf("%d", &a);

    // Note: Works only for positive exponents
    // For exponent 0, result should be 1 (handled by value = 1 initialization)
    for (int i = 1; i <= a; i++)
    {
        value *= x;
    }

    printf("(%d)^%d is %d.\n\n", x, a, value);

    return 0;
}