#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Q-101 Write a program to create number guessing game

    int i = 16, num, guess; // guess= stores the input value by user, num = value by computer

    num = rand() % 100 + 1;

    printf("\n\nWELCOME TO THE NUMBER GUESSING GAME!\n\n");
    printf("I have selected a number between 1 to 100 and you have to guess it.\n");

    printf("Enter your guess: ");
    scanf("%d", &guess);

    int no_guess = 1; // no_guess = the number of guesses taken to get the answer right

    while (num != guess)
    {

        if (guess < num)
            printf("\nToo low. Try again!\n");
        else
            printf("\nToo high. Try again!\n");

        printf("Enter your guess: ");
        scanf("%d", &guess);

        no_guess++;
    }

    printf("\nCongratulation! You guessed the number in %d attempts.\n\n", no_guess);

    return 0;
}