#include <stdio.h>

int main()
{
    // Q-17 Write a program to check perfect number

    int num, perfect = 0;
    /*num = input number,
    perfect = sum of all proper divisors*/

    printf("Enter a number to check if it is a perfect number: ");
    scanf("%d", &num);

    // loop through all numbers less than num
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            perfect += i;
        }
    }

    // If sum of all proper divisors equal to the number, then it is a perfect number
    if (num == perfect)
        printf("The number %d is a perfect number.\n\n", num);
    else
        printf("The number %d is not a perfect number.\n\n", num);

    return 0;
}