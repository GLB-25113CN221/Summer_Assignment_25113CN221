#include <stdio.h>

// Function prototype for prime check (void return type)
void prime_check(int t);

int main()
{
    // Q-43 Write a program to write function to check prime

    int num;

    printf("Enter a number to check if it is prime or not: ");
    scanf("%d", &num);

    prime_check(num);

    return 0;
}

void prime_check(int t)
{
    int check = 1; // check = 1 means prime, 0 means not prime

    // Check divisibility from 2 to sqrt(t)
    for (int i = 2; i * i <= t; i++)
    {
        if (t % i == 0) // If remainder is 0, a divisor is found
        {
            check = 0; // Set check = 0 (not prime)
            break;     // Exit loop
        }
    }

    // If check is 1 (prime), else not prime
    if (check)
        printf("%d is a prime number.\n", t);
    else
        printf("%d is not a prime number.\n", t);
}