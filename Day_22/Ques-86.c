#include <stdio.h>
#include <string.h>

// the words count in the sentence
int count_words(char str[]);

int main()
{

    // Q-86 Write a program to count words in a sentence.

    char string[500];

    printf("Enter a sentence to get the word count: \n");
    fgets(string, sizeof(string), stdin);

    int count = count_words(string); // number of words in the string

    printf("\n\nThe number of words in the sentence is %d.\n\n", count);

    return 0;
}

int count_words(char str[])
{
    int new_word = 1;   // indicate if we aresearching for a new word or not
    int word_count = 0; // counts the number of word

    for (int i = 0; i < strlen(str); i++)
    {

        char ch = str[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if (new_word == 1)
            {
                new_word = 0;
                word_count++;
            }
        }
        else
        {
            new_word = 1;
        }
    }

    return word_count;
}