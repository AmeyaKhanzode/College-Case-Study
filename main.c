#include <stdio.h>
#include "functions.h"

    const int pop;
    char names[10][50], subs[10][40]; int credits[10];         
    int sems[10],roll[10],isa1[10][3],isa2[10][3],esa[10][3];    
    long int contact[10];                                    

int main()
{
    
    const int pop = 10;

    int user_input;
    do
    {
    
        printf("\nFollowing are the options. Please click any of the following numbers.\n");
        printf("1 - Enter Student Information \n2 - Enter Marks \n3 - Grade Card\n4 - Exit\n\n");

        printf("Enter choice : ");
        scanf("%d",&user_input);
        printf("\n");

        switch(user_input)
        {
            case 1:
                student(pop,names,sems,roll,contact);   //to enter the student's data
                break;
            case 2:
                marks(isa1,isa2,esa);   //to enter the student's marks
                break;
            case 3:
                card(names,sems,isa1,isa2,esa,contact,roll);    //to print the grade card
                break;
            case 4:
                return 1;
        }
    } while (user_input != 4); //breaks out when user wants to exit
}