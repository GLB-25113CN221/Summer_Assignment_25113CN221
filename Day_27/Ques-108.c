#include <stdio.h>
#include <string.h>

#define MAX_EMP 100

struct student
{
    int roll;
    char name[50];
    int marks[5];
    int total;
    float per;
    char grade;
};

void press_enter();
char calculate_grade(float per);
int add_student(struct student s[], int n);
int display_all(struct student s[], int n);
int search_student(struct student s[], int n);
int generate_marksheet(struct student s[], int n);
void Bubble_sort(struct student s[], int num);

int main()
{

    // Q-108 Write a program to create marksheet generation system

    printf("\n==================================================\n");
    printf("          | MARKSHEET MANAGEMENT SYSTEM |\n");
    printf("==================================================\n\n");

    struct student s[MAX_EMP];
    int option = 0; // to store option selected by th user
    int i = 0;      // traces number of employee
    int (*menu[4])(struct student s[], int) = {add_student, display_all, search_student, generate_marksheet};

    do
    {
        printf("----- MENU -----\n");
        printf("\n1. Add Student\n2. Display All\n3. Search Student\n4. Generate Marksheet\n5. Exit\n");
        printf("\nEnter your choice:_ ");
        scanf("%d", &option);

        if (option >= 1 && option <= 4)
        {
            i = menu[option - 1](s, i);
        }
        else if (option == 5)
        {
            printf("\nExiting Program. Goodbye!\n\n");
            break;
        }
        else
        {
            printf("\nInvalid Input. Please Try Again.\n\n");
            press_enter();
        }
    } while (option != 5);

    return 0;
}

void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

int add_student(struct student s[], int n)
{
    printf("\n----- Add Student -----\n");

    int num; // Enter the number of students to add

    printf("\nEnter the number of  student to add: ");
    scanf("%d", &num);

    for (int i = n; i < (n + num); i++)
    {

        printf("\nStudent %d", i);
        printf("\nRoll Number: ");
        scanf("%d", &s[i].roll);
        printf("\nName: ");
        getchar();

        fgets(s[i].name, sizeof(s[i].name), stdin);

        int len = strlen(s[i].name);
        if (len > 0 && s[i].name[len - 1] == '\n')
            s[i].name[len - 1] = '\0';

        printf("\nEnter marks of five subjects: ");
        scanf("%d%d%d%d%d", &s[i].marks[0], &s[i].marks[1], &s[i].marks[2], &s[i].marks[3], &s[i].marks[4]);
        s[i].total = s[i].marks[0] + s[i].marks[1] + s[i].marks[2] + s[i].marks[3] + s[i].marks[4];
        s[i].per = s[i].total / 5;
        s[i].grade = calculate_grade(s[i].per);
        printf("\nStudent added successfully!\nPercentage: %.2f\nGrade: %c", s[i].per, s[i].grade);
    }

    return n + num;
}

int display_all(struct student s[], int n)
{
    if (n == 0)
    {
        printf("\nNo students found!\n");
        return n;
    }
    printf("\n============================================================\n");
    printf("                    STUDENT MARK LIST\n");
    printf("============================================================\n");
    printf("Roll\tName\t\tM1\tM2\tM3\tM4\tM5\tTotal\t%%\tGrade\n");
    printf("------------------------------------------------------------\n");

    Bubble_sort(s, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t", s[i].roll, s[i].name);
        for (int j = 0; j < 5; j++)
            printf("%d\t", s[i].marks[j]);
        printf("%d\t%.2f\t%c\n", s[i].total, s[i].per, s[i].grade);
    }
    printf("------------------------------------------------------------\n");
    printf("Total Students: %d\n", n);

    return n;
}
int search_student(struct student s[], int n)
{
    int roll, found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\nStudent Found!\n");

            printf("Roll: %d\nName: %s\n", s[i].roll, s[i].name);
            printf("Marks: ");
            for (int j = 0; j < 5; j++)
                printf("%d ", s[i].marks[j]);
            printf("\nTotal: %d\nPercentage: %.2f%%\nGrade: %c\n",
                   s[i].total, s[i].per, s[i].grade);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nStudent with Roll %d not found!\n", roll);

    return n;
}
int generate_marksheet(struct student s[], int n)
{
    int roll, found = 0;

    printf("\nEnter Roll Number for Marksheet: ");
    scanf("%d", &roll);

    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == roll)
        {
            found = 1;
            printf("\n========================================\n");
            printf("            MARK SHEET\n");
            printf("========================================\n");
            printf("Roll Number: %d\n", s[i].roll);
            printf("Name       : %s\n ", s[i].name);
            printf("-----------------------------------------\n");
            printf("Subject     :  Marks\n");
            printf("-----------------------------------------\n");
            for (int j = 0; j < 5; j++)
            {
                printf("Subject %d   : %d\n", j + 1, s[i].marks[j]);
            }
            printf("-----------------------------------------\n");
            printf("Total       : %d\n", s[i].total);
            printf("Percentage  : %.2f\n", s[i].per);
            printf("Grade       : %c\n", s[i].grade);
            printf("==========================================\n");

            break;
        }

        if (!found)
            printf("\nStudent not found!\n");
    }

    return n;
}
char calculate_grade(float per)
{
    if (per >= 90)
        return 'A';
    else if (per >= 75)
        return 'B';
    else if (per >= 60)
        return 'C';
    else if (per >= 40)
        return 'D';
    else
        return 'F';
}
void Bubble_sort(struct student s[], int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            int flag = 0; // flag to tell if the elements should be swapped or not

            if (s[j].roll > s[j + 1].roll)
                flag = 1;

            if (flag == 1)
            {
                struct student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}