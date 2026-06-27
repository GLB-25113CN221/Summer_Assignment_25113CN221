#include <stdio.h>
#include <string.h>

#define MAX_EMP 100

struct employee
{
    int id; // employee ID
    char first_name[25];
    char last_name[25];
    char department[50];
    char designation[50];
    float basic; // basic salary
    float da;    // dearness allowance
    float hra;   // house rent allowance
    float pf;    // provident fund
    float tax;   // income tax
    float net;   // net salary
};

void press_enter();
void bubble_sort(struct employee emp[], int n, int choice);
void enter_info(struct employee e);
void emp_info(struct employee e);
void emp_table(struct employee emp[], int n);
int add_emp(struct employee emp[], int n);
int display(struct employee emp[], int n);
int generate_payslip(struct employee emp[], int n);
void trim_newline(char str[]);

int main()
{

    // Q-107 Write a program to create salary management system.

    printf("\n==================================================\n");
    printf("          | SALARY MANAGEMENT SYSTEM |\n");
    printf("==================================================\n\n");

    struct employee emp[MAX_EMP];
    int option = 0; // to store option selected by th user
    int i = 0;      // traces number of employee
    int (*menu[3])(struct employee emp[], int) = {add_emp, display, generate_payslip};

    do
    {
        printf("----- MENU -----\n");
        printf("\n1. Add Employee\n2. Display all Employees\n3. Generate Pay Slip\n4. Exit\n");
        printf("\nEnter your choice:_ ");
        scanf("%d", &option);

        if (option >= 1 && option <= 3)
        {
            i = menu[option - 1](emp, i);
        }
        else if (option == 4)
        {
            printf("\nExiting Program. Goodbye!\n\n");
            break;
        }
        else
        {
            printf("\nInvalid Input. Please Try Again.\n\n");
            press_enter();
        }
    } while (option != 4);

    return 0;
}

void press_enter()
{
    printf("\nPress Enter to continue...");

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    getchar();
}

void enter_data(struct employee e)
{
    printf("\nEmployee ID: ");
    scanf("%d", &e.id);
    printf("\nFirst Name: ");
    scanf("%s", e.first_name);
    printf("\nLast Name: ");
    scanf("%s", e.last_name);
    printf("\nDepartment: ");
    scanf("%s", e.department);
    printf("\nDesignation: ");
    scanf("%s", e.designation);
    printf("\nBasic Salary: ");
    scanf("%f", &e.basic);
    printf("\nDearness Allowance(DA): ");
    scanf("%f", &e.da);
    printf("\nHouse Rent Allowance(HRA): ");
    scanf("%f", &e.hra);
    printf("\nProvident Fund: ");
    scanf("%f", &e.pf);
    printf("\nTax: ");
    scanf("%f", &e.tax);
    e.net = (e.basic + e.da + e.hra) - (e.pf + e.tax);
}

void emp_info(struct employee e)
{
    printf("\nEmployee ID: %d", e.id);
    printf("\nName: %s %s", e.first_name, e.last_name);
    printf("\nDepartment: %s", e.department);
    printf("\nDesignation: %s", e.designation);
    printf("----------------------------------------\n");
    printf("EARNING: ");
    printf("\nBasic Salary: %.2f", e.basic);
    printf("\nDA: %.2f", e.da);
    printf("\nHRA: %.2f", e.hra);
    printf("\n----------------------------------------\n");
    printf("Gross Salary: %.2f", e.basic + e.da + e.hra);
    printf("\nDEDUCTIONS: ");
    printf("\nPF: %.2f", e.pf);
    printf("\nTax: %.2f", e.tax);
    printf("\n----------------------------------------\n");
    printf("Total Deductions: %.2f", e.pf + e.tax);
    printf("\nNet Salary: %.2f", e.net);
    printf("\n=========================================\n");
}

void emp_table(struct employee emp[], int n)
{
    printf("ID        | Name                    | Department    | Basic Salary  | DA       | HRA      | PF       | Tax      | Net Salary \n");
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {

        int digit = 1, id = emp[i].id;

        while (id > 9)
        {
            digit++;
            id /= 10;
        }
        printf("%d", emp[i].id);
        for (int j = 0; j < 10 - digit; j++)
        {
            printf(" ");
        }
        printf("| %s %s", emp[i].first_name, emp[i].last_name);

        digit = strlen(emp[i].first_name) + strlen(emp[i].last_name);

        for (int j = 0; j < 23 - digit; j++)
        {
            printf(" ");
        }

        printf("| %s", emp[i].department);

        digit = strlen(emp[i].department);

        for (int j = 0; j < 14 - digit; j++)
        {
            printf(" ");
        }

        printf("| %.2f", emp[i].basic);
        digit = 1;
        float temp1 = emp[i].basic;
        while (temp1 > 9)
        {
            digit++;
            temp1 /= 10;
        }
        for (int j = 0; j < 12 - digit; j++)
        {
            printf(" ");
        }
        printf("| %.2f", emp[i].da);
        digit = 1;
        float temp2 = emp[i].da;
        while (temp2 > 9)
        {
            digit++;
            temp2 /= 10;
        }
        for (int j = 0; j < 7 - digit; j++)
        {
            printf(" ");
        }

        printf("| %.2f", emp[i].hra);
        digit = 1;
        float temp3 = emp[i].hra;
        while (temp3 > 9)
        {
            digit++;
            temp3 /= 10;
        }
        for (int j = 0; j < 7 - digit; j++)
        {
            printf(" ");
        }

        printf("| %.2f", emp[i].pf);
        digit = 1;
        float temp4 = emp[i].pf;
        while (temp4 > 9)
        {
            digit++;
            temp4 /= 10;
        }
        for (int j = 0; j < 7 - digit; j++)
        {
            printf(" ");
        }

        printf("| %.2f", emp[i].tax);
        digit = 1;
        float temp5 = emp[i].tax;
        while (temp5 > 9)
        {
            digit++;
            temp5 /= 10;
        }
        for (int j = 0; j < 7 - digit; j++)
        {
            printf(" ");
        }

        printf("| %.2f", (emp[i].basic + emp[i].da + emp[i].hra) - (emp[i].pf + emp[i].tax));
    }

    printf("\n--------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Total Employees: %d", n);
}

int add_emp(struct employee emp[], int n)
{
    printf("\n----- Add Employee -----\n");
    printf("\nEnter the number of Employees to add:_");
    int empy; // Number of employees to add
    scanf("%d", &empy);
    if ((empy + n) > MAX_EMP)
    {
        printf("\nLimit Exceeds. Please try again.\n");
        return n;
    }

    for (int i = 0; i < (empy); i++)
    {
        printf("\n----- Employee %d -----\n", n + 1);
        enter_data(emp[n]);
        printf("\n\nEmployee Added Successfully!\n");
        printf("Net Salary: %.2f\n", (emp[n].basic + emp[n].da + emp[n].hra) - (emp[n].pf + emp[n].tax));
        n++;
    }

    return n;
}

int display(struct employee emp[], int n)
{

    printf("\n============================================================\n");
    printf("                        SALARY LIST\n");
    printf("============================================================\n");

    bubble_sort(emp, n, 0);

    emp_table(emp, n);

    return n;
}

int generate_payslip(struct employee emp[], int n)
{
    printf("\n----- Generate Payslip ------\n");

    int id, found = 0;

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (emp[i].id == id)
        {
            found = 1;
            printf("\n========================================\n");
            printf("              PAY SLIP\n");
            printf("========================================\n");

            emp_info(emp[i]);
            break;
        }
    }

    if (!found)
        printf("\nEmployee not found!\n");

    return n;
}
