#include <stdio.h>

int main()
{
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