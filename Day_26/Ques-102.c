#include <stdio.h>

int main()
{

    // Q-102 Write a program to create voting eligibility system

    char name[20];

    int age;

    printf("\n\nWELCOME to the Voting Eligibility System!\n");
    printf("------------------------------------------\n\n");
    printf("Let's see if you are eligible to vote.\n");

    printf("\nEnter your name: ");
    scanf("%s", name);

    printf("\nEnter your age: ");
    scanf("%d", &age);

    if (age < 0)
    {
        printf("\n\nInvalid Age! Please Try Again.\n\n");
    }
    else if (age >= 18)
    {

        printf("\n\nHey %s, you are eligible to vote.\n\nHope you exercise it responsibly.\n\n", name);
    }
    else
    {

        printf("\n\nSorry %s, you are not eligible to vote yet.\n\nGuess you have to wait for %d years more.\n\n", name, (18 - age));
    }

    printf("Thankyou!\n\n");

    return 0;
}