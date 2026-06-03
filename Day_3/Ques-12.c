#include <stdio.h>

int main()
{
    // Q-12 Write a program to find LCM of two numbers
    int a1, b1, lcm;

    printf("Enter two numbers to find their LCM: ");
    scanf("%d%d", &a1, &b1);

    int i = 1;

    while (1)
    {
        if (a1 * i == b1 * i)
        {
            lcm = a1 * i;
            break;
        }
        else if ((a1 * i) % b1 == 0)
        {
            lcm = a1 * i;
            break;
        }
        else if ((b1 * i) % a1 == 0)
        {
            lcm = b1 * i;
            break;
        }
        i++;
    }
    printf("%d", lcm);

    return 0;
}