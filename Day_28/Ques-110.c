#include <stdio.h>
#include <string.h>

#define MAX 100

// struct variable store info of bank accounts
struct bank
{
    long int acc_no; // account number
    char name[50];
    float balance; // initial Balance
};

// Function Declaration

void press_enter();
int create_acc(struct bank accounts[], int n);
int display_acc(struct bank accounts[], int n);
int deposit(struct bank accounts[], int n);
int withdraw(struct bank accounts[], int n);
void Bubble_sort(struct bank accounts[], int n);

int main()
{

    // Q-110 Write a program to create bank account system

    printf("\n=======================================================\n");
    printf("                 | BANK ACCOUNT SYSTEM |\n");
    printf("=======================================================\n\n");

    struct bank accounts[MAX];
    int option;  // to store the choice of user to navigate menu
    int num = 0; // to store the number of accounts in bank
    int (*menu[4])(struct bank accounts[], int num) = {create_acc, display_acc, deposit, withdraw};

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Create Account\n2. Display All Accounts\n3. Deposit\n4. Withdraw\n5. Exit");

        printf("\n\nEnter your choice:_");
        scanf("%d", &option);

        if (option >= 1 && option <= 4)
        {
            num = menu[option - 1](accounts, num);
            press_enter();
        }
        else if (option == 5)
        {
            printf("\nExiting Program! Thank you.\n");
        }
        else
            printf("\nInvalid Input! Please Try Again.");

    } while (option != 5);

    return 0;
}

void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

// function to create account
int create_acc(struct bank accounts[], int n)
{
    printf("\n----- Create Account -----\n");

    int temp; // no. of accounts to create
    printf("\nEnter the number of accounts to create:_");
    scanf("%d", &temp);

    if (temp + n > MAX)
    {
        printf("\nLimit Exceed. Please Try Again.\n");
        return n;
    }

    // Input the account info

    for (int i = 0; i < temp; i++, n++)
    {
        printf("\n----- Account %d -----\n", i + 1);
        printf("Account Number: ");
        scanf("%ld", &accounts[n].acc_no);
        printf("Name: ");
        getchar();
        fgets(accounts[n].name, sizeof(accounts[n].name), stdin);

        int len = strlen(accounts[n].name);
        if (len > 0 && accounts[n].name[len - 1] == '\n')
            accounts[n].name[len - 1] = '\0';

        printf("Initial Balance: ");
        scanf("%f", &accounts[n].balance);

        printf("\nAccount created successfully!\n");
    }

    return n;
}

int display_acc(struct bank accounts[], int n)
{

    if (n == 0)
    {
        printf("\nNo account Found! Please Try Again.\n");
        return n;
    }

    printf("\n==============================================================\n");
    printf("                       ACCOUNT LIST\n");
    printf("==============================================================\n");
    printf("Account No.      | Name                   |Balance     \n");
    printf("---------------------------------------------------------------\n");

    Bubble_sort(accounts, n);

    for (int i = 0; i < n; i++)
    {
        printf("%ld", accounts[i].acc_no);

        int digit = 1, temp = accounts[i].acc_no;

        while (temp > 9)
        {
            digit++;
            temp /= 10;
        }

        for (int j = 1; j <= 17 - digit; j++)
        {
            printf(" ");
        }

        printf("| %s", accounts[i].name);

        digit = strlen(accounts[i].name);

        for (int j = 1; j <= 23 - digit; j++)
        {
            printf(" ");
        }

        printf("| %.2f", accounts[i].balance);

        printf("\n");
    }
    printf("---------------------------------------------------------------\n");
    printf("Total Accounts: %d\n", n);

    return n;
}

// Function to deposit amount
int deposit(struct bank accounts[], int n)
{
    printf("\n----- DEPOSIT -----\n");

    float deposit; // amount to deposit in the account
    long int acc;  // account number to deposit in
    int found = 0; // to determine if the account found or not

    printf("\nEnter Account Number:_");
    scanf("%d", &acc);

    for (int i = 0; i < n; i++)
    {
        if (acc == accounts[i].acc_no)
        {
            printf("Enter the amount to deposit: ");
            scanf("%f", &deposit);
            accounts[i].balance = accounts[i].balance + deposit;
            printf("\nDeposited successfully!\n");
            printf("\nNew Balance: %.2f", accounts[i].balance);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Account not found! Please Try Again!");
    }
    return n;
}

// Function to withdraw money
int withdraw(struct bank accounts[], int n)
{
    printf("\n----- WITHDRAW -----\n");

    float withdraw; // amount to withdraw from the account
    long int acc;   // account number to withdraw from
    int found = 0;  // to determine if the account found or not

    printf("\nEnter Account Number:_");
    scanf("%d", &acc);

    for (int i = 0; i < n; i++)
    {
        if (acc == accounts[i].acc_no)
        {
            printf("Enter the amount to withdraw: ");
            scanf("%f", &withdraw);
            accounts[i].balance -= withdraw;
            printf("\nWithdrawn successfully!\n");
            printf("\nNew Balance: %.2f", accounts[i].balance);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Account not found! Please Try Again!");
    }
    return n;
}

void Bubble_sort(struct bank accounts[], int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            int flag = 0; // flag to tell if the elements should be swapped or not

            if (accounts[j].acc_no > accounts[j + 1].acc_no)
                flag = 1;

            if (flag == 1)
            {
                struct bank temp = accounts[j];
                accounts[j] = accounts[j + 1];
                accounts[j + 1] = temp;
            }
        }
    }
}
