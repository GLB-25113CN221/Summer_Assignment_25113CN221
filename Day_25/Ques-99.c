#include <stdio.h>
#include <string.h>

int main()
{
    // Q99: Sort names alphabetically

    int n;

    printf("Enter number of names: ");
    scanf("%d", &n);

    char names[n][50];
    char temp[50];

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%s", names[i]);

    // Bubble sort names alphabetically
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted names:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    return 0;
}