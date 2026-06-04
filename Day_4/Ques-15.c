#include <stdio.h>
#include <math.h>

int main()
{
    // Q-15 Write a program to Armstrong number

    int num, original, arm = 0, digit = 0;
    /* num = input,
    original = to retain original input,
    arm = sum of powers,
    digit = number of digits */

    printf("Enter a number to check if it's a armstrong number: ");
    scanf("%d", &num);

    original = num;

    // Count number of digits in the number
    while (num > 0)
    {
        num /= 10;
        digit++;
    }

    num = original;

    while (num > 0)
    {
        arm += pow(num % 10, digit); // Add (digit ^ power of digit count) to arm
        num /= 10;
    }

    if (arm == original)
        printf("%d is an armstrong number.\n\n", original);
    else
        printf("%d is not an armstrong number.\n\n", original);

    return 0;
}