#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

void student_data(struct student *ptr, int pop)
{
    for (int i = 0; i < pop; i++)
    {
        printf("========== Data of Student %d ==========\n",i+1);
        printf("Enter name : ");
        scanf("%s",ptr[i].name);

        printf("Enter sem number : ");
        scanf("%d",&ptr[i].sem);

        printf("Enter roll : ");
        scanf("%d",&ptr[i].roll);

        printf("Enter contact : ");
        scanf("%lld",&ptr[i].contact);
        printf("\n");
    }
}

void marks(struct student *ptr, int pop)
{
    for (int i = 0; i < pop; i++)
    {      
        printf("=========================Marks of Student %d=========================\n",i+1);
        printf("\n");
        printf("Enter Statistics (3 credits) Marks (ISA1 ISA2 ESA) : ");
        scanf("%d %d %d", &ptr[i].isa1[0], &ptr[i].isa2[0], &ptr[i].esa[0]);
    
        printf("Enter C (5 credits) Marks (ISA1 ISA2 ESA) : ");
        scanf("%d %d %d", &ptr[i].isa1[1], &ptr[i].isa2[1], &ptr[i].esa[1]);
    
        printf("Enter DSA (4 credits) Marks (ISA1 ISA2 ESA) : ");
        scanf("%d %d %d", &ptr[i].isa1[2], &ptr[i].isa2[2], &ptr[i].esa[2]);
        printf("\n");
    }
}

float gp(float temp[], int n)
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

void sgpa(int k,struct student *ptr)
{
    float score1 = 0,score2 = 0,score3 = 0;
    score1 += (ptr[k].isa1[0] + ptr[k].isa2[0] + ptr[k].esa[0])/2 + 10;
    score2 += (ptr[k].isa1[1] + ptr[k].isa2[1] + ptr[k].esa[1])/2 + 10;
    score3 += (ptr[k].isa1[2] + ptr[k].isa2[2] + ptr[k].esa[2])/2 + 10;

    float temp[] = {score1,score2,score3};


    int gpa = 0;
    
    for (int i = 0; i < 3; i++)
    {
        int x;
        if (i == 1)
        {
            x = gp(temp,i);
            gpa += 3*x;
        }
        else if (i == 2)
        {
            x = gp(temp,i);
            gpa += 5*x;
        }
        else
        {
            x = gp(temp,i);
            gpa += 4*x;
        }
    }
    
    float sgpa = gpa/12.0;
    ptr->sgpa = sgpa;
}


void card(struct student *ptr, int pop)
{
    printf("Student Names:\n");
    for (int i = 0; i < pop; i++)  
    {
        printf("%d. %s\n", i + 1, ptr[i].name);
    }  

    int user_input;
    char grade;
    
    printf("Choose which student's grade card to be printed : ");
    scanf("%d",&user_input);

    sgpa(user_input-1,ptr);

    float Sgpa = ptr[user_input-1].sgpa;

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
    printf("%-5s%s\n","Name : ",ptr[user_input-1].name);

    printf("%-5s%d\t\t\t\t\t%-1s%.2f\n", "Semester : ", ptr[user_input-1].sem,"SGPA : ",Sgpa);
    printf("%-10s%d\t\t\t\t\t%-1s%c\n","Roll No. : ",ptr[user_input-1].roll,"Grade : ",grade);
    printf("%-15s%d\n","Contact No. : ",ptr[user_input-1].contact);
    
    printf("--------------------------------------------------------------------\n");

    printf("%-20s\t%-8s\t%-8s\t%-8s\n","Subject","ISA1","ISA2","ESA");
    printf("--------------------------------------------------------------------\n");
    
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            printf("%-21s\t","Statistics");
        }
        else if (i == 1)
        {
            printf("%-21s\t","Problem Solving With C");
        }
        else
        {
            printf("%-21s\t","DSA");
        }
        printf("%-8d\t%-8d\t%-8d\n",ptr[i].isa1,ptr[i].isa2,ptr[i].esa);
    }
    printf("====================================================================\n");
}

