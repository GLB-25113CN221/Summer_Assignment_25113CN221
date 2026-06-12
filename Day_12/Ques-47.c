#include <stdio.h>

// Function prototype for Fibonacci series
void print_fibonacci(int);

int main()
{
    // Q-47 Write a program to write a function for fibonacci
    int n1;

    printf("Enter the number of terms to print fibonacci series: ");
    scanf("%d", &n1);

    print_fibonacci(n1);
    printf("\n\n");

    return 0;
}

void print_fibonacci(int num)
{
    // first = first term (0), second = second term (1), next = next term
    int first = 0, second = 1, next;

    printf("The fibonacci series upto %d is : \n", num);

    // Loop to print 'num' terms
    for (int i = 1; i <= num; i++)
    {
        printf("%d\t", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n"); // Add newline after the series
}