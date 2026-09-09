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

    int admissionChoice[MAX_PATIENTS];
    int daysAdmitted[MAX_PATIENTS];

    int patientCount = 0;

    int currentQueue[4] = {0, 0, 0, 0};
    int estimatedWaitingTime;

    int bedNumber[MAX_PATIENTS] = {0};
    char allocationDate[MAX_PATIENTS][20];
    char cancellationDate[MAX_PATIENTS][20];
    int bedOccupancy[4][20] = {0};


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

                int case3Choice;

                do
                {
                    printf("1.Bed matrix\n");
                    printf("2.Bed allocation\n");
                    printf("3.Back\n");
                    printf("Enter your choice : ");
                    scanf("%d", &case3Choice);

                    switch(case3Choice)
                    {
                    case 1:
                        {
                            printf("\nBed Occupancy Matrix\n");
                            printf("0 = Available   1 = Occupied   X = Not Available\n\n");

                            printf("                  ");

                            for(int j = 0; j < 20; j++)
                            {
                                printf("%2d ", j + 1);
                            }

                            printf("\n");

                            for(int i = 0; i < 4; i++)
                            {
                                printf("%-16s ", ward[i]);

                                for(int j = 0; j < 20; j++)
                                {
                                    if(j < totalBedCapacity[i])
                                    {
                                        printf("%2d ", bedOccupancy[i][j]);
                                    }
                                    else
                                    {
                                        printf(" X ");
                                    }
                                }

                                printf("\n");
                            }
                            break;
                        }
                    case 2:
                        {
                            printf("2.Bed allocation\n");

                            int case3wardId;
                            for (int i = 0; i < 4; i++)
                            {
                                printf("%d. %s\n", i + 1, ward[i]);
                            }
                            printf("Ward ID: ");
                            scanf("%d", &case3wardId);

                            if(case3wardId < 1 || case3wardId > 4)
                            {
                                printf("Invalid choice!\n");
                                break;
                            }
                            printf("Selected Ward: %s\n", ward[case3wardId - 1]);

                            int case32Choice;
                            do
                            {
                                printf("1.To be allocated\n");
                                printf("2.Already allocated\n");
                                printf("3.Cancel bed allocation\n");
                                printf("4.Back\n");
                                printf("Enter your choice : ");
                                scanf("%d", &case32Choice);

                                switch(case32Choice)
                                {
                                case 1:
                                    {
                                        printf("1.To be allocated\n");

                                        int toBeAllocatedCount = 0;
                                        int selectedPatient;

                                        for(int i = 0; i < patientCount; i++)
                                        {
                                            if(admissionChoice[i] == 1 &&
                                               wardId[i] == case3wardId &&
                                               bedNumber[i] == 0)
                                            {
                                                toBeAllocatedCount++;

                                                printf("%d. %s\n",
                                                       toBeAllocatedCount,
                                                       patientName[i]);
                                            }
                                        }

                                        if(toBeAllocatedCount == 0)
                                        {
                                            printf("No patients to be allocated.\n");
                                            break;
                                        }

                                        printf("Select patient: ");
                                        scanf("%d", &selectedPatient);

                                        if(selectedPatient < 1 ||
                                           selectedPatient > toBeAllocatedCount)
                                        {
                                            printf("Invalid patient choice!\n");
                                            break;
                                        }

                                        int patientIndex = -1;
                                        int patientPosition = 0;

                                        for(int i = 0; i < patientCount; i++)
                                        {
                                            if(admissionChoice[i] == 1 &&
                                               wardId[i] == case3wardId &&
                                               bedNumber[i] == 0)
                                            {
                                                patientPosition++;

                                                if(patientPosition == selectedPatient)
                                                {
                                                    patientIndex = i;
                                                    break;
                                                }
                                            }
                                        }

                                        printf("\nSelected Patient: %s\n",
                                               patientName[patientIndex]);

                                        printf("\nAvailable Beds:\n");

                                        int availableBedCount = 0;

                                        for(int i = 0; i < totalBedCapacity[case3wardId - 1]; i++)
                                        {
                                            if(bedOccupancy[case3wardId - 1][i] == 0)
                                            {
                                                availableBedCount++;

                                                printf("Bed %d\n", i + 1);
                                            }
                                        }

                                        if(availableBedCount == 0)
                                        {
                                            printf("No beds available in this ward.\n");
                                            break;
                                        }

                                        int selectedBed;

                                        printf("Enter bed number: ");
                                        scanf("%d", &selectedBed);

                                        if(selectedBed < 1 ||
                                           selectedBed > totalBedCapacity[case3wardId - 1])
                                        {
                                            printf("Invalid bed number!\n");
                                            break;
                                        }

                                        if(bedOccupancy[case3wardId - 1][selectedBed - 1] == 1)
                                        {
                                            printf("This bed is already occupied!\n");
                                            break;
                                        }

                                        bedOccupancy[case3wardId - 1][selectedBed - 1] = 1;

                                        bedNumber[patientIndex] = selectedBed;
                                        printf("Allocation date (DD/MM/YYYY): ");
                                        scanf("%s", allocationDate[patientIndex]);

                                        printf("\nBed allocated successfully!\n");
                                        break;
                                    }
                                case 2:
                                    {
                                        printf("2.Already allocated\n");

                                        int alreadyAllocatedCount = 0;

                                        for(int i = 0; i < patientCount; i++)
                                        {
                                            if(admissionChoice[i] == 1 &&
                                               wardId[i] == case3wardId &&
                                               bedNumber[i] != 0)
                                            {
                                                alreadyAllocatedCount++;

                                                printf("%d. %s - Bed %d\n",
                                                       alreadyAllocatedCount,
                                                       patientName[i],
                                                       bedNumber[i]);
                                            }
                                        }

                                        if(alreadyAllocatedCount == 0)
                                        {
                                            printf("No patients are currently allocated to a bed.\n");
                                        }

                                        break;
                                    }
                                case 3:
                                    {
                                        printf("3.Cancel bed allocation\n");

                                        int allocatedPatientCount = 0;

                                        for(int i = 0; i < patientCount; i++)
                                        {
                                            if(admissionChoice[i] == 1 &&
                                               wardId[i] == case3wardId &&
                                               bedNumber[i] != 0)
                                            {
                                                allocatedPatientCount++;

                                                printf("%d. %s - Bed %d\n",
                                                       allocatedPatientCount,
                                                       patientName[i],
                                                       bedNumber[i]);
                                            }
                                        }

                                        if(allocatedPatientCount == 0)
                                        {
                                            printf("No patients are currently allocated.\n");
                                            break;
                                        }

                                        int selectedPatient;

                                        printf("Select patient: ");
                                        scanf("%d", &selectedPatient);

                                        if(selectedPatient < 1 ||
                                           selectedPatient > allocatedPatientCount)
                                        {
                                            printf("Invalid patient choice!\n");
                                            break;
                                        }

                                        int patientIndex = -1;
                                        int patientPosition = 0;

                                        for(int i = 0; i < patientCount; i++)
                                        {
                                            if(admissionChoice[i] == 1 &&
                                               wardId[i] == case3wardId &&
                                               bedNumber[i] != 0)
                                            {
                                                patientPosition++;

                                                if(patientPosition == selectedPatient)
                                                {
                                                    patientIndex = i;
                                                    break;
                                                }
                                            }
                                        }

                                        printf("\nPatient: %s\n", patientName[patientIndex]);
                                        printf("Bed Number: %d\n", bedNumber[patientIndex]);
                                        printf("Allocation Date: %s\n", allocationDate[patientIndex]);

                                        printf("Cancellation date (DD/MM/YYYY): ");
                                        scanf("%s", cancellationDate[patientIndex]);

                                        printf("\nBed allocation cancelled successfully!\n");

                                        bedOccupancy[case3wardId - 1][bedNumber[patientIndex] - 1] = 0;

                                        bedNumber[patientIndex] = 0;
                                        break;
                                    }
                                case 4:
                                    {
                                        printf("4.Back\n");
                                        break;
                                    }
                                default:
                                    printf("\nInvalid choice! Please try again.\n");
                                }

                            }while(case32Choice != 4);

                            break;
                        }
                    case 3:
                        {
                            printf("3.Back\n");
                            break;
                        }
                    default:
                        printf("\nInvalid choice! Please try again.\n");
                    }

                }while (case3Choice != 3);

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

