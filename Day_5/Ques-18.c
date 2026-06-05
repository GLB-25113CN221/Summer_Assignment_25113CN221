#include <stdio.h>

int main()
{
    // Q-18 Write a program to check strong number

    int n, original, sum = 0;
    /* n = input number,
       original = to retain the input value,
       sum = sum of factorials of digits */

    printf("Enter a number to check if it is a strong number: ");
    scanf("%d", &n);

    original = n;

    // process each digit of the number
    while (n > 0)
    {
        int fact = 1, rem = n % 10; // rem = last digit of n, fact = factorial of rem

        // Calculate factorial of the digit
        for (int i = 1; i <= rem; i++)
            fact *= i;

        sum += fact;
        n /= 10;
    }

    // Check if the sum of factorials of digits is equal to the number itself, then it is a strong number
    if (original == sum)
        printf("The number %d is a strong number.\n\n", original);
    else
        printf("The number %d is not a strong number.\n\n", original);

    return 0;
}