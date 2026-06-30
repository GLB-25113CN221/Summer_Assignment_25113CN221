#include <stdio.h>
#include <string.h>

#define MAX 100

struct employee
{
    int id;
    char name[50];
    char dept[30];
    char desig[30];
    float salary;
};

struct employee emp[MAX];
int count = 0;

void add_emp();
void display_emp();
void search_emp();
void update_emp();
void delete_emp();
void press_enter();

int main()
{
    int choice;
    void (*menu[5])() = {add_emp, display_emp, search_emp, update_emp, delete_emp};

    printf("\n========================================\n");
    printf("     MINI EMPLOYEE MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    do
    {
        printf("\n1. Add Employee\n2. Display All\n3. Search Employee\n4. Update Employee\n5. Delete Employee\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5)
        {
            menu[choice - 1]();
            press_enter();
        }
        else if (choice == 6)
            printf("\nExiting... Goodbye!\n");
        else
            printf("\nInvalid choice!\n");

    } while (choice != 6);

    return 0;
}

void add_emp()
{
    if (count >= MAX)
    {
        printf("\nLimit exceeded!\n");
        return;
    }

    int n;
    printf("\nEnter number of employees to add: ");
    scanf("%d", &n);

    for (int i = 0; i < n && count < MAX; i++, count++)
    {
        printf("\nEmployee %d:\n", count + 1);
        printf("ID: ");
        scanf("%d", &emp[count].id);

        for (int j = 0; j < count; j++)
        {
            if (emp[j].id == emp[count].id)
            {
                printf("\nID already exists!\n");
                count--;
                return;
            }
        }

        printf("Name: ");
        getchar();
        fgets(emp[count].name, 50, stdin);
        emp[count].name[strcspn(emp[count].name, "\n")] = '\0';

        printf("Department: ");
        fgets(emp[count].dept, 30, stdin);
        emp[count].dept[strcspn(emp[count].dept, "\n")] = '\0';

        printf("Designation: ");
        fgets(emp[count].desig, 30, stdin);
        emp[count].desig[strcspn(emp[count].desig, "\n")] = '\0';

        printf("Salary: ");
        scanf("%f", &emp[count].salary);

        printf("\nEmployee added!\n");
    }
}

void display_emp()
{
    if (count == 0)
    {
        printf("\nNo employees found!\n");
        return;
    }

    printf("\n========================================\n");
    printf("          EMPLOYEE LIST\n");
    printf("========================================\n");
    printf("ID  | Name                | Dept      | Designation   | Salary\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-4d| %-19s | %-9s | %-13s | %.2f\n",
               emp[i].id, emp[i].name, emp[i].dept, emp[i].desig, emp[i].salary);
    }
    printf("----------------------------------------\n");
    printf("Total Employees: %d\n", count);
}

void search_emp()
{
    if (count == 0)
    {
        printf("\nNo employees found!\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (emp[i].id == id)
        {
            printf("\nEmployee Found!\n");
            printf("Name: %s\n", emp[i].name);
            printf("Department: %s\n", emp[i].dept);
            printf("Designation: %s\n", emp[i].desig);
            printf("Salary: %.2f\n", emp[i].salary);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nEmployee not found!\n");
}

void update_emp()
{
    if (count == 0)
    {
        printf("\nNo employees found!\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (emp[i].id == id)
        {
            printf("\nCurrent Details:\n");
            printf("Name: %s\n", emp[i].name);
            printf("Department: %s\n", emp[i].dept);
            printf("Designation: %s\n", emp[i].desig);
            printf("Salary: %.2f\n", emp[i].salary);

            printf("\nEnter New Details:\n");
            printf("Name: ");
            getchar();
            fgets(emp[i].name, 50, stdin);
            emp[i].name[strcspn(emp[i].name, "\n")] = '\0';

            printf("Department: ");
            fgets(emp[i].dept, 30, stdin);
            emp[i].dept[strcspn(emp[i].dept, "\n")] = '\0';

            printf("Designation: ");
            fgets(emp[i].desig, 30, stdin);
            emp[i].desig[strcspn(emp[i].desig, "\n")] = '\0';

            printf("Salary: ");
            scanf("%f", &emp[i].salary);

            printf("\nEmployee updated!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nEmployee not found!\n");
}

void delete_emp()
{
    if (count == 0)
    {
        printf("\nNo employees found!\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (emp[i].id == id)
        {
            printf("\nEmployee Found: %s\n", emp[i].name);
            printf("Are you sure? (y/n): ");
            char ch;
            scanf(" %c", &ch);

            if (ch == 'y' || ch == 'Y')
            {
                for (int j = i; j < count - 1; j++)
                    emp[j] = emp[j + 1];
                count--;
                printf("\nEmployee deleted!\n");
            }
            else
                printf("\nDeletion cancelled!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nEmployee not found!\n");
}

void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}