#include <stdio.h>

// Function to reverse the string
void reverse_string(char str[]);
// Function to find the length of the string
int string_length(char str[]);

int main()
{

    // Q-82 Write a program to reverse a string

    char string[500];

    // Input the string
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    reverse_string(string);

    // Print the string after reversal
    printf("\nThe reverse string is : \n");
    fputs(string, stdout);

    return 0;
}

void reverse_string(char str[])
{

    int i = 0;
    int str_len = string_length(str); // the length of the string

    for (int i = 0; i < str_len / 2; i++)
    {

        char temp = str[i];
        str[i] = str[str_len - 1 - i];
        str[str_len - 1 - i] = temp;
    }
}

int string_length(char str[])
{
    int count = 0;

    while (str[count] != '\0' && str[count] != '\n')
    {
        count++;
    }

    return count;
}