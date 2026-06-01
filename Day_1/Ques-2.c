#include <stdio.h>

int main()
{
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

    return 0;
}