#include <stdio.h>

int main()
{

    // Q-63 Write a program to find the pair with given sum

    int arr[20] = {3, 8, 15, 7, 12, 5, 20, 9, 6, 18, 11, 4, 14, 2, 19, 1, 16, 10, 13, 17};

    int sum, found = 0;

    printf("Enter the sum to find the pair: ");
    scanf("%d", &sum);

    printf("The pairs with sum %d are: ", sum);
    for (int i = 0; i < 20; i++)
    {
        if (arr[i] <= sum)
        {
            for (int j = i + 1; j < 20; j++)
            {
                if (arr[i] + arr[j] == sum)
                {
                    printf(" %d & %d", arr[i], arr[j]);
                    found = 1;
                }
            }
        }
    }

    if (found == 0)
        printf("No pairs found.");

    return 0;
}