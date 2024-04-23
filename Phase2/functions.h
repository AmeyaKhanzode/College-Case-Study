#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern const int pop;
typedef struct student
{
    char name[100];
    int sem;
    int roll;
    long long int contact;
    int isa1[3];
    int isa2[3];
    int esa[3];
    float sgpa;
} student;



extern student all_students[];
void student_data(struct student *ptr, int pop);
void marks(struct student *ptr, int pop);
float gp(float temp[], int n);
void sgpa(int k,struct student *ptr);
void card(struct student *ptr, int pop);

#endif