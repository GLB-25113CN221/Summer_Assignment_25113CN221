#include <stdio.h>
int main()
{
    // Q-5 Write a program to find sum of digits of a number
    int n, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    printf("The sum of digits is %d.\n\n", sum);

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

    // Q-7 Write a program to find product of digits of a number

    int n1, prod = 1;

    printf("Enter a number to find the product of it's digits: ");
    scanf("%d", &n1);

    while (n1 > 0)
    {
        prod *= n1 % 10;
        n1 /= 10;
    }
    printf("The product is %d.\n\n", prod);

    // Q-8 Write a program to check whether a number is palindrome

    int n2, original, reverse = 0;

    printf("Enter a number to check if it's a palindrome: ");
    scanf("%d", &n2);

    original = n2;

    while (n2 > 0)
    {
        reverse = reverse * 10 + n2 % 10;
        n2 /= 10;
    }

    if (original == reverse)
        printf("The number %d is a palindrome.\n\n", original);
    else
        printf("The number %d is not a palindrome.\n\n", original);

    return 0;
}