#include <stdio.h>

int main()
{
    // Q-1 Sum of first N natural numbers
    int num, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }

    printf("Sum of first %d natural numbers is %d\n\n", num, sum);

    // Q-2 Multiplication table of a given number

    int n;

    printf("Enter a number to print its table: ");
    scanf("%d", &n);
    printf("The multiplication table of %d is as follows:\n", n);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d  =  %d\n", n, i, n * i);
    }
    printf("\n");

    // Q-3 Write a program to find factorial of a number

    int number, fact = 1;

    printf("\nEnter a number to find it's factorial: ");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++)
    {
        fact *= i;
    }
    printf("Factorial of %d is %d\n\n", number, fact);

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