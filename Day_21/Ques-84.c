#include <stdio.h>

// Function to convert lowercase to uppercase character
void convert_lc_uc(char str[]);

int main()
{

    // Q-84 Write a program to convert lowercase to uppercase

    char string[500];

    // Input the string
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    // Call the converting function
    convert_lc_uc(string);

    // Print the string
    printf("\nThe modified string is: \n");
    fputs(string, stdout);

    return 0;
}

void convert_lc_uc(char str[])
{

    int i = 0;
    char ch;

    while (str[i] != '\0')
    {

        ch = str[i];

        if ((ch >= 'a' && ch <= 'z'))
        {
            str[i] = ch - 32;
        }

        i++;
    }
}
