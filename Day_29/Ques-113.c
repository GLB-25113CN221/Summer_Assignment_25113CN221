#include <stdio.h>
#include <math.h>

// Function declaration

void add();
void subtract();
void multi();
void division();
void modulus();
void percentage();
void average();
void press_enter();

int main()
{

    int option; // to stor the choice of the user
    void (*menu[7])() = {add, subtract, multi, division, modulus, percentage, average};

    do
    {
        printf("===============================================\n");
        printf("*                  BASIC CALCULATOR           *\n");
        printf("===============================================\n\n");

        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Percentage\n7. Average\n8. Exit\n");

        printf("===============================================\n");
        printf("\nEnter your choice:_");
        scanf("%d", &option);

        if (option >= 1 && option <= 7)
        {
            menu[option - 1]();
            press_enter();
        }
        else if (option == 8)
        {
            printf("\nExiting Program. GoodBye!\n");
        }
        else
            printf("\nInvalid Input! Please Try Again.\n");

    } while (option != 8);

    return 0;
}

// Function definition

// function to add number
void add()
{
    printf("\n----- Addition -----\n\n");
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    printf("\n%.2f + %.2f = %.2f\n", num1, num2, num2 + num1);

    return;
}

// function to subtract numbers
void subtract()
{
    printf("\n----- Subtraction -----\n\n");
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    printf("\n%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);

    return;
}

// function to multiply numbers
void multi()
{
    printf("\n----- Multiplication -----\n\n");
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    printf("\n%.2f * %.2f = %.2f\n", num1, num2, num2 * num1);

    return;
}

// function to divide numbers
void division()
{
    printf("\n----- Division -----\n\n");
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    if (num2 == 0.0f)
    {
        printf("\nDivision by zero is not possible!\n");
        return;
    }
    printf("\n%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);

    return;
}

// function to find modulus
void modulus()
{
    printf("\n----- Modulus -----\n\n");
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    if (num2 == 0)
    {
        printf("\nDivision by zero is not possible!\n");
        return;
    }

    printf("\n%d %% %d = %d\n", num1, num2, num1 % num2);

    return;
}
void percentage()
{
    printf("\n----- Percentage -----\n");

    int n; // no of subjects
    printf("Enter the number of subjects: ");
    scanf("%d", &n);

    int sub[n], sum = 0;
    printf("Enter the marks of each subject out of 100: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sub[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sum += sub[i];
    }

    // calculate percentage
    float percent = (sum * 100.0) / (n * 100);

    printf("\nPercentage = %.2f%%\n", percent);

    return;
}

// function average
void average()
{
    printf("\nHow many numbers are there: ");
    int n; // number of numbers to find average
    scanf("%d", &n);

    int num[n];
    printf("Enter the number: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += num[i];
    }

    float average = (float)sum / n;

    printf("\nAverage = %.2f\n", average);

    return;
}

// press enter feature to make easy experience
void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}
