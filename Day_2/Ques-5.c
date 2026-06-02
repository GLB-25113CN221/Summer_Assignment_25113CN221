#include <stdio.h>

int main()
{
    // Q-5 Write a program to find sum of digits of a number
    int n, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    printf("The sum of digits is %d.\n\n", sum);

    return 0;
}