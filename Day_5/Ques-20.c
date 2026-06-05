#include <stdio.h>

int main()
{
    // Q-20 Write a program to find largest prime factor.

    int num, prime = 1;
    /* num = input number,
       prime = largest prime factor */

    printf("Enter a natural number to find its largest prime factor: ");
    scanf("%d", &num);

    // Start from largest possible factor and go downwards
    for (int i = num; i > 0; i--)
    {
        if (num % i == 0)
        {
            int check = 1; // Assume i is prime until proven otherwise

            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                    check = 0; // i has divisor then check = 0
            }

            // if check = 1 means i is prime, the largest prime factor is found, break the loop
            if (check)
            {
                prime = i;
                break;
            }
        }
    }

    printf("The largest prime factor of %d is %d.\n\n", num, prime);

    return 0;
}