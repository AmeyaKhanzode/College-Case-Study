#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct student
{
    char name[50];
    int sem;
    int roll;
    long long contact;
    int isa1[3];
    int isa2[3];
    int esa[3];
    float sgpa;
} student;

void student_data(student *ptr, int pop);
void marks(student *ptr, int pop);
void card(student *ptr, int pop);
void updateToFile(student *ptr, int pop);
void readFromFile(student *ptr, int pop);

#endif
