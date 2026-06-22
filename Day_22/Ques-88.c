#include <stdio.h>

// function to remove spaces form string
void remove_space(char str[]);

int main()
{

    char string[500];

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    remove_space(string);

    printf("\n\nThe string after removing spaces:   ");
    fputs(string, stdout);

    printf("\n\n");

    return 0;
}

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