#include <stdio.h>
#include <string.h>

// function to remove space and convert the alphabet into lowercase
void compare_ready(char str[]);

int main()
{

    // Q-85 Write a program to check palindrome string

    char string[500];

    printf("Enter a string to check if it palindrome or not: ");
    fgets(string, sizeof(string), stdin);

    compare_ready(string);

    int len = strlen(string); // to measure the length of the string
    int check = 0;            // flag to check if it is palindrome or not

    for (int i = 0; i < len / 2; i++)
    {

        if (string[i] != string[len - 1 - i])
        {
            check = 1;
            break;
        }
    }

    if (check == 1)
    {
        printf("\nThe given string is not a palindrome.\n");
    }
    else
    {
        printf("\nThe given string is a palindrome.\n");
    }

    return 0;
}

void compare_ready(char str[])
{

    int temp = strlen(str);
    int i = 0, j = 0;

    while (str[i] != 0)
    {
        // Removes newline character if present any
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }

        // convert uppercase to lowercase

        if (str[i] >= 'A' && str[i] <= 'Z')
        {

            str[i] = str[i] + 32;
        }

        // skip the spaces
        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }

        i++;
    }

    str[j] = '\0';
}