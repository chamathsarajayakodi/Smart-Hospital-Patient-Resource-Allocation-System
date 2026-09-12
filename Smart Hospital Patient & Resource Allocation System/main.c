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

                int reportChoice;

                while(1)
                {
                    printf("1. Patient Summary by Emergency Level\n");
                    printf("2. Revenue & Discount Report\n");
                    printf("3. Ward Bed Occupancy Report\n");
                    printf("4. Highest-Paying Patient\n");
                    printf("5. Back\n");

                    printf("\nEnter your choice: ");
                    scanf("%d", &reportChoice);

                    switch(reportChoice)
                    {
                        case 1:
                        {
                            int normalCount = 0;
                            int urgentCount = 0;
                            int criticalCount = 0;

                            for(int i = 0; i < patientCount; i++)
                            {
                                if(emergencyLevel[i] == 1)
                                {
                                    normalCount++;
                                }
                                else if(emergencyLevel[i] == 2)
                                {
                                    urgentCount++;
                                }
                                else
                                {
                                    criticalCount++;
                                }
                            }

                            printf("\nPatient Summary by Emergency Level\n\n");

                            printf("%s   : %d patients\n",
                                   emergencyChoice[0],
                                   normalCount);

                            printf("%s   : %d patients\n",
                                   emergencyChoice[1],
                                   urgentCount);

                            printf("%s : %d patients\n",
                                   emergencyChoice[2],
                                   criticalCount);

                            break;
                        }

                        case 2:
                        {
                            float totalRevenue = 0;
                            float totalDiscount = 0;

                            for(int i = 0; i < patientCount; i++)
                            {
                                float baseFee;
                                float emergencySurcharge;
                                float wardCost = 0;
                                float grossTotal;
                                float discount;
                                float finalPayable;

                                baseFee = consultationFee[specialtyId[i] - 1];

                                emergencySurcharge =
                                    calculateEmergencySurcharge(
                                        baseFee,
                                        emergencyLevel[i]
                                    );

                                if(admissionChoice[i] == 1)
                                {
                                    wardCost =
                                        calculateWardCost(
                                            daysAdmitted[i],
                                            dailyBedRate[wardId[i] - 1]
                                        );
                                }

                                grossTotal =
                                    calculateGrossTotal(
                                        baseFee,
                                        emergencySurcharge,
                                        wardCost
                                    );

                                discount =
                                    calculateAgeSubsidy(
                                        grossTotal,
                                        age[i]
                                    );

                                finalPayable =
                                    calculateFinalPayable(
                                        grossTotal,
                                        discount
                                    );

                                totalRevenue += finalPayable;
                                totalDiscount += discount;
                            }

                            printf("\nRevenue & Discount Report\n\n");

                            printf("Total Revenue   : LKR %.2f\n",
                                   totalRevenue);

                            printf("Total Discounts : LKR %.2f\n",
                                   totalDiscount);

                            break;
                        }

                        case 3:
                        {
                            printf("\nWard Bed Occupancy Report\n\n");

                            for(int i = 0; i < 4; i++)
                            {
                                int occupiedBeds = 0;
                                int availableBeds;

                                for(int j = 0; j < totalBedCapacity[i]; j++)
                                {
                                    if(bedOccupancy[i][j] == 1)
                                    {
                                        occupiedBeds++;
                                    }
                                }

                                availableBeds =
                                    totalBedCapacity[i] - occupiedBeds;

                                printf("%s\n", ward[i]);
                                printf("Total Beds     : %d\n",
                                       totalBedCapacity[i]);

                                printf("Occupied Beds  : %d\n",
                                       occupiedBeds);

                                printf("Available Beds : %d\n\n",
                                       availableBeds);
                            }

                            break;
                        }

                        case 4:
                        {
                            int highestPatient = 0;
                            float highestPayable = 0;

                            for(int i = 0; i < patientCount; i++)
                            {
                                float baseFee;
                                float emergencySurcharge;
                                float wardCost = 0;
                                float grossTotal;
                                float discount;
                                float finalPayable;

                                baseFee =
                                    consultationFee[specialtyId[i] - 1];

                                emergencySurcharge =
                                    calculateEmergencySurcharge(
                                        baseFee,
                                        emergencyLevel[i]
                                    );

                                if(admissionChoice[i] == 1)
                                {
                                    wardCost =
                                        calculateWardCost(
                                            daysAdmitted[i],
                                            dailyBedRate[wardId[i] - 1]
                                        );
                                }

                                grossTotal =
                                    calculateGrossTotal(
                                        baseFee,
                                        emergencySurcharge,
                                        wardCost
                                    );

                                discount =
                                    calculateAgeSubsidy(
                                        grossTotal,
                                        age[i]
                                    );

                                finalPayable =
                                    calculateFinalPayable(
                                        grossTotal,
                                        discount
                                    );

                                if(i == 0 || finalPayable > highestPayable)
                                {
                                    highestPayable = finalPayable;
                                    highestPatient = i;
                                }
                            }

                            printf("\nHighest-Paying Patient\n\n");

                            printf("Patient Name  : %s\n",
                                   patientName[highestPatient]);

                            printf("Patient ID    : PAT-%04d\n",
                                   1001 + highestPatient);

                            printf("Final Payable : LKR %.2f\n",
                                   highestPayable);

                            break;
                        }

                        case 5:
                        {
                            break;
                        }

                        default:
                        {
                            printf("Invalid choice!\n");
                        }
                    }

                    if(reportChoice == 5)
                    {
                        break;
                    }
                }

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

