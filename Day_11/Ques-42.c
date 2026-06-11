#include <stdio.h>

// Function prototype for maximum
int maximum(int a, int b);

int main()
{
    // Q-42 Write a program to write function to find the maximum .

    int n_1, n_2; // n_1, n_2 = numbers entered by user

    printf("Enter two numbers to find the maximum: ");
    scanf("%d%d", &n_1, &n_2);

    printf("The maximum of %d and %d is %d.", n_1, n_2, maximum(n_1, n_2));

    return 0;
}

// If a > b, return a, else return b
int maximum(int a, int b)
{
    return (a > b) ? a : b;
}