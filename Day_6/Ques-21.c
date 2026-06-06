#include <stdio.h>

int main()
{
    // Q-21 Write a program to convert decimal to binary

    int n, original, temp = 0, binary = 0;
    /* n = input decimal number
       original = retain original input
       temp = stores binary digits in reverse order
       binary = final binary number*/

    printf("Enter a decimal number to convert into binary: ");
    scanf("%d", &n);

    original = n;

    // Extract binary digits in reverse order
    while (n > 0)
    {
        temp = temp * 10 + (n % 2);
        n /= 2;
    }

    // Reverse the digits to get correct binary order
    while (temp > 0)
    {
        binary = binary * 10 + (temp % 10);
        temp /= 10;
    }

    // This method works only for numbers where binary fits in int range
    printf("The binary equivalent of %d is %d.\n\n", original, binary);

    return 0;
}