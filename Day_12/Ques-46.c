#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function prototype for Armstrong check (returns bool)
bool armstrong(int);

int main()
{
    // Q-46 Write a program to write function for Armstrong
    int n, check;

    printf("Enter a number to check if it is armstrong number: ");
    scanf("%d", &n);

    check = armstrong(n);
    if (check)
        printf("It is an Armstrong number.");
    else
        printf("It is not an Armstrong number.");

    printf("\n\n");

    return 0;
}

bool armstrong(int t)
{
    // sum = sum of powers, orig = to retain original input, digit = number of digits, check = result
    int sum = 0, orig = t, digit = 0;
    bool check = 0;

    // Count number of digits in the number
    while (t > 0)
    {
        digit++;
        t /= 10;
    }

    t = orig; // Reset t to original value

    // Calculate sum of each digit raised to power of digit count
    while (t > 0)
    {
        sum += pow(t % 10, digit);
        t /= 10;
    }

    // If sum equals original, it's an Armstrong number
    if (sum == orig)
        check = 1;

    return check;
}