#include <stdio.h>
#include <stdbool.h>

// Function prototype for perfect number check
bool perfect_check(int);

int main()
{
    // Q-48 Write a program to write function for perfect number
    int number, temp;

    printf("Enter a number to find if it is a perfect number or not: ");
    scanf("%d", &number);

    temp = perfect_check(number);
    if (temp)
        printf("%d is a perfect number.", number);
    else
        printf("%d is not a perfect number.", number);
    printf("\n\n");

    return 0;
}

bool perfect_check(int num)
{
    // perf_sum = sum of divisors, flag = 0 (not perfect) or 1 (perfect)
    int perf_sum = 0, flag = 0;

    // Check all numbers from 1 to num-1
    for (int i = 1; i < num; i++)
    {
        // If i divides num, add it to sum of divisors
        if (num % i == 0)
            perf_sum += i;
    }

    // If sum of divisors equals the number, it's perfect
    if (perf_sum == num)
        flag = 1;

    return flag;
}