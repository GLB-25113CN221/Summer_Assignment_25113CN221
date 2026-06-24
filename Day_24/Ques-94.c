#include <stdio.h>
#include <string.h>

int main()
{

    // Q-94 Write a program to compress a string

    char string[200];

    printf("Enter a string: ");
    scanf("%s", string);

    int size1 = strlen(string);

    if (size1 > 0 && string[size1 - 1] == '\n')
        string[size1 - 1] = '\0';

    size1 = strlen(string);

    char ch = string[0];
    int count = 1;

    printf("\nThe compressed string is: ");

    for (int i = 1; i < size1; i++)
    {

        if (string[i] == ch)
        {
            count++;
        }
        else
        {
            printf("%c%d", ch, count);
            ch = string[i];
            count = 1;
        }
    }
    printf("%c%d", ch, count);

    return 0;
}