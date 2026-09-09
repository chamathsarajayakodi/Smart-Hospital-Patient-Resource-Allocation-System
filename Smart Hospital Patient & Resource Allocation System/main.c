#include <stdio.h>
#include <stdlib.h>

int main()
{
    int id,choice,loginAgain;
    char userName[50];
    char date[20];
    char time[20];
    int emergencyLevel,specialtyId,wardId;
    char patientName[100];
    int age;

    //Emergency level
    char emergencyChoice [3][10]=
    {
        "Normal",
        "Urgent",
        "Critical"
    };

    //Specialty
    char specialty [4][30]=
    {
        "General Practice (OPD)",
        "Paediatrics",
        "Cardiology",
        "Neurology"
    };

    //Ward Admission
    char ward [4][30]=
    {
        "General Ward",
        "Pediatric Ward",
        "Surgical Ward",
        "ICU (Intensive Care Unit)"
    };

    //User login
    do
    {
       printf("User login\n");
       printf("User name: ");
       scanf(" %[^\n]", userName);
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
           printf("2.Doctor channeling\n");
           printf("3.Hospital wards and Bed allocation\n");
           printf("4.Triage priority queue\n");
           printf("5.Billing\n");
           printf("6.Reports and Data management\n");
           printf("7.Exit\n");
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
                printf("2.Doctor channeling\n");

                for (int i = 0; i < 4; i++)
                {
                    printf("%d. %s\n", i + 1, specialty[i]);
                }
                printf("Specialty ID: ");
                scanf("%d", &specialtyId);
                {
                    int case2Choice;
                    do
                    {
                        printf("1.Current queue\n");
                        printf("2.Consultation time\n");
                        printf("3.Estimated waiting time\n");
                        printf("4.Daily capacity\n");
                        printf("5.Back\n");
                        printf("Enter your choice : ");
                        scanf("%d", &case2Choice);

                        switch(case2Choice)
                        {
                        case 1:
                            {
                                printf("1.Current queue\n");
                            }
                        case 2:
                            {
                                printf("2.Consultation time\n");
                            }
                        case 3:
                            {
                                printf("3.Estimated waiting time\n");
                            }
                        case 4:
                            {
                                printf("4.Daily capacity\n");
                            }
                        case 5:
                            {
                                printf("5.Back\n");
                            }
                        default:
                            printf("\nInvalid choice! Please try again.\n");

                        }while(choice != 5);

                    }
                }

                break;
            }
           case 3:
            {
                printf("3.Hospital wards and Bed allocation\n");
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
                printf("6.Reports and Data management\n");
            }
           case 7:
            {
                printf("7.Exit\n");
                break;
            }
           default:
                printf("\nInvalid choice! Please try again.\n");
           }
       }while(choice != 7);

       //Login again
       do
       {
            printf("\nDo you want to login again?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Enter your choice: ");
            scanf("%d", &loginAgain);

            if(loginAgain != 1 && loginAgain != 2)
            {
                printf("Invalid choice! Please enter 1 or 2.\n");
            }

       }while(loginAgain != 1 && loginAgain != 2);

    }while(loginAgain == 1);

    //End
    printf("\nThank you for using the Smart Hospital System!\n");

    return 0;
}

