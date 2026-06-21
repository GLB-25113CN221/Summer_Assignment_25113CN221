#include <stdio.h>

int string_length(char str[]);

int main()
{

    // Q-81 Write a program to find string length without strlen()

    char string[500] = {'\0'};
    int len; // to store the value returned by th string_length function

    // Input the string
    printf("Input a string: ");
    fgets(string, sizeof(string), stdin);

    len = string_length(string);

    // Print the value
    printf("The length of the given string is : %d", len);

    return 0;
}

int string_length(char str[])
{
    int count = 0; // to count the characters in the string

    while (str[count] != '\0' && str[count] != '\n')
    {
        count++;
    }

    return count;
}