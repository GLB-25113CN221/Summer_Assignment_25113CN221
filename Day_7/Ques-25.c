#include <stdio.h>

int fact(int t);

int main()
{
    // Q-25 Write a program to recursive factorial

    int n;

    printf("Enter a number find its factorial: ");
    scanf("%d", &n);

    printf("Factorial of %d is %d.\n", n, fact(n));

    return 0;
}

// Recursive function to calculate factorial of a number
int fact(int t)
{
    // Base case: factorial of 0 and 1 is 1
    if (t == 0 || t == 1)
        return 1;
    // Recursive case: n! = n * (n-1)!
    else
        return t * fact(t - 1);
}
