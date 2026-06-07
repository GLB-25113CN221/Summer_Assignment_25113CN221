#include <stdio.h>

int digit_sum(int t);

int main()
{
    // Q-27 Write a program to recursive sum of digits
    int n1;

    printf("Enter a number to find the sum of digits: \n");
    scanf("%d", &n1);

    printf("The sum of digits of %d is %d\n\n", n1, digit_sum(n1));

    return 0;
}

// Recursive function to calculate sum of digits of a number
int digit_sum(int t)
{
    // Base case: when all digits have been processed
    if (t == 0)
        return 0;
    // Recursive case: last digit + sum of remaining digits
    else
        return (t % 10) + digit_sum(t / 10);
}