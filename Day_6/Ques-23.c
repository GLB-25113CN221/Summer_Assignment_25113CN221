#include <stdio.h>

int main()
{
    // Q-23 Write a program to count set bits in a number

    int n1, orig, temp1 = 0, binary1 = 0, count = 0;
    /* n1 = input decimal number
     orig = to retain the original number
     temp1 = stores binary digits in reverse order
     binary1 = actual binary number (as decimal of 0s and 1s)
     count = number of set bits (1s) in binary representation */

    printf("Enter a decimal number to count number of set bits: ");
    scanf("%d", &n1);

    orig = n1;

    // Convert decimal to binary
    while (n1 > 0)
    {
        temp1 = temp1 * 10 + (n1 % 2);
        n1 /= 2;
    }

    // Reverse to get correct binary order
    while (temp1 > 0)
    {
        binary1 = binary1 * 10 + (temp1 % 10);
        temp1 /= 10;
    }

    // Count set bits (1s) in the binary representation
    while (binary1 > 0)
    {
        if (binary1 % 10)
            count++;
        binary1 /= 10;
    }

    printf("The number of set bits in %d is %d.\n\n", orig, count);

    return 0;
}