#include <stdio.h>
#include <math.h>

int main()
{
    // Q22 Write a program to convert binary to decimal

    int num, i = 0, dec = 0;
    /*  num = input binary number
        i = power index (position of digit from right, starting at 0)
        dec = decimal result */

    printf("Enter a binary number to convert into decimal: ");
    scanf("%d", &num);

    // Process each digit from right to left
    while (num > 0)
    {
        // Multiply last digit by 2^i and add to decimal result
        dec += (num % 10) * pow(2, i);
        num /= 10;
        i++;
    }

    printf("The decimal equivalent is %d.\n\n", dec);

    return 0;
}