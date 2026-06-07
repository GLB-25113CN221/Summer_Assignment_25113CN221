#include <stdio.h>

int fibonacci(int t);

int main()
{
    // Q-26 Write a program to recursive fibonacci

    int term;

    printf("Enter the number of terms in fibonacci series: ");
    scanf("%d", &term);

    printf("The first %d terms of fibonacci series are: \n", term);

    // Print each term from 1 to term
    // Note: Not efficient for large values due to repeated calculations
    for (int i = 1; i <= term; i++)
    {
        printf("%d\t", fibonacci(i));
    }
    printf("\n\n");

    return 0;
}

// Recursive function to find nth Fibonacci term
int fibonacci(int t)
{
    // Base case: 1st Fibonacci term is 0
    if (t == 1)
        return 0;
    // Base case: 2nd Fibonacci term is 1
    else if (t == 2)
        return 1;
    // Recursive case: Fib(n) = Fib(n-1) + Fib(n-2)
    else
        return fibonacci(t - 1) + fibonacci(t - 2);
}