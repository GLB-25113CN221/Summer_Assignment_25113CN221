#include <stdio.h>

int main()
{
    // Q-6 Write a program to reverse a number
    int num, rev = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    printf("The reverse of the number is %d.\n\n", rev);

    return 0;
}