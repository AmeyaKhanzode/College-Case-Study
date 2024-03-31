#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern const int pop;
extern char names[][50];
extern int sems[];
extern int roll[];
extern long int contact[];
extern int isa1[][3];
extern int isa2[][3];
extern int esa[][3];

void subdet(char subs[3][40], int credits[3]);
void marks(int isa1[][3], int isa2[][3], int esa[][3]);
void student(int pop, char names[][50],int sems[],int roll[],long int contact[]);
float gp(float temp[], int n);
float sgpa(int k,int isa1[][3], int isa2[][3], int esa[][3]);
void card(char names[][50],int sems[],int isa1[][3],int isa2[][3],int esa[][3],long int contact[],int roll[]);


#endif
