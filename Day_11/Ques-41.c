#include <stdio.h>

int sum(int a, int b);

int main()
{
    // Q-41 Write a program to find sum of two numbers.

    int n1, n2; // n1, n2 = numbers entered by user

    printf("Enter two numbers to find their sum: ");
    scanf("%d%d", &n1, &n2);

    // Call sum function with n1 and n2 as arguments
    printf("The sum of %d and %d is %d", n1, n2, sum(n1, n2));

    return 0;
}

// Returns sum of a and b
int sum(int a, int b)
{
    return a + b;
}