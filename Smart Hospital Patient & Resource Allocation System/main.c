#include <stdio.h>
#include <stdlib.h>

#define MAX_PATIENTS 100

float calculateEmergencySurcharge(float baseFee, int emergencyLevel)

float calculateWardCost(int daysAdmitted, float dailyRate)

float calculateGrossTotal(float baseFee, float emergencySurcharge,
                          float wardCost)

float calculateAgeSubsidy(float grossTotal, int age)

float calculateFinalPayable(float grossTotal, float discount)

void generateBill(int i)

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

                int selectedPatient;
                int billingChoice;

                if(patientCount == 0)
                {
                    printf("\nNo registered patients available.\n");
                    break;
                }

                while(1)
                {
                    printf("\nRegistered Patients:\n");

                    for(int i = 0; i < patientCount; i++)
                    {
                        printf("%d. %s\n",
                               i + 1,
                               patientName[i]);
                    }

                    printf("\nSelect Patient: ");
                    scanf("%d", &selectedPatient);

                    if(selectedPatient < 1 || selectedPatient > patientCount)
                    {
                        printf("Invalid patient selection!\n");
                        continue;
                    }

                    printf("\nSelected Patient: %s\n",
                           patientName[selectedPatient - 1]);

                    while(1)
                    {
                        printf("\n1. Generate Bill\n");
                        printf("2. Select Another Patient\n");
                        printf("3. Back\n");

                        printf("\nEnter your choice: ");
                        scanf("%d", &billingChoice);

                        if(billingChoice == 1)
                        {
                            generateBill(selectedPatient - 1);
                        }
                        else if(billingChoice == 2)
                        {
                            break;
                        }
                        else if(billingChoice == 3)
                        {
                            break;
                        }
                        else
                        {
                            printf("Invalid choice!\n");
                        }
                    }

                    if(billingChoice == 3)
                    {
                        break;
                    }
                }

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

//Billing functions

// Emergency Surcharge
float calculateEmergencySurcharge(float baseFee, int emergencyLevel)
{
    if(emergencyLevel == 2)
    {
        return baseFee * 0.20;
    }
    else if(emergencyLevel == 3)
    {
        return baseFee * 0.50;
    }
    else
    {
        return 0;
    }
}


// Total Ward Stay Cost
float calculateWardCost(int daysAdmitted, float dailyRate)
{
    return daysAdmitted * dailyRate;
}


// Gross Total Bill
float calculateGrossTotal(float baseFee, float emergencySurcharge,
                          float wardCost)
{
    return baseFee + emergencySurcharge + wardCost;
}


// Age Subsidy Discount
float calculateAgeSubsidy(float grossTotal, int age)
{
    if(age < 5 || age > 65)
    {
        return grossTotal * 0.15;
    }
    else
    {
        return 0;
    }
}


// Final Amount Payable
float calculateFinalPayable(float grossTotal, float discount)
{
    return grossTotal - discount;
}

// Bill generation
void generateBill(int i)
{
    float baseFee;
    float emergencySurcharge;
    float wardCost = 0;
    float grossTotal;
    float discount;
    float finalPayable;

    // Get consultation fee
    baseFee = consultationFee[specialtyId[i] - 1];

    // Calculate emergency surcharge
    emergencySurcharge =
        calculateEmergencySurcharge(baseFee, emergencyLevel[i]);

    // Calculate ward cost only if patient is admitted
    if(admissionChoice[i] == 1)
    {
        wardCost =
            calculateWardCost(daysAdmitted[i],
                              dailyBedRate[wardId[i] - 1]);
    }

    // Calculate gross total
    grossTotal =
        calculateGrossTotal(baseFee,
                            emergencySurcharge,
                            wardCost);

    // Calculate age subsidy
    discount =
        calculateAgeSubsidy(grossTotal, age[i]);

    // Calculate final payable amount
    finalPayable =
        calculateFinalPayable(grossTotal, discount);


    // Display Bill

    printf("\nSMART HOSPITAL ADMISSION & BILL\n\n");

    printf("Patient ID          : PAT-%04d\n", 1001 + i);

    printf("Patient Name        : %s\n",
           patientName[i]);

    if(age[i] < 5 || age[i] > 65)
    {
        printf("Age                 : %d Years (15%% Subsidy Eligible)\n",
               age[i]);
    }
    else
    {
        printf("Age                 : %d Years\n",
               age[i]);
    }

    printf("Specialty           : %s\n",
           specialty[specialtyId[i] - 1]);


    if(admissionChoice[i] == 1)
    {
        printf("Assigned Ward       : %s",
               ward[wardId[i] - 1]);

        if(bedNumber[i] > 0)
        {
            printf(" (Bed #%02d)", bedNumber[i]);
        }

        printf("\n");
    }
    else
    {
        printf("Assigned Ward       : Outpatient (OPD)\n");
    }


    if(emergencyLevel[i] == 1)
    {
        printf("Urgency Level       : Level 1 (Normal)\n");
    }
    else if(emergencyLevel[i] == 2)
    {
        printf("Urgency Level       : Level 2 (Urgent)\n");
    }
    else
    {
        printf("Urgency Level       : Level 3 (Critical)\n");
    }


    printf("\n");

    printf("Base Consultation Fee : LKR %10.2f\n",
           baseFee);

    if(emergencyLevel[i] == 2)
    {
        printf("Emergency Surcharge   : LKR %10.2f (20%%)\n",
               emergencySurcharge);
    }
    else if(emergencyLevel[i] == 3)
    {
        printf("Emergency Surcharge   : LKR %10.2f (50%%)\n",
               emergencySurcharge);
    }
    else
    {
        printf("Emergency Surcharge   : LKR %10.2f (0%%)\n",
               emergencySurcharge);
    }

    printf("Ward Stay Cost (%d Days): LKR %10.2f\n",
           daysAdmitted[i],
           wardCost);

    printf("\n");

    printf("Gross Total Bill      : LKR %10.2f\n",
           grossTotal);

    printf("Age Subsidy Discount  : LKR -%9.2f\n",
           discount);

    printf("\n");

    printf("Final Payable Amount  : LKR %10.2f\n",
           finalPayable);

    printf("Estimated Waiting Time: %d mins\n",
           estimatedWaitingTime);
}

