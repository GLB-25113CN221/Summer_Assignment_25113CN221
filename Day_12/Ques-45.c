#include <stdio.h>

// Function prototype for palindrome check
void palindrome_check(int);

int main()
{
    // Q-45 Write a program to write a function for palindrome
    int num;

    printf("Enter a number to check if it is palindrome or not :");
    scanf("%d", &num);

    palindrome_check(num);
    printf("\n\n");

    return 0;
}

void palindrome_check(int t)
{
    // original = stores original number, reverse = stores reversed number
    int original = t, reverse = 0;

    // Extract digits and build reversed number
    while (t > 0)
    {
        reverse = reverse * 10 + t % 10;
        t /= 10;
    }

    // If original equals reverse, it's a palindrome
    if (original == reverse)
        printf("The number %d is a palindrome.\n\n", original);
    else
        printf("The number %d is not a palindrome.\n\n", original);
}