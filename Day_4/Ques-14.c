#include <stdio.h>

int main()
{
    // Q-14 Write a program to find the nth fibonacci term

    int term, f1 = 0, f2 = 1, temp = 0, value;
    /* term = position to find,
    f1 = first term (0),
    f2 = second term (1),
    temp = temporary variable,
    value = the nth fibonacci term */

    printf("Enter the number of term to find in the fibonacci series: ");
    scanf("%d", &term);

    for (int i = 1; i <= term; i++) // Loop to reach the nth term
    {
        if (i == term) // when value reach the desired term, store current f1 as value
            value = f1;

        // Update the next terms
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }

    printf("The %dth in fibonacci series is %d\n\n", term, value);

    return 0;
}