#include <stdio.h>
#include <stdlib.h>

#define MAX_PATIENTS 100

int main()
{
    int id,choice,loginAgain;
    char userName[50];
    char date[20];
    char time[20];
    int emergencyLevel[MAX_PATIENTS],
        specialtyId[MAX_PATIENTS],wardId[MAX_PATIENTS];
    char patientName[MAX_PATIENTS][100];
    int age[MAX_PATIENTS];
    int patientCount = 0;

    int currentQueue;
    int estimatedWaitingTime;

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

                //Patient Details

                printf("Patient Name: ");
                scanf(" %[^\n]", patientName);
                printf("Patient Age: ");
                scanf("%d", &age);

                if(age <= 0 || age > 120)
                {
                    printf("Invalid age!\n");
                    break;
                }

                //Emergency level selection
                printf("Emergency Choice\n");

                for (int i = 0; i < 3; i++)
                {
                    printf("%d. %s\n", i + 1, emergencyChoice[i]);
                }
                printf("Emergency level: ");
                scanf("%d", &emergencyLevel);

                if(emergencyLevel < 1 || emergencyLevel > 3)
                {
                    printf("Invalid choice!\n");
                    break;
                }


                //Specialty Selection
                printf("Specialty Selection\n");

                for (int i = 0; i < 4; i++)
                {
                    printf("%d. %s\n", i + 1, specialty[i]);
                }
                printf("Specialty ID: ");
                scanf("%d", &specialtyId);

                if(specialtyId < 1 || specialtyId > 4)
                {
                    printf("Invalid choice!\n");
                    break;
                }

                //Ward Admission Details
                int admissionChoice, daysAdmitted;

                printf("Is Admitted to Ward?\n");
                printf("1=Yes\n");
                printf("0=No\n");
                printf("Ward admission choice: ");
                scanf("%d",&admissionChoice);

                if(admissionChoice==1)
                {
                    printf("Ward selection\n");

                    for (int i = 0; i < 4; i++)
                    {
                        printf("%d. %s\n", i + 1, ward[i]);
                    }
                    printf("Ward ID: ");
                    scanf("%d", &wardId);

                    if(wardId < 1 || wardId > 4)
                    {
                    printf("Invalid choice!\n");
                    break;
                    }

                    printf("Days Admitted: ");
                    scanf("%d", &daysAdmitted);

                    if(daysAdmitted <= 0)
                    {
                    printf("Invalid number of days!\n");
                    break;
                    }
                }
                else if(admissionChoice==0)
                {
                    daysAdmitted = 0;
                    printf("Days Admitted: %d\n",daysAdmitted);
                }
                else
                {
                    printf("Invalid choice!\n");
                    break;
                }

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
                printf("4.Billing\n");
                break;
            }
           case 5:
            {
                printf("5.Reports and Data management\n");
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

