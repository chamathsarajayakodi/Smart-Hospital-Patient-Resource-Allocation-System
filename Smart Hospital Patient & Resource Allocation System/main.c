#include <stdio.h>
#include <stdlib.h>

int main()
{
    int id,choice,loginAgain;
    char name[50];
    char date[20];
    char time[20];

    //User login
    do
    {
       printf("User login\n");
       printf("User name: ");
       scanf(" %[^\n]", name);
       printf("Employee ID: ");
       scanf("%d", &id);
       printf("Date (DD/MM/YYYY): ");
       scanf("%s", date);
       printf("Time (HH:MM): ");
       scanf("%s", time);

       //Main menu
       do
       {
           printf("\nMain menu\n");
           printf("1.New patient registration\n");
           printf("2.Doctor chanelling\n");
           printf("3.Hospital wards\n");
           printf("4.Triage priority queue\n");
           printf("5.Billing\n");
           printf("6.Exit\n");
           printf("Enter your choice : ");
           scanf("%d", &choice);

           switch(choice)
           {
           case 1:
            {
                printf("1.New patient registration\n");
                break;
            }
           case 2:
            {
                printf("2.Doctor chanelling\n");
                break;
            }
           case 3:
            {
                printf("3.Hospital wards\n");
                break;
            }
           case 4:
            {
                printf("4.Triage priority queue\n");
                break;
            }
           case 5:
            {
                printf("5.Billing\n");
                break;
            }
           case 6:
            {
                printf("6.Exit\n");
                break;
            }
           default:
                printf("\nInvalid choice! Please try again.\n");
           }
       }while(choice != 6);

       //Login again
       printf("\nDo you want to login again?\n");
       printf("1. Yes\n");
       printf("2. No\n");
       printf("Enter your choice: ");
       scanf("%d", &loginAgain);

    }while(loginAgain == 1);

    //End
    printf("\nThank you for using the Smart Hospital System!\n");

    return 0;
}

