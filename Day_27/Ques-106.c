#include <stdio.h>
#include <string.h>

// struct variable definition
struct employee
{
    int emp_id;
    char first_name[20];
    char last_name[20];
    char depart[20];
    char designation[20];
    float salary;
    long long int phone;
    char email[50];
};

// Function Declarations
void press_enter();
void bubble_sort(struct employee emp[], int n, int choice);
void display_emp(struct employee e);
void trim_newline(char str[]);
int add(struct employee emp[], int n);
int display(struct employee emp[], int n);
int search(struct employee emp[], int n);
int update(struct employee emp[], int n);
int delete_emp(struct employee emp[], int n);
int sort_salary(struct employee emp[], int n);
int save_file(struct employee emp[], int n);
int load_file(struct employee emp[], int n);

int main()
{

    // Q-106 Write a program to Create employee management system.

    int choice = 0; // To record the input choice of the user
    int i = 0;      // index to count no of employees in record
    struct employee emp[100];

    printf("\n===================================================\n");
    printf("         EMPLOYEE RECORD MANAGEMENT SYSTEM\n");
    printf("===================================================\n\n");

    do
    {
        printf("\n----- MENU -----");
        printf("\n\n1. Add Employee\n2. Display all Employees\n3. Search Employee\n4. Update Employee\n5. Delete Employee\n6. Sort by Salary (Descending)\n7. Save to File\n8. Load from File\n9. Exit\n");

        printf("\nEnter your choice: _");
        scanf("%d", &choice);

        int (*menu[8])(struct employee[], int) = {add, display, search, update, delete_emp, sort_salary, save_file, load_file};

        if (choice >= 1 && choice < 9)
        {
            i = menu[choice - 1](emp, i);
        }
        else if (choice == 9)
        {
            printf("\nExiting program. Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid Input. Please try again.\n");
            press_enter();
        }

    } while (choice != 9);

    return 0;
}

void press_enter()
{

    printf("Press enter to continue...");
    getchar();
    getchar();
}

void bubble_sort(struct employee emp[], int n, int choice)
{

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {

            int swap = 0; // to check if we need to swap two number sor not

            if (choice == 0)
            {
                if (emp[j].emp_id > emp[j + 1].emp_id)
                    swap = 1;
            }
            if (choice == 1)
            {
                if (emp[j].salary < emp[j + 1].salary)
                    swap = 1;
            }

            if (swap == 1)
            {
                struct employee sWap = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = sWap;
            }
        }
    }
}

void display_emp(struct employee e)
{
    printf("Employee ID: %d", e.emp_id);
    printf("\nName: %s %s", e.first_name, e.last_name);
    printf("\nDepartment: %s", e.depart);
    printf("\nDesignation: %s", e.designation);
    printf("\nSalary: %.2f", e.salary);
    printf("\nPhone Number: %lld", e.phone);
    printf("\nEmail: %s\n", e.email);
}

int add(struct employee emp[], int n)
{
    int temp; // to input the number of employee to add

    printf("\n\nEnter the number of employee to add: _ ");
    scanf("%d", &temp);

    if (n + temp > 100)
    {
        printf("Cannot add more employees. Storage full.\n");
        return n;
    }

    for (int i = 1; i <= temp; i++)
    {
        printf("\n\n---- Employee %d ----:\n\n", i);
        printf("Employee ID: _");
        scanf("%d", &emp[n].emp_id);
        printf("First Name: _");
        scanf("%19s", emp[n].first_name);
        printf("Last Name: _");
        scanf("%19s", emp[n].last_name);
        getchar();
        printf("Department: _");
        fgets(emp[n].depart, sizeof(emp[n].depart), stdin);
        trim_newline(emp[n].depart);
        printf("Designation: _");
        fgets(emp[n].designation, sizeof(emp[n].designation), stdin);
        trim_newline(emp[n].designation);
        printf("Salary: _");
        scanf("%f", &emp[n].salary);
        printf("Phone Number: _");
        scanf("%lld", &emp[n].phone);
        printf("Email: _");
        scanf("%49s", emp[n].email);

        printf("\nEmployee added successfully!\n\n");

        n++;
    }
    press_enter();

    return n;
}

int display(struct employee emp[], int n)
{
    printf("==============================================================================================================\n");
    printf("                                                EMPLOYEE LIST\n");
    printf("==============================================================================================================\n");

    printf("ID    | Name                 | Department       | Designation      | Salary      | Phone      | Email\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");

    bubble_sort(emp, n, 0);

    for (int i = 0; i < n; i++)
    {

        int digit = 1, roll = emp[i].emp_id;

        while (roll > 9)
        {
            roll /= 10;
            digit++;
        }

        printf("%d", emp[i].emp_id);

        for (int j = 1; j <= 6 - digit; j++)
            printf(" ");

        printf("| %s %s", emp[i].first_name, emp[i].last_name);

        digit = strlen(emp[i].first_name) + strlen(emp[i].last_name);

        for (int j = 1; j <= 20 - digit; j++)
            printf(" ");

        printf("| %s", emp[i].depart);

        for (int j = 0; j < 17 - strlen(emp[i].depart); j++)
            printf(" ");

        printf("| %s", emp[i].designation);

        for (int j = 0; j < 17 - strlen(emp[i].designation); j++)
            printf(" ");

        printf("| %.2f", emp[i].salary);

        digit = 1;
        float roLl = emp[i].salary;

        while (roLl > 9)
        {
            roLl /= 10;
            digit++;
        }

        for (int j = 0; j < 9 - digit; j++)
            printf(" ");

        printf("| %lld | %s", emp[i].phone, emp[i].email);

        printf("\n");
    }

    printf("--------------------------------------------------------------------------------------------------------------\n");

    printf("\nTotal Employee: %d\n", n);

    return n;
}

int search(struct employee emp[], int n)
{

    int search; // enter the employee id of the employee to search

    printf("\n---- Search Employee ----\n\n");
    printf("Enter the ID of the employee to search: _");
    scanf("%d", &search);

    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (search == emp[i].emp_id)
        {
            printf("\nEmployee Found!\n");
            printf("------------------------\n\n");

            printf("Employee ID: %d", emp[i].emp_id);
            printf("\nName: %s %s", emp[i].first_name, emp[i].last_name);
            printf("\nDepartment: %s", emp[i].depart);
            printf("\nDesignation: %s", emp[i].designation);
            printf("\nSalary: %.2f", emp[i].salary);
            printf("\nPhone Number: %lld", emp[i].phone);
            printf("\nEmail: %s", emp[i].email);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Employee with ID %d not found!", search);
    }
    press_enter();
    return n;
}

int update(struct employee emp[], int n)
{
    int search, emp_index = -1; // search = Id of the employ to update
    // emp_index = index of the employee

    printf("\n---- Update Employee Data ----\n\n");
    printf("Enter the employee ID to update info: ");
    scanf("%d", &search);

    for (int i = 0; i < n; i++)
    {

        if (search == emp[i].emp_id)
        {
            emp_index = i;
            break;
        }
    }

    if (emp_index == -1)
    {
        printf("Element not found.\n");
        press_enter();
        return n;
    }

    printf("\nElement Found!\n\n");
    display_emp(emp[emp_index]);

    press_enter();

    printf("\nEnter the updated info: \n");

    printf("Employee ID: _");
    scanf("%d", &emp[emp_index].emp_id);
    printf("First Name: _");
    scanf("%19s", emp[emp_index].first_name);
    printf("Last Name: _");
    scanf("%19s", emp[emp_index].last_name);
    getchar();
    printf("Department: _");
    fgets(emp[emp_index].depart, sizeof(emp[emp_index].depart), stdin);
    trim_newline(emp[emp_index].depart);
    printf("Designation: _");
    fgets(emp[emp_index].designation, sizeof(emp[emp_index].designation), stdin);
    trim_newline(emp[emp_index].designation);
    printf("Salary: _");
    scanf("%f", &emp[emp_index].salary);
    printf("Phone Number: _");
    scanf("%lld", &emp[emp_index].phone);
    printf("Email: _");
    scanf("%49s", emp[emp_index].email);

    printf("\nInfo updated successfully!\n\n");

    press_enter();

    return n;
}

int delete_emp(struct employee emp[], int n)
{
    int search, emp_index = -1;
    // search = to search the element, emp_index = the index of the element tp delete

    printf("\n---- Delete Employee ----\n\n");
    printf("\nEnter the Employee ID to delete: ");
    scanf("%d", &search);

    for (int i = 0; i < n; i++)
    {

        if (search == emp[i].emp_id)
        {
            emp_index = i;
            break;
        }
    }

    if (emp_index == -1)
    {
        printf("\nElement not found. Please try again.\n");
        press_enter();
        return n;
    }

    printf("\nElement found:\n");
    printf("-------------------\n");
    display_emp(emp[emp_index]);

    char y_n; // to store decision
    printf("\nAre you sure you want to delete?(Y/N): ");
    scanf(" %c", &y_n);

    if (y_n == 'y' || y_n == 'Y')
    {

        for (int i = emp_index; i < n - 1; i++)
        {
            emp[i] = emp[i + 1];
        }
        n--;
        printf("\nEmployee deleted successfully!\n");
    }
    else
    {
        printf("\nDeletion cancelled.\n");
    }

    press_enter();
    return n;
}

int sort_salary(struct employee emp[], int n)
{
    printf("==============================================================================================================\n");
    printf("                                     EMPLOYEE LIST (Sorted By Salary)\n");
    printf("==============================================================================================================\n");

    printf("ID    | Name                 | Department       | Designation      | Salary      | Phone      | Email\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");

    bubble_sort(emp, n, 1);

    for (int i = 0; i < n; i++)
    {

        int digit = 1, roll = emp[i].emp_id;

        while (roll > 9)
        {
            roll /= 10;
            digit++;
        }

        printf("%d", emp[i].emp_id);

        for (int j = 1; j <= 6 - digit; j++)
            printf(" ");

        printf("| %s %s", emp[i].first_name, emp[i].last_name);

        digit = strlen(emp[i].first_name) + strlen(emp[i].last_name);

        for (int j = 1; j <= 20 - digit; j++)
            printf(" ");

        printf("| %s", emp[i].depart);

        for (int j = 0; j < 17 - strlen(emp[i].depart); j++)
            printf(" ");

        printf("| %s", emp[i].designation);

        for (int j = 0; j < 17 - strlen(emp[i].designation); j++)
            printf(" ");

        printf("| %.2f", emp[i].salary);

        digit = 1;
        float roLl = emp[i].salary;

        while (roLl > 9)
        {
            roLl /= 10;
            digit++;
        }

        for (int j = 0; j < 9 - digit; j++)
            printf(" ");

        printf("| %lld | %s", emp[i].phone, emp[i].email);

        printf("\n");
    }

    printf("--------------------------------------------------------------------------------------------------------------\n");

    printf("\nTotal Employee: %d\n", n);

    return n;
}

int save_file(struct employee emp[], int n)
{
    printf("\n---- Save to File ----\n\n");

    if (n < 1)
    {
        printf("\nNo employees to save!\n");
        press_enter();
        return n;
    }

    FILE *fp = NULL;
    fp = fopen("employee.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file for writing.\n");
        press_enter();
        return n;
    }

    // write number of employees
    fprintf(fp, "%d\n", n);

    // write each employees data
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", emp[i].emp_id);
        fprintf(fp, "%s\n", emp[i].first_name);
        fprintf(fp, "%s\n", emp[i].last_name);
        fprintf(fp, "%s\n", emp[i].depart);
        fprintf(fp, "%s\n", emp[i].designation);
        fprintf(fp, "%f\n", emp[i].salary);
        fprintf(fp, "%lld\n", emp[i].phone);
        fprintf(fp, "%s\n", emp[i].email);
    }

    fclose(fp);

    printf("\nData saved successfully to 'employee.txt'!\n");
    press_enter();

    return n;
}

int load_file(struct employee emp[], int n)
{
    printf("\n---- Load to File ----\n\n");

    FILE *fp = NULL;
    fp = fopen("employee.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo saved data found. Please add employee first.\n");

        press_enter();
        return n;
    }

    // read the number of employees int the file
    int temp; // no of employees in the file

    fscanf(fp, "%d", &temp);

    // read each employee's data
    for (int i = 0; i < (temp); i++)
    {
        fscanf(fp, "%d\n", &emp[i].emp_id);
        fscanf(fp, "%s\n", emp[i].first_name);
        fscanf(fp, "%s\n", emp[i].last_name);
        /*fscanf(fp, "%s\n", emp[i].depart);
        fscanf(fp, "%s\n", emp[i].designation);*/
        fgets(emp[i].depart, sizeof(emp[i].depart), fp);
        trim_newline(emp[i].depart);

        fgets(emp[i].designation, sizeof(emp[i].designation), fp);
        trim_newline(emp[i].designation);
        fscanf(fp, "%f\n", &emp[i].salary);
        fscanf(fp, "%lld\n", &emp[i].phone);
        fscanf(fp, "%s\n", emp[i].email);
    }

    printf("\nData loaded successfully from 'employee.txt'!\n");
    printf("%d records loaded.\n", temp);
    press_enter();

    return temp;
}

void trim_newline(char str[])
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}