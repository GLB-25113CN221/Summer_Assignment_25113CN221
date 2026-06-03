#include <stdio.h>

int main()
{
    // Q-9 Write a program to check whether a number is prime
    int n, flag = 1;

    printf("Enter a number to check if it's prime: ");
    scanf("%d", &n);

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("The number %d is a prime number.\n\n", n);
    else
        printf("The number %d is not a prime number.\n\n", n);

    return 0;
}