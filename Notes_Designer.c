/************************************************************************************
**  File_Name :  Notes_Designer.c                                                  **
**  Title     :  Notes Desinger                                                    **
**  Version: 1.0.2                                                                 **
**  Author : Ahmed Nageeb                                                          **
************************************************************************************/
/*----------Including-section-----------*/
#include <stdio.h>
/*--------------------------------------*/

/*-------------Variable-Section---------*/
int Start_Number;
int End_Number;
char Exit_Value;
/*--------------------------------------*/

/*---------Main-Fun-section-------------*/
int main()
{
    while (1)
    {
        //--------------------Scan Start Number----------------------
        printf("PLease Enter Start Number:"); // Taking Start Number.
        scanf("%i", &Start_Number);           // Taking Start Number.
        //------------------------------------------------------------
        //--------------------Scan End Number-------------------------
        printf("PLease Enter End Number:"); // Taking End Number.
        scanf("%i", &End_Number);           // Taking End Number.
        //------------------------------------------------------------
        if (Start_Number < 0 || End_Number < 0 || Start_Number > End_Number) // Check Negative Function.
        {
            printf("Invalid Numbers !! \nPlease, Enter valid Values!?\n----------------------------\n"); // Print Invalid Message.
        }
        else // ENtering the Program.
        {
            End_Number++;
            for (Start_Number; Start_Number <= End_Number; Start_Number++) // Design Loop.
            {
                printf("--------------------------------------------------------------------------------\n"); // Initial Line repeatable.
                if (Start_Number == End_Number)
                {
                    break;
                }
                printf("%i-\n", Start_Number);
            }

            printf("Thank you for Using Our Program :)\n"); // Thanking Message.
            printf("--------------------------------------\n");
            printf("Write any number to Exit if not Write 1 !!\n"); // Exit Request
            scanf("%i", &Exit_Value);                               // Exit scan
            if (1 == Exit_Value)                                    // Exit Condition
            {
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}
/*--------------------------------------*/