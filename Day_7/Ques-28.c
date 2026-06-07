#include <stdio.h>

int reverse(int t, int rev);

int main()
{
    // Q-28 Write a program to Recursive reverse number

    int num, rev = 0;

    printf("Enter a number to find its reverse: ");
    scanf("%d", &num);

    printf("The reverse of %d is %d.\n\n", num, reverse(num, rev));

    return 0;
}

// Recursive function to reverse a number using accumulator
int reverse(int t, int rev)
{
    // Base case: when all digits processed, return reversed number
    if (t == 0)
        return rev;

    else
        rev = rev * 10 + t % 10;
    // Recursive call with remaining digits and updated rev
    return reverse(t / 10, rev);
}