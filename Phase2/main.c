#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

const int pop = 3;

int main()
{

    all_students[pop];
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
                student_data(all_students, pop);
                break;
            case 2:
                marks(all_students, pop);
                break;
            case 3:
                 card(all_students, pop);
                break;
            case 4:
                for (int i = 0;  i < pop; i++)
                    {
                        free(all_students[i].name);
                    }
                return 1;
        }
    } while (user_input != 4); //breaks out when user wants to exit
}