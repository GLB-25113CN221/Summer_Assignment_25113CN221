#include <stdio.h>

int main()
{
    // Q-19 Write a program to print factors of a number

    int num; // num = input number

    printf("Enter a number to find its factors: ");
    scanf("%d", &num);

    printf("The factors of %d are: ", num);

    // Check each number from 1 to num
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            printf("%d\t", i); // print the factors
        }
    }

    printf("\n\n");

    return 0;
}