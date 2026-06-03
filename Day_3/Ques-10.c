#include <stdio.h>

int main()
{
    // Q-10 Write a program to print prime numbers in range
    int n1, n2;

    printf("Enter a range to find prime numbers between them(n1, n2): ");
    scanf("%d%d", &n1, &n2);

    printf("The prime numbers between %d and %d are: \n", n1, n2);

    for (int i = n1; i <= n2; i++)
    {
        if (i < 2)
            continue;
        int fact = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                fact = 0;
                break;
            }
        }
        if (fact)
            printf("%d\t", i);
    }
    printf("\n\n");

    return 0;
}