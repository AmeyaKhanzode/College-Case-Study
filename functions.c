#include <stdio.h>

//file contains all the functioncs to be used.

void subject(char subs[3][40], int credits[3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter subject %d name : ",i+1);
        scanf("%s",&subs[i]);
        
        printf("Enter credit of subject %d : ",i+1);
        scanf("%s",&credits[i]);
    }
}

void marks(int isa1[][3], int isa2[][3], int esa[][3]) 
{
    for (int i = 0; i < 10; i++) {      
        printf("=========================Marks of Student %d=========================\n",i+1);
        printf("\n");
        printf("Enter Statistics (3 credits) Marks (ISA1 ISA2 ESA) : ");
        scanf("%d %d %d", &isa1[i][0], &isa2[i][0], &esa[i][0]);
    
        printf("Enter C (5 credits) Marks (ISA1 ISA2 ESA) : ");
        scanf("%d %d %d", &isa1[i][1], &isa2[i][1], &esa[i][1]);
    
        printf("Enter DSA (4 credits) Marks (ISA1 ISA2 ESA) : ");
        scanf("%d %d %d", &isa1[i][2], &isa2[i][2], &esa[i][2]);
        printf("\n");
    }
}

void student(int pop, char names[][50],int sems[],int roll[],long int contact[])
{
    for (int i = 0; i < pop; i++)       
        {
            printf("========== Data of Student %d ==========\n",i+1);
            printf("Enter name : ");
            scanf("%s",&names[i]);

            printf("Enter sem number : ");
            scanf("%d",&sems[i]);

            printf("Enter roll : ");
            scanf("%d",&roll[i]);

            printf("Enter contact : ");
            scanf("%li",&contact[i]);
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

float sgpa(int k,int isa1[][3], int isa2[][3], int esa[][3])
{
    float score1 = 0,score2 = 0,score3 = 0;
    score1 += (isa1[k][0] + isa2[k][0] + esa[k][0])/2 + 10;
    score2 += (isa1[k][1] + isa2[k][1] + esa[k][1])/2 + 10;
    score3 += (isa1[k][2] + isa2[k][2] + esa[k][2])/2 + 10;

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
    return sgpa;
}

void card(char names[][50],int sems[],int isa1[][3],int isa2[][3],int esa[][3],long int contact[],int roll[])
{
    printf("Student Names:\n");
    for (int i = 0; i < 10; i++)  
    {
        printf("%d. %s\n",i+1,names[i]);
    }  

    int user_input;
    char grade;
    
    printf("Choose which student's grade card to be printed : ");
    scanf("%d",&user_input);

    float Sgpa = sgpa(user_input-1,isa1,isa2,esa);

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
    printf("%-5s%s\n","Name : ",names[user_input-1]);

    printf("%-5s%d\t\t\t\t\t%-1s%.2f\n", "Semester : ", sems[user_input-1],"SGPA : ",Sgpa);
    printf("%-10s%d\t\t\t\t\t%-1s%c\n","Roll No. : ",roll[user_input-1],"Grade : ",grade);
    printf("%-15s%d\n","Contact No. : ",contact[user_input-1]);
    
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
        printf("%-8d\t%-8d\t%-8d\n",isa1[user_input-1][i],isa2[user_input-1][i],esa[user_input-1][i]);
    }
    printf("====================================================================\n");
}