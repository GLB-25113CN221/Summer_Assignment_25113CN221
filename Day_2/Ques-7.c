#include <stdio.h>

int main()
{
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

    return 0;
}