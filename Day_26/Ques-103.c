#include <stdio.h>

int main()
{

    // Q-103 Write a program to create ATM simulation

    int choice = 0, balance = 5000; // stores the value of input or choice of the user

    printf("\n\n     __________________\n");
    printf("    |  ATM SIMULATION  |    \n");
    printf("    |__________________|\n");

    do
    {
        printf("\n\n==MENU==\n");
        printf("\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n\n");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("\nYour current balance is: %d\n\n", balance);
            printf("Press Enter to continue...\n");
            getchar();
            getchar();
            break;

        case 2:
            int temp = 0;
            printf("\nEnter the amount to deposit: ");
            scanf("%d", &temp);
            balance += temp;
            printf("\n\n%d rupees deposited successfully!\n", temp);
            printf("New Balance: %d\n\n", balance);
            printf("Press Enter to continue...\n");
            getchar();
            getchar();
            break;

        case 3:
            int withdraw = 0;
            printf("\nEnter the amount to withdraw: ");
            scanf("%d", &withdraw);
            if (withdraw > balance)
            {
                printf("\n\nRequest Denied! You don't have enough balance.\nPlease check your Balance\n\n");
            }
            else
            {
                balance -= withdraw;
                printf("\n\n%d withdrawn successfully!\n", withdraw);
                printf("New balance: %d\n\n", balance);
            }

            printf("Press Enter to continue...\n");
            getchar();
            getchar();
            break;

        case 4:
            break;

        default:
            printf("\nInvalid Input! Please Try Again.\n");
        }

    } while (choice != 4);

    printf("\n\nTHANK YOU. \nHave a good day.\n\n");

    return 0;
}