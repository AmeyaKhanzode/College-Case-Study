#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int pop;
    printf("Enter number of students: ");
    scanf("%d", &pop);

    student *students = malloc(pop * sizeof(student));
    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;
    do
    {
        printf("\nFollowing are the options. Please select one:\n");
        printf("1 - Enter student data\n");
        printf("2 - Enter marks\n");
        printf("3 - Generate grade card\n");
        printf("4 - Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            student_data(students, pop);
            updateToFile(students, pop);
            break;
        
        case 2:
            marks(students, pop);
            updateToFile(students, pop);
            break;
        
        case 3:
            readFromFile(students, pop);
            card(students, pop);
            break;
        
        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice. Please select a number between 1 and 4.\n");
            break;
        }
    } while (choice != 4);

    free(students);
    return 0;
}
