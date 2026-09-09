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
    const char specialty [4][30]=
    {
        "General Practice (OPD)",
        "Paediatrics",
        "Cardiology",
        "Neurology"
    };

    //Consultation Fee
    const float consultationFee[4] =
    {
        1500.00,
        2500.00,
        4500.00,
        5000.00
    };

    //Consultation Time
    const int consultationTime[4] =
    {
        15,
        20,
        30,
        30
    };

    //Patient Lookup Capacity
    const int dailyCapacity[4] =
    {
        30,
        20,
        12,
        10
    };

    //Ward Admission
    const char ward [4][30]=
    {
        "General Ward",
        "Pediatric Ward",
        "Surgical Ward",
        "ICU (Intensive Care Unit)"
    };

    //Daily Bed Rate
    const float dailyBedRate[4] =
    {
        3000.00,
        6000.00,
        12000.00,
        25000.00
    };

    //Total Bed Capacity
    const int totalBedCapacity[4] =
    {
        20,
        10,
        10,
        5
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
           printf("4.Billing\n");
           printf("5.Reports and Data management\n");
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
                printf("2.Doctor channeling\n");
                break;
            }
           case 3:
            {
                printf("3.Hospital wards and Bed allocation\n");
                break;
            }

           case 4:
            {
                printf("5.Billing\n");
                break;
            }
           case 5:
            {
                printf("6.Reports and Data management\n");
                break;
            }
           case 6:
            {
                printf("7.Exit\n");
                break;
            }
           default:
                printf("\nInvalid choice! Please try again.\n");
           }
       }while(choice != 6);

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

