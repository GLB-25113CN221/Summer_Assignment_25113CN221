#include <stdio.h>
#include <string.h>

// Function to print the character frequency
void character_frequency(char str[]);

int main()
{

    // Q-87 Write a program to character frequency

    char string[500];

    printf("Enter a paragraph: ");
    fgets(string, sizeof(string), stdin);

    printf("The frequency of the characters is as follows: \n\n");

    character_frequency(string);

    printf("\n\n");

    return 0;
}

void character_frequency(char str[])
{

    int temp = strlen(str);
    char char_freq[temp];

    for (int i = 0; i < temp; i++)
    {

        char ch = str[i];
        int freq = 1; // frequency of the character

        if (ch == ' ' || ch == '\n' || ch == '\0')
        {
            continue;
        }
        printf("    %c = ", ch);
        for (int j = i + 1; j < temp; j++)
        {
            if (str[j] == str[i])
            {
                freq++;
                str[j] = ' ';
            }
        }
        printf("%d\n", freq);
    }
}