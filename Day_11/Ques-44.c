#include <stdio.h>

// Function prototype for factorial
int factorial(int t);

int main()
{
    // Q-44 Write a program to write function to find factorial

    int n;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);

    printf("The factorial of %d is %d.\n", n, factorial(n));

    return 0;
}

int factorial(int t)
{
    int fact = 1; // fact = stores factorial result (starting from 1)

    // Multiply fact by numbers from 1 to t
    for (int i = 1; i <= t; i++)
    {
        fact *= i;
    }

    return fact;
}