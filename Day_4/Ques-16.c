#include <stdio.h>
#include <math.h>

int main()
{
    // Q-16 Write a program to print Armstrong number in a range

    int n1, n2; // To store the input values

    printf("Enter a range to find armstrong number between them: ");
    scanf("%d%d", &n1, &n2);

    printf("The armstrong numbers between %d and %d are: \n", n1, n2);

    for (int i = n1; i <= n2; i++)
    {
        int temp = i, sum = 0, digits = 0;
        /* temp = copy of i,
        sum = sum of powers,
        digits = digit count */

        // Count digits in current number i
        while (temp > 0)
        {
            temp /= 10;
            digits++;
        }
        temp = i; // Reset temp for next calculation

        // Calculate sum of each digit raised to the power of digit count
        while (temp > 0)
        {
            sum += pow(temp % 10, digits);
            temp /= 10;
        }

        // If sum equals original number, it's an Armstrong number
        if (sum == i)
            printf("%d\t", i);
    }

    return 0;
}