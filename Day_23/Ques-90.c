#include <stdio.h>
#include <string.h>

// function to remove space
void remove_space(char str[])
{

    int i = 0, j = 0;

    while (str[i] != '\0')
    {

        if (str[i] == '\n')
        {
            str[i] = '\0';
        }

        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }

        i++;
    }
}

int main()
{

    // Q-90 Write a  program to find the first repeating character

    char string[50];

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    int temp = strlen(string);

    remove_space(string);

    printf("\nThe first repeating character is: ");

    // first non-repeating character
    for (int i = 0; i < temp; i++)
    {

        char ch = string[i];
        int found = 0;
        for (int j = 0; j < temp; j++)
        {
            if (string[j] == string[i] && j != i)
            {
                found = 1;
            }
        }
        if (found == 1)
        {
            printf("%c", ch);
            break;
        }
    }

    return 0;
}
