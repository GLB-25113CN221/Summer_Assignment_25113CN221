#include <stdio.h>

int main()
{
    // Q-13 Write a program to generate fibonacci series

    int n, first = 0, second = 1, next = 0;
    /*n = number of terms,
    first = first term (0),
    second = second term (1),
    next = next term */

    printf("Enter the number of terms for the fibonacci series: ");
    scanf("%d", &n);

    printf("The first %d terms of fibonacci series are: \n", n);

    for (int i = 1; i <= n; i++) // Loop runs n times, one for each term
    {
        printf("%d\t", first); // print current term before updating

        next = first + second; // calculate next as sum of previous two

        first = second;
        second = next;
    }

    printf("\n\n");

    return 0;
}