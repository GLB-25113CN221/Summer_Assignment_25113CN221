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

    return 0;
}