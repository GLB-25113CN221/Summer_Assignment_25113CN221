#include <stdio.h>

int main()
{
    // Q-11 Write a program to find gcd of two numbers
    int a, b, min, gcd;

    printf("Enter two numbers to find their GCD: ");
    scanf("%d%d", &a, &b);

    min = (a < b) ? a : b;

    for (int i = min; i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break;
        }
    }

    printf("The GCD of %d and %d is %d.\n\n", a, b, gcd);

    return 0;
}