#include <stdio.h>
#include <string.h>

struct student
{
    int roll_no;
    int class;
    char sec;
    float percentage;
    char name[20];
    char last_name[20];
};

void Bubble_sort(struct student stud[], int num, int choice)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            int flag = 0; // flag to tell if the elements should be swapped or not
            if (choice == 1 && stud[j].percentage < stud[j + 1].percentage)
                flag = 1;

            if (choice == 2 && stud[j].roll_no > stud[j + 1].roll_no)
                flag = 1;

            if (flag == 1)
            {
                struct student temp = stud[j];
                stud[j] = stud[j + 1];
                stud[j + 1] = temp;
            }
        }
    }
}

void display_student(struct student s)
{

    printf("Name: %s %s", s.name, s.last_name);
    printf("Roll Number: %d\n", s.roll_no);
    printf("Class: %d", s.class);
    printf("Section: %c", s.sec);
    printf("Percentage: %f", s.percentage);
}

void press_enter()
{

    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void student_table(struct student s)
{

    printf("%d", s.roll_no);

    int digits = 1;
    int n = s.roll_no;
    while (n > 9)
    {
        digits++;
        n /= 10;
    }

    for (int k = 1; k <= 9 - digits; k++)
        printf(" ");

    printf("| %s %s", s.name, s.last_name);

    int temp = strlen(s.name) + strlen(s.last_name);

    for (int k = 1; k <= 21 - temp; k++)
        printf(" ");

    printf("| %2d     | %c   | %.2f\n", s.class, s.sec, s.percentage);
}

int main()
{

    // Q-105 Write a program to create library management system

    struct student stud[100] = {0}; // stud = an array of struct student type to store the info of the students

    int choice = 0; // to input the choice of the user
    int i = 0;      // no of students record

    printf("\n\n __________________________________\n");
    printf("| STUDENT RECORD MANAGEMENT SYSTEM |");
    printf("\n|__________________________________|\n");

    do
    {
        printf("\n\n==== MENU ====\n");
        printf("1. Add Student\n2. Display All Student\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Sort by Marks\n7. Save to File\n8. Load from File\n9. Exit\n");

        printf("\nEnter your choice: _");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("\n--- Add Student ---\n\n");

            int temp; // no of students the user needs to add

            printf("Enter the number of students to add:_");
            scanf("%d", &temp);

            for (int j = 0; j < temp; j++)
            {

                printf("\nEnter the details of student %d.", j + 1);
                printf("\nName: ");
                scanf("%s%s", stud[i].name, stud[i].last_name);

                printf("Roll Number: ");
                scanf("%d", &stud[i].roll_no);

                printf("Class: ");
                scanf("%d", &stud[i].class);

                printf("Section: ");
                scanf(" %c", &stud[i].sec);

                printf("Percentage: ");
                scanf("%f", &stud[i].percentage);

                i++;
                        }

            printf("\n%d students added successfully!\n", temp);

            press_enter();
            break;
        }

        case 2:
            printf("\n============================================================\n");
            printf("                        STUDENT LIST\n");
            printf("============================================================\n");
            printf("\nRoll no. | Name                  | Class  | Sec | Percentage\n");
            printf("------------------------------------------------------------\n");

            Bubble_sort(stud, i, 2);

            for (int j = 0; j < i; j++)
            {
                student_table(stud[j]);
            }
            printf("------------------------------------------------------------\n");

            printf("Total Students: %d\n", i);

            press_enter();
            break;

        case 3:
            printf("\n---- Search Student ----\n\n");
            printf("Enter the Roll Number to search: ");

            int search, found = 0;
            scanf("%d", &search);

            for (int j = 0; j < i; j++)
            {
                if (search == stud[j].roll_no)
                {
                    printf("\nStudent Found!\n\n");
                    display_student(stud[j]);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
                printf("Student with Roll Number %d not found!\n", search);

            press_enter();
            break;

        case 4:
            printf("\n---- Update Student ----\n\n");
            printf("Enter Roll Number to update: ");

            int update, found_1 = 0;
            scanf("%d", &update);

            printf("\nCurrent Details: ");
            for (int j = 0; j < i; j++)
            {
                if (update == stud[j].roll_no)
                {
                    printf("\nStudent Found!\n\n");
                    display_student(stud[j]);

                    printf("\nEnter New Details: \n");
                    printf("Name: ");
                    scanf("%s%s", stud[j].name, stud[j].last_name);
                    printf("Class: ");
                    scanf("%d", &stud[j].class);
                    printf("Section: ");
                    scanf(" %c", &stud[j].sec);
                    printf("Percentage: ");
                    scanf("%f", &stud[j].percentage);

                    found_1 = 1;
                    break;
                }
            }
            if (found_1 == 0)
            {
                printf("Student with Roll Number %d not found!\n", update);
                printf("To add go to 'Add Student' section\n", update);
            }

            press_enter();
            break;

        case 5:
            int delete, found_2 = 0;
            printf("\n---- Delete Student ----\n");
            printf("\nEnter Roll Number to delete: ");
            scanf("%d", &delete);

            for (int j = 0; j < i; j++)
            {
                if (delete == stud[j].roll_no)
                {
                    printf("\nStudent Found:\n");
                    display_student(stud[j]);

                    printf("Are you sure you want to delete this record? (Y/N): ");
                    char y_n;
                    scanf(" %c", &y_n);

                    if (y_n == 'Y' || y_n == 'y')
                    {
                        for (int k = j; k < i - 1; k++)
                        {

                            stud[k].roll_no = stud[k + 1].roll_no;
                            strcpy(stud[k].name, stud[k + 1].name);
                            strcpy(stud[k].last_name, stud[k + 1].last_name);
                            stud[k].class = stud[k + 1].class;
                            stud[k].sec = stud[k + 1].sec;
                            stud[k].percentage = stud[k + 1].percentage;
                        }
                        i--;

                        printf("\nStudent record deleted successfully!\n");
                    }
                    else
                    {
                        printf("Deletion cancelled!");
                    }

                    found_2 = 1;
                    break;
                }
            }
            if (found_2 == 0)
            {
                printf("Student with Roll Number %d not found!\n", delete);
            }

            press_enter();
            break;

        case 6:
            printf("\n============================================================\n");
            printf("               STUDENT LIST (Sorted by Marks)\n");
            printf("============================================================\n");
            printf("\nRoll no. | Name                  | Class  | Sec | Percentage\n");
            printf("------------------------------------------------------------\n");

            Bubble_sort(stud, i, 1);

            for (int j = 0; j < i; j++)
            {
                student_table(stud[j]);
            }
            printf("------------------------------------------------------------\n");

            press_enter();
            break;

        case 7:
        {
            printf("\n---- Save to File ----\n\n");

            FILE *fp = NULL;
            fp = fopen("students.txt", "w");

            if (fp == NULL)
            {

                printf("Error opening file for writing!\n");
                press_enter();
                break;
            }

            // write number of student
            fprintf(fp, "%d\n", i);

            // write each student's data
            for (int j = 0; j < i; j++)
            {
                fprintf(fp, "%d\n", stud[j].roll_no);
                fprintf(fp, "%s\n", stud[j].name);
                fprintf(fp, "%s\n", stud[j].last_name);
                fprintf(fp, "%d\n", stud[j].class);
                fprintf(fp, "%c\n", stud[j].sec);
                fprintf(fp, "%.2f\n", stud[j].percentage);
            }

            fclose(fp);

            printf("Data saved successfully to 'student.txt'!\n");

            press_enter();
            break;
        }

        case 8:
        {
            printf("\n---- Load from File ----\n\n");

            FILE *fp = NULL;
            fp = fopen("students.txt", "r");

            if (fp == NULL)
            {
                printf("No saved data found. PLease add students first.\n");
                press_enter();
                break;
            }

            // read number of students
            fscanf(fp, "%d", &i);

            // read each student's data
            for (int j = 0; j < i; j++)
            {
                fscanf(fp, "%d", &stud[j].roll_no);
                fscanf(fp, "%s", stud[j].name);
                fscanf(fp, "%s", stud[j].last_name);
                fscanf(fp, "%d", &stud[j].class);
                fscanf(fp, " %c", &stud[j].sec);
                fscanf(fp, "%f", &stud[j].percentage);
            }

            fclose(fp);

            printf("Data loaded successfully from 'students.txt'!\n");

            press_enter();
            break;
        }

        case 9:
            printf("\n---- Exiting ----\n\n");
            printf("Thank you for using Student Record Management System.\n\n");

            press_enter();
            break;

        default:
            printf("Invalid Input!\nPlease Try Again.");

            press_enter();
        }
    } while (choice != 9);

    return 0;
}