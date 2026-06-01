#include <stdio.h>

int main()
{
    // Q-4  Write a program to count digits in a number

    int n1, temp, count = 0;

    printf("Enter a number to count it's digits: ");
    scanf("%d", &n1);

    temp = n1;
    while (temp != 0)
    {
        temp /= 10;
        count++;
    }

    printf("Number of digits in %d is %d\n", n1, count);

    return 0;
}