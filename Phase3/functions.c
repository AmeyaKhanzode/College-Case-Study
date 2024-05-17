#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void student_data(student *ptr, int pop)
{
    for (int i = 0; i < pop; i++)
    {
        printf("========== Data of Student %d ==========\n", i + 1);
        printf("Enter name: ");
        scanf("%s", ptr[i].name);

        printf("Enter sem number: ");
        scanf("%d", &ptr[i].sem);

        printf("Enter roll: ");
        scanf("%d", &ptr[i].roll);

        printf("Enter contact: ");
        char contact_str[20];
        scanf("%s", contact_str);
        ptr[i].contact = strtoll(contact_str, NULL, 10);
    }
    updateToFile(ptr, pop); // Save the data to the file after entering student information
}

void marks(student *ptr, int pop)
{
    for (int i = 0; i < pop; i++)
    {
        printf("========================= Marks of Student %d =========================\n", i + 1);
        printf("\n");
        printf("Enter Statistics (3 credits) Marks (ISA1 ISA2 ESA): ");
        scanf("%d %d %d", &ptr[i].isa1[0], &ptr[i].isa2[0], &ptr[i].esa[0]);

        printf("Enter C (5 credits) Marks (ISA1 ISA2 ESA): ");
        scanf("%d %d %d", &ptr[i].isa1[1], &ptr[i].isa2[1], &ptr[i].esa[1]);

        printf("Enter DSA (4 credits) Marks (ISA1 ISA2 ESA): ");
        scanf("%d %d %d", &ptr[i].isa1[2], &ptr[i].isa2[2], &ptr[i].esa[2]);
        printf("\n");
    }
    updateToFile(ptr, pop); // Save the data to the file after entering marks
}

int gp(float temp[], int n)
{
    int x = 0;
    if (temp[n] > 90 && temp[n] <= 100)
    {
        x = 10;
    }
    else if (temp[n] > 80 && temp[n] <= 90)
    {
        x = 9;
    }
    else if (temp[n] > 70 && temp[n] <= 80)
    {
        x = 8;
    }
    else if (temp[n] > 60 && temp[n] <= 70)
    {
        x = 7;
    }
    else if (temp[n] > 50 && temp[n] <= 60)
    {
        x = 6;
    }
    else if (temp[n] > 40 && temp[n] <= 50)
    {
        x = 5;
    }
    else
    {
        x = 0;
    }
    return x;
}

void sgpa(int k, student *ptr)
{
    float score1 = 0, score2 = 0, score3 = 0;
    score1 += ((ptr[k].isa1[0] + ptr[k].isa2[0] + ptr[k].esa[0]) / 2.0) + 10;
    score2 += ((ptr[k].isa1[1] + ptr[k].isa2[1] + ptr[k].esa[1]) / 2.0) + 10;
    score3 += ((ptr[k].isa1[2] + ptr[k].isa2[2] + ptr[k].esa[2]) / 2.0) + 10;

    float temp[] = {score1, score2, score3};

    int gpa = 0;

    for (int i = 0; i < 3; i++)
    {
        int x;
        if (i == 0)
        {
            x = gp(temp, i);
            gpa += 3 * x;
        }
        else if (i == 1)
        {
            x = gp(temp, i);
            gpa += 5 * x;
        }
        else
        {
            x = gp(temp, i);
            gpa += 4 * x;
        }
    }

    float sgpa = gpa / 12.0;
    ptr[k].sgpa = sgpa;
}

void card(student *ptr, int pop)
{
    printf("Student Names:\n");
    for (int i = 0; i < pop; i++)
    {
        printf("%d. %s\n", i + 1, ptr[i].name);
    }

    int user_input;
    char grade;

    printf("Choose which student's grade card to be printed: ");
    scanf("%d", &user_input);

    sgpa(user_input - 1, ptr);

    float Sgpa = ptr[user_input - 1].sgpa;

    if (Sgpa > 9 && Sgpa <= 10)
    {
        grade = 'S';
    }
    else if (Sgpa > 8 && Sgpa <= 9)
    {
        grade = 'A';
    }
    else if (Sgpa > 7 && Sgpa <= 8)
    {
        grade = 'B';
    }
    else if (Sgpa > 6 && Sgpa <= 7)
    {
        grade = 'C';
    }
    else if (Sgpa > 5 && Sgpa <= 6)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }
    printf("\n");
    printf("====================================================================\n");
    printf("\t\t\t    GRADE CARD\n");
    printf("%-5s%s\n", "Name : ", ptr[user_input - 1].name);

    printf("%-5s%d\t\t\t\t\t%-1s%.2f\n", "Semester : ", ptr[user_input - 1].sem, "SGPA : ", Sgpa);
    printf("%-10s%d\t\t\t\t\t%-1s%c\n", "Roll No. : ", ptr[user_input - 1].roll, "Grade : ", grade);
    printf("%-15s%lld\n", "Contact No. : ", ptr[user_input - 1].contact);

    printf("--------------------------------------------------------------------\n");

    printf("%-20s\t%-8s\t%-8s\t%-8s\n", "Subject", "ISA1", "ISA2", "ESA");
    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            printf("%-21s\t", "Statistics");
            printf("%-8d\t%-8d\t%-8d\n", ptr[user_input - 1].isa1[0], ptr[user_input - 1].isa2[0], ptr[user_input - 1].esa[0]);
        }
        else if (i == 1)
        {
            printf("%-21s\t", "Problem Solving With C");
            printf("%-8d\t%-8d\t%-8d\n", ptr[user_input - 1].isa1[1], ptr[user_input - 1].isa2[1], ptr[user_input - 1].esa[1]);
        }
        else
        {
            printf("%-21s\t", "DSA");
            printf("%-8d\t%-8d\t%-8d\n", ptr[user_input - 1].isa1[2], ptr[user_input - 1].isa2[2], ptr[user_input - 1].esa[2]);
        }
    }
    printf("====================================================================\n");
}

void updateToFile(student *ptr, int pop)
{
    FILE *fp;
    fp = fopen("StudentData.csv", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // Write the header
    fprintf(fp, "Name,Sem,Roll,Contact,ISA1_Stats,ISA2_Stats,ESA_Stats,ISA1_C,ISA2_C,ESA_C,ISA1_DSA,ISA2_DSA,ESA_DSA\n");

    // Write the data
    for (int i = 0; i < pop; i++)
    {
        fprintf(fp, "%s,%d,%d,%lld,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
                ptr[i].name, ptr[i].sem, ptr[i].roll, ptr[i].contact,
                ptr[i].isa1[0], ptr[i].isa2[0], ptr[i].esa[0],
                ptr[i].isa1[1], ptr[i].isa2[1], ptr[i].esa[1],
                ptr[i].isa1[2], ptr[i].isa2[2], ptr[i].esa[2]);
    }

    fclose(fp);
}

void readFromFile(student *ptr, int pop)
{
    FILE *fp;
    fp = fopen("StudentData.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char buffer[1024];
    int row = 0;

    // Skip the header line
    fgets(buffer, sizeof(buffer), fp);

    while (fgets(buffer, sizeof(buffer), fp) && row < pop)
    {
        sscanf(buffer, "%49[^,],%d,%d,%lld,%d,%d,%d,%d,%d,%d,%d,%d,%d",
               ptr[row].name,
               &ptr[row].sem,
               &ptr[row].roll,
               &ptr[row].contact,
               &ptr[row].isa1[0], &ptr[row].isa2[0], &ptr[row].esa[0],
               &ptr[row].isa1[1], &ptr[row].isa2[1], &ptr[row].esa[1],
               &ptr[row].isa1[2], &ptr[row].isa2[2], &ptr[row].esa[2]);
        row++;
    }

    fclose(fp);
}
